/**
 * @file App.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Main application header file.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef OMAHKU_APP
#define OMAHKU_APP

#include <Arduino.h>
#include "debug.h"
#include "config.h"
#include "lib/Eth/Eth.h"
#include "lib/MQTT/MQTT.h"
#include "lib/DigitalOutput/DigitalOutput.h"
#include "lib/Sensor/Sensor.h"

namespace Omahku
{
    class App
    {
    protected:
        Eth ethernetModule;
        MQTT mqttModule;
    public:
        unsigned long timer;
        App();
        ~App();

        bool setup();
        void loop();
    };
}

#endif