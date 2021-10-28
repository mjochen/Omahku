#ifndef OMAHKU_DIGITALOUTPUT
#define OMAHKU_DIGITALOUTPUT

#include <Arduino.h>
#include "constants.h"

namespace Omahku
{
    class DigitalOutput
    {
    protected:
        // Support a maximum of MAX_AMOUNT_OF_INSTANCES outputs.
        static uint8_t _instanceCount;
        static DigitalOutput* _instances[MAX_AMOUNT_OF_INSTANCES];

        // Output pin and state.
        uint8_t _outputPin;
        bool _state;

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
        DigitalOutput(uint8_t outputPin);
        ~DigitalOutput();

        static void loop();

        DigitalOutput* addInput(uint8_t inputPin);
        DigitalOutput* addInputs(uint8_t inputPin[], uint8_t size);
        DigitalOutput* addAllOffInput(uint8_t inputPin);
        DigitalOutput* addAllOffInputs(uint8_t inputPin[], uint8_t size);

        void setState();
        void setState(bool state);
        bool getState();

        void setTimeDelay(unsigned long msec);
        void setTimeDelay(int hours, int minutes, int seconds);
    };
}

#endif