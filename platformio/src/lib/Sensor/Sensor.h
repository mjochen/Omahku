/**
 * @file Sensor.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief Sensor header file.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 * Extra info: sadly enough we must do all
 * the programming for this template in the
 * header file, since we cannot easily
 * abstract away implementations of the template.
 * 
 */

#ifndef OMAHKU_SENSOR
#define OMAHKU_SENSOR

#include <Arduino.h>
#include "lib/MQTT/MQTT.h"

#define MAX_NAME_SIZE 30
#define MAX_TOPIC_SIZE 80

namespace Omahku
{
    class Sensor
    {
    protected:
        // Output name and topic for MQTT.
        char _outputName[MAX_NAME_SIZE];
        char _topicName[MAX_TOPIC_SIZE];

        MQTT* _mqttInstance;
        int _state;
    public:
        // Sensor();
        Sensor(int initialState, const char *sensorName)
        {
            strncpy(_outputName, sensorName, MAX_NAME_SIZE);
            snprintf(_topicName, MAX_TOPIC_SIZE, "%s/%s/%s", CUSTOM_HOST_NAME, "/sensor/", _outputName);
            _mqttInstance = nullptr;
            _state = initialState;
        }

        ~Sensor() {}

        void loop()
        {
            // If MQTT is enabled, update the status in MQTT.
            if (_mqttInstance != nullptr)
            {
                _state++;
                char test[30];
                snprintf(test, 30, "%d", _state);
                _mqttInstance->publish(_topicName, test);
            }
        }

        void setMQTTInstance(MQTT* mqttInstance)
        {
            _mqttInstance = mqttInstance;
        }

        int getState()
        {
            return _state;
        }

        void setState(int state)
        {
            _state = state;
        }
    };
}

#endif