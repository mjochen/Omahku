#include "App.h"

using namespace Omahku;

App::App() = default;

App::~App() = default;

DigitalOutput test2{Q_RELAY_1};
DigitalOutput test3{Q_RELAY_2};
DigitalOutput test4{Q_RELAY_3};
DigitalOutput test5{Q_RELAY_4};
DigitalOutput test6{Q_RELAY_5};
DigitalOutput test7{Q_RELAY_6};

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

    test2.addInput(I_PB_1)->addAllOutInput(I_PB_6);
    test3.addInputs(new uint8_t[1]{I_PB_2}, 1)->addAllOutInput(I_PB_6);
    test4.addInputs(new uint8_t[1]{I_PB_3}, 1)->addAllOutInput(I_PB_6);
    test5.addInputs(new uint8_t[1]{I_PB_4}, 1)->addAllOutInput(I_PB_6);
    test6.addInputs(new uint8_t[1]{I_PB_5}, 1)->addAllOutInputs(new uint8_t[1]{I_PB_6}, 1);

    Serial.println(F("Omahku running."));

    return true;
}

void App::loop()
{
    // Loop over every digital output.
    DigitalOutput::loop();
    
    // Handle Ethernet events and maintain the DHCP lease.
    ethernetModule.loop();

    // Loop every second.
    if (millis() > timer + 1000)
    {
        timer = millis();
    }
}