#ifndef OMAHKU_DIGITALOUTPUT
#define OMAHKU_DIGITALOUTPUT

#include <Arduino.h>

#define MAX_AMOUNT_OF_INSTANCES 100
#define MAX_AMOUNT_OF_INPUT_PINS 8
#define MAX_AMOUNT_OF_ALL_OUT_INPUT_PINS 8

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
        uint8_t _allOutPinCount;
        uint8_t _allOutPins[MAX_AMOUNT_OF_ALL_OUT_INPUT_PINS];

        void handle();
    public:
        DigitalOutput(uint8_t outputPin);
        ~DigitalOutput();

        static void loop();

        DigitalOutput* addInput(uint8_t inputPin);
        DigitalOutput* addInputs(uint8_t inputPin[], uint8_t size);
        DigitalOutput* addAllOutInput(uint8_t inputPin);
        DigitalOutput* addAllOutInputs(uint8_t inputPin[], uint8_t size);

        void setState(bool state);
        bool getState();
    };
}

#endif