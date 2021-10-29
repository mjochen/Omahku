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
        debugln(F("Failed to configure Ethernet using DHCP."));

        if (Ethernet.hardwareStatus() == EthernetNoHardware)
        {
            debugln(F("Ethernet controller not found."));
        } 
        else if (Ethernet.linkStatus() == LinkOFF)
        {
            debugln(F("Ethernet cable is not connected/no link."));
        }

        return false;
    }

    debug(F("I have an IP address! It's: "));
    debugln(Ethernet.localIP());

    return true;
}

void Eth::loop()
{
    switch (Ethernet.maintain())
    {
        case 1:
            // DHCP lease renewal failed.
            debugln(F("I have no IP address anymore..."));
            break;
        
        case 2:
            // DHCP lease renewal success.
            debugln(F("I got to keep my IP address!"));
            break;

        case 3:
            // Rebind fail.
            debugln(F("Rebind failed."));
            break;

        case 4:
            // Rebind success.
            debugln(F("Rebind success."));
            break;

        default:
            // Nothing going on here...
            break;
    }
}