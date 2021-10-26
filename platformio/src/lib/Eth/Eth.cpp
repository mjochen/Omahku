#include "Eth.h"

using namespace Omahku;

Eth::Eth() = default;

Eth::~Eth() = default;

bool Eth::setup()
{
    // CHANGEME: Config option should come here.
    byte macAddress[] = { 0x74, 0x69, 0x69, 0x2D, 0x30, 0x31 };

    if (Ethernet.begin(macAddress) == 0)
    {
        Serial.println("Failed to configure Ethernet using DHCP.");

        if (Ethernet.hardwareStatus() == EthernetNoHardware)
        {
            Serial.println("Ethernet controller not found.");
        } 
        else if (Ethernet.linkStatus() == LinkOFF)
        {
            Serial.println("Ethernet cable is not connected/no link.");
        }

        return false;
    }

    Serial.print("I have an IP address! It's: ");
    Serial.println(Ethernet.localIP());

    return true;
}

void Eth::loop()
{
    switch (Ethernet.maintain())
    {
        case 1:
            // DHCP lease renewal failed.
            Serial.println("I have no IP address anymore...");
            break;
        
        case 2:
            // DHCP lease renewal success.
            Serial.println("I got to keep my IP address!");
            break;

        case 3:
            // Rebind fail.
            Serial.println("Rebind failed.");
            break;

        case 4:
            // Rebind success.
            Serial.println("Rebind success.");
            break;

        default:
            // Nothing going on here...
            break;
    }
}