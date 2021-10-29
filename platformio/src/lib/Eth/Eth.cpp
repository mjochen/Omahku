#include "Eth.h"

using namespace Omahku;

Eth::Eth() = default;

Eth::~Eth() = default;

bool Eth::setup()
{
    byte macAddress[] = {
        MAC_ADDR_BYTE_1,
        MAC_ADDR_BYTE_2,
        MAC_ADDR_BYTE_3,
        MAC_ADDR_BYTE_4,
        MAC_ADDR_BYTE_5,
        MAC_ADDR_BYTE_6
    };

    // Start the Ethernet connection with the MAC address and specify a timeout of 5 seconds.
    if (Ethernet.begin(macAddress, 5000UL) == 0)
    {
        debugln("Failed to configure Ethernet using DHCP.");

        if (Ethernet.hardwareStatus() == EthernetNoHardware)
        {
            debugln("Ethernet controller not found.");
        } 
        else if (Ethernet.linkStatus() == LinkOFF)
        {
            debugln("Ethernet cable is not connected/no link.");
        }

        return false;
    }

    debug("I have an IP address! It's: ");
    debugln(Ethernet.localIP());

    return true;
}

void Eth::loop()
{
    switch (Ethernet.maintain())
    {
        case 1:
            // DHCP lease renewal failed.
            debugln("I have no IP address anymore...");
            break;
        
        case 2:
            // DHCP lease renewal success.
            debugln("I got to keep my IP address!");
            break;

        case 3:
            // Rebind fail.
            debugln("Rebind failed.");
            break;

        case 4:
            // Rebind success.
            debugln("Rebind success.");
            break;

        default:
            // Nothing going on here...
            break;
    }
}