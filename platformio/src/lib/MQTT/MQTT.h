/**
 * @file MQTT.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief The MQTT module header file.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef OMAHKU_MQTT
#define OMAHKU_MQTT

#include "debug.h"
#include "config.h"
#include <EthernetENC.h>
#include <PubSubClient.h>

namespace Omahku
{
    class MQTT
    {
    protected:
        EthernetClient _ethClient;
        PubSubClient _client;
    public:
        MQTT();
        ~MQTT();

        bool setup();
        void loop();

        bool publish(const char *topic, const char *payload);
        
        PubSubClient getPubSubClient();
    };
}

#endif