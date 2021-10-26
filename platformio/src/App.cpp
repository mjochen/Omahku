#include "App.h"

using namespace Omahku;

App::App() = default;

App::~App() = default;


bool App::setup()
{
    // Startup serial.
    Serial.begin(115200);
    Serial.println(F("Starting up Omahku controller..."));

    Serial.println(F("[      ] Setting up module Eth..."));
    if (ethernetModule.setup())
    {
        Serial.println(F("[  OK  ] Setting up module Omahku::Eth"));
    } else {
        Serial.println(F("[ FAIL ] Setting up module Omahku::Eth"));
    }

    test2.addInput(I_DK_1);
    test2.addAllOutInput(I_DK_6);
    test3.addInput(I_DK_2);
    test3.addAllOutInput(I_DK_6);
    test4.addInput(I_DK_3);
    test4.addAllOutInput(I_DK_6);
    test5.addInput(I_DK_4);
    test5.addAllOutInput(I_DK_6);
    test6.addInput(I_DK_5);
    test6.addAllOutInput(I_DK_6);

    Serial.println(F("Omahku running."));

    return true;
}

void App::loop()
{
    // Loop over every digital output.
    DigitalOutput::loop();
    
    ethernetModule.loop();

    // Loop every second.
    if (millis() > timer + 1000)
    {
        timer = millis();
    }
}