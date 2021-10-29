/**
 * @file MQTT.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief The MQTT module implementation file.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "MQTT.h"

using namespace Omahku;

MQTT::MQTT() = default;

MQTT::~MQTT() = default;

bool MQTT::setup()
{
    // Create a new PubSubClient with the Ethernet card.
    this->client = PubSubClient(this->ethClient);

    // Set the MQTT server address and port.
    this->client.setServer(MQTT_SERVER_ADDRESS, MQTT_SERVER_PORT);

    return true;
}

void MQTT::loop()
{
    // If the client is not connected, retry the connection.
    if (!client.connected())
    {
        debugln("Trying MQTT connection...");

        if (client.connect(MQTT_CLIENT_ID))
        {
            debugln("MQTT client connected.");
        }
    }

    // Process MQTT messages and maintain the connection
    // to the server. Also send periodic keep alives.
    client.loop();
}