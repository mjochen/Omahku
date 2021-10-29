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
    this->_client = PubSubClient(this->_ethClient);

    // Set the MQTT server address and port.
    this->_client.setServer(MQTT_SERVER_ADDRESS, MQTT_SERVER_PORT);

    return true;
}

void MQTT::loop()
{
    // If the client is not connected, retry the connection.
    if (!_client.connected())
    {
        debugln(F("Trying MQTT connection..."));

        if (_client.connect(MQTT_CLIENT_ID))
        {
            debugln(F("MQTT client connected."));
        }
    }

    // Process MQTT messages and maintain the connection
    // to the server. Also send periodic keep alives.
    _client.loop();
}

bool MQTT::publish(const char *topic, const char *payload)
{
    return _client.publish(topic, payload);
}

PubSubClient MQTT::getPubSubClient()
{
    return _client;
}