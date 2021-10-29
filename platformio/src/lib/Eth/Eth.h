#ifndef OMAHKU_ETH
#define OMAHKU_ETH

#include "debug.h"
#include "config.h"
#include <SPI.h>
#include <EthernetENC.h>

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