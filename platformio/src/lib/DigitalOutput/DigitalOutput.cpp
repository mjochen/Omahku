#include "DigitalOutput.h"

using namespace Omahku;

uint8_t DigitalOutput::_instanceCount = 0;
DigitalOutput *DigitalOutput::_instances[MAX_AMOUNT_OF_INSTANCES] = {};

DigitalOutput::DigitalOutput(uint8_t outputPin)
{
    // Initialize the pin as an output.
    pinMode(outputPin, OUTPUT);

    // Set the class instance parameters.
    _state = false;
    _outputPin = outputPin;
    digitalWrite(outputPin, !_state);
    
    // Setup the input pins.
    _inputPinCount = 0;
    _inputPins[MAX_AMOUNT_OF_INPUT_PINS] = {};
    _allOutPin = 0;

    // Perform some clever pointer assignment so
    // that we don't have to manually call handle()
    // for every instance.
    _instances[_instanceCount] = this;
    _instanceCount++;
}

DigitalOutput::~DigitalOutput() = default;

void DigitalOutput::addInput(uint8_t inputPin)
{
    // Set the input pin, as an input pin, obviously.
    pinMode(inputPin, INPUT_PULLUP);

    // Add the input pin to the array.
    _inputPins[_inputPinCount] = inputPin;
    _inputPinCount++;
}

void DigitalOutput::addAllOutInput(uint8_t inputPin)
{
    // Set the input pin, as an input pin, obviously.
    pinMode(inputPin, INPUT_PULLUP);

    _allOutPin = inputPin;
}

void DigitalOutput::loop()
{
    // Loop over every instance and call it's handle() function.
    for (uint8_t i = 0; i < _instanceCount; i++)
    {
        _instances[i]->handle();
    }
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
            _state = !_state;
            digitalWrite(_outputPin, !_state);
            while (digitalRead(_inputPins[i]) == 0) {}
            delay(200);
        }
    }

    if (digitalRead(_allOutPin) == 0)
    {
        _state = false;
        digitalWrite(_outputPin, !_state);
    }
}

void DigitalOutput::setState(bool state)
{
    _state = state;
}

bool DigitalOutput::getState()
{
    return _state;
}
