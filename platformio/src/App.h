#ifndef OMAHKU_APP
#define OMAHKU_APP

#include <Arduino.h>
#include "config.h"
#include "lib/Eth/Eth.h"
#include "lib/DigitalOutput/DigitalOutput.h"

namespace Omahku
{
    class App
    {
    protected:
        Eth ethernetModule;
    public:
        unsigned long timer;
        App();
        ~App();

        bool setup();
        void loop();
    };
}

#endif