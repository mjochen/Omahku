/**
 * @file DigitalOutput.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief This is the header file for a digital output.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef OMAHKU_DIGITALOUTPUT
#define OMAHKU_DIGITALOUTPUT

#include <Arduino.h>
#include "lib/MQTT/MQTT.h"
#include "constants.h"

#define MAX_OUTPUT_NAME_SIZE 30
#define MAX_TOPIC_SIZE 80

namespace Omahku
{
    class DigitalOutput
    {
    protected:
        // Support a maximum of MAX_AMOUNT_OF_INSTANCES outputs.
        static uint8_t _instanceCount;
        static DigitalOutput* _instances[MAX_AMOUNT_OF_INSTANCES];
        static MQTT* _mqttInstance;

        // Output name and topic for MQTT.
        char _outputName[MAX_OUTPUT_NAME_SIZE];
        char _topicName[MAX_TOPIC_SIZE];

        // Output pin and state.
        uint8_t _outputPin;
        bool _state;

        unsigned long _lastButtonPress;
        int16_t _buttonPressed;

        // Supporting a maximum of MAX_AMOUNT_OF_INPUT_PINS push button inputs per output pin.
        uint8_t _inputPinCount;
        uint8_t _inputPins[MAX_AMOUNT_OF_INPUT_PINS];

        // All-out input.
        uint8_t _allOffPinCount;
        uint8_t _allOffPins[MAX_AMOUNT_OF_ALL_OFF_INPUT_PINS];

        // Timer function
        // Turn the light off after a specified amount of time.
        unsigned long _timeStampOn;
        unsigned long _timeDelay;
        bool _timeDelayFunction;

        void handle();
    public:
        DigitalOutput(uint8_t outputPin) : DigitalOutput(outputPin, nullptr) {};
        DigitalOutput(uint8_t outputPin, const char *outputName);
        ~DigitalOutput();

        static void loop();
        static void setMQTTInstance(MQTT* mqttInstance);

        DigitalOutput* addInput(uint8_t inputPin);
        DigitalOutput* addInputs(uint8_t inputPin[], uint8_t size);
        DigitalOutput* addAllOffInput(uint8_t inputPin);
        DigitalOutput* addAllOffInputs(uint8_t inputPin[], uint8_t size);

        void setState(bool state);
        bool getState();

        void setTimeDelay(unsigned long msec);
        void setTimeDelay(int hours, int minutes, int seconds);
    };
}

#endif