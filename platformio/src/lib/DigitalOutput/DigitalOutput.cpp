/**
 * @file DigitalOutput.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief This is the implementation for a digital output.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DigitalOutput.h"

using namespace Omahku;

uint8_t DigitalOutput::_instanceCount = 0;
DigitalOutput *DigitalOutput::_instances[MAX_AMOUNT_OF_INSTANCES] = {};
MQTT *DigitalOutput::_mqttInstance = nullptr;

DigitalOutput::DigitalOutput(uint8_t outputPin, const char *outputName)
{
    // If there is no output name set, give it
    // the value of the output pin number.
    if (outputName == nullptr) itoa(outputPin, _outputName, 10);
    else strncpy(_outputName, outputName, 40);

    sprintf(_topicName, "%s/%s/%s", CUSTOM_HOST_NAME, "/output/", _outputName);

    // Initialize the pin as an output.
    pinMode(outputPin, OUTPUT);

    // Set the class instance parameters.
    _state = false;
    _outputPin = outputPin;
    setState(false);
    
    // Setup the input pins.
    _inputPinCount = 0;
    _inputPins[MAX_AMOUNT_OF_INPUT_PINS] = {};
    _allOffPinCount = 0;
    _allOffPins[MAX_AMOUNT_OF_ALL_OFF_INPUT_PINS] = {};

    // Set the time to 0 and disable the function.
    _timeDelay = 0;
    _timeDelayFunction = false;

    // Perform some clever pointer assignment so
    // that we don't have to manually call handle()
    // for every instance.
    _instances[_instanceCount] = this;
    _instanceCount++;
}

DigitalOutput::~DigitalOutput() = default;

DigitalOutput* DigitalOutput::addInput(uint8_t inputPin)
{
    // Set the input pin, as an input pin, obviously.
    pinMode(inputPin, INPUT_PULLUP);

    // Add the input pin to the array.
    _inputPins[_inputPinCount] = inputPin;
    _inputPinCount++;

    return this;
}

DigitalOutput* DigitalOutput::addInputs(uint8_t inputPin[], uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        // Set the input pin, as an input pin, obviously.
        pinMode(inputPin[i], INPUT_PULLUP);

        // Add the input pin to the array.
        _inputPins[_inputPinCount] = inputPin[i];
        _inputPinCount++;
    }

    return this;
}

DigitalOutput* DigitalOutput::addAllOffInput(uint8_t inputPin)
{
    // Set the input pin, as an input pin, obviously.
    pinMode(inputPin, INPUT_PULLUP);

    // Add the input pin to the array.
    _allOffPins[_allOffPinCount] = inputPin;
    _allOffPinCount++;

    return this;
}

DigitalOutput* DigitalOutput::addAllOffInputs(uint8_t inputPin[], uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        // Set the input pin, as an input pin, obviously.
        pinMode(inputPin[i], INPUT_PULLUP);

        // Add the input pin to the array.
        _allOffPins[_allOffPinCount] = inputPin[i];
        _allOffPinCount++;
    }

    return this;
}

void DigitalOutput::loop()
{
    // Loop over every instance and call it's handle() function.
    for (uint8_t i = 0; i < _instanceCount; i++)
    {
        _instances[i]->handle();
    }
}

// Set the MQTT instance globally for the DigitalOutput class.
void DigitalOutput::setMQTTInstance(MQTT* mqttInstance)
{
    _mqttInstance = mqttInstance;
}

void DigitalOutput::handle()
{
    // Loop over every input pin, and check it's state.
    for (size_t i = 0; i < _inputPinCount; i++)
    {
        // If the input pin is low (pull-up so pull low for active)
        // enter the if function, change the output state, write
        // the output state and then wait until the switch comes
        // high again (released), then we wait 200msec because of contact
        // rumbling happening (read Schmitt Trigger).
        // CHANGEME: PII and PQI should be implemented here for non-blocking usage.
        if (digitalRead(_inputPins[i]) == 0)
        {
            setState(!_state);

            if (_timeDelayFunction) _timeStampOn = millis();

            while (digitalRead(_inputPins[i]) == 0) {}
            delay(200);
        }
    }

    // Loop over all-out input pin, and check it's state.
    for (size_t i = 0; i < _allOffPinCount; i++)
    {
        if (digitalRead(_allOffPins[i]) == 0)
        {
            setState(false);
        }
    }

    // If the time delay function is enabled AND the
    // output is turned on, check if the time differential
    // has been exceeded yet. If it has, turn off the output.
    if (_timeDelayFunction && _state)
    {
        unsigned long timeDifferential = millis() - _timeStampOn;
        if (timeDifferential > _timeDelay)
        {
            setState(false);
        }
    }
}

void DigitalOutput::setState(bool state)
{
    // Set the output state.
    // True is on, false is off.
    _state = state;
    digitalWrite(_outputPin, !_state);

    // If MQTT is enabled, update the status in MQTT.
    if (_mqttInstance != nullptr)
    {
        _mqttInstance->client.publish(_topicName, _state ? "true" : "false");
    }
}

bool DigitalOutput::getState()
{
    // Get the output state.
    // True is on, false is off.
    return _state;
}

void DigitalOutput::setTimeDelay(unsigned long msec)
{
    // Turn on the time delay function.
    _timeDelayFunction = true;

    // Set the total time in msec that is needed.
    _timeDelay = msec;
}

void DigitalOutput::setTimeDelay(int hours, int minutes, int seconds)
{
    // Turn on the time delay function.
    _timeDelayFunction = true;

    // Calculate the total time in msec that is needed.
    _timeDelay = hours * HOURS + minutes * MINUTES + seconds * SECONDS;
}