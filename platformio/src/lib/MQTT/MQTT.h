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
        EthernetClient ethClient;
        
    public:
        PubSubClient client;

        MQTT();
        ~MQTT();

        bool setup();
        void loop();
    };
}

#endif