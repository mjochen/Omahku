#ifndef OMAHKU_ETH
#define OMAHKU_ETH

#include "config.h"
#include <SPI.h>
#include <EthernetENC.h>

#ifdef HOST_NAME
#undef HOST_NAME
#define HOST_NAME ard
#endif

namespace Omahku
{
    class Eth
    {
    public:
        Eth();
        ~Eth();

        bool setup();
        void loop();
    };
}

#endif