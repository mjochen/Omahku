/**
 * @file App.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Main application implementation file.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "App.h"

using namespace Omahku;

App::App() = default;

App::~App() = default;

// Create outputs.
// Optional: output name in MQTT, if you do not
// specify this, the output pin number will be used.
DigitalOutput test2{Q_RELAY_1, "relay1"};
DigitalOutput test3{Q_RELAY_2};
DigitalOutput test4{Q_RELAY_3};
DigitalOutput test5{Q_RELAY_4};
DigitalOutput test6{Q_RELAY_5};

auto virtualSensor = Sensor(0, "virty01");

bool App::setup()
{
    // Startup serial.
    #if INFO == 1
        Serial.begin(115200);
    #endif
    infoln(F("Starting up Omahku controller..."));

    // Setup Ethernet module.
    info(F("[      ] Setting up module Eth..."));
    if (ethernetModule.setup())
    {
        infoln(F("\r[  OK  ] Setting up module Omahku::Eth"));
    } else {
        infoln(F("\r[ FAIL ] Setting up module Omahku::Eth"));
    }

    // Setup MQTT module.
    info(F("[      ] Setting up module MQTT..."));
    if (mqttModule.setup())
    {
        infoln(F("\r[  OK  ] Setting up module Omahku::MQTT"));
    } else {
        infoln(F("\r[ FAIL ] Setting up module Omahku::MQTT"));
    }

    // Set up the digital outputs for use with MQTT.
    DigitalOutput::setMQTTInstance(&mqttModule);

    // Setup I/O.
    test2.addInput(I_PB_1)->addAllOffInput(I_PB_6);
    test3.addInputs(new uint8_t[1]{I_PB_2}, 1)->addAllOffInput(I_PB_6);
    test4.addInputs(new uint8_t[1]{I_PB_3}, 1)->addAllOffInput(I_PB_6)->setTimeDelay(0, 0, 10);
    test5.addInputs(new uint8_t[1]{I_PB_4}, 1)->addAllOffInput(I_PB_6)->setTimeDelay(3000);
    test6.addInputs(new uint8_t[1]{I_PB_5}, 1)->addAllOffInputs(new uint8_t[1]{I_PB_6}, 1);

    virtualSensor.setMQTTInstance(&mqttModule);

    infoln(F("Omahku running."));

    return true;
}

void App::loop()
{
    // Loop over every digital output.
    DigitalOutput::loop();
    
    // Check if there is a link on the Ethernet port.
    // If there is no link, we don't need to keep checking for a new lease.
    // If there is a link, maintain it and maintain the lease.
    // Loop takes a long time to timeout -> Arduino inputs unresponsive.
    // This issue does not occur on an ESP32 with 2 cores.
    if (Ethernet.linkStatus() == LinkON)
    {
        // Handle Ethernet events and maintain the DHCP lease.
        ethernetModule.loop();

        // Handle MQTT looping.
        // It only makes sense to do it here, since if there
        // is no Ethernet connection, MQTT will not function.
        mqttModule.loop();
    }
    
    // Loop every second.
    if (millis() > timer + 1000)
    {
        virtualSensor.loop();

        timer = millis();
    }
}