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

        // User definitions
        
        DigitalOutput test2{Q_RELAY_1};
        DigitalOutput test3{Q_RELAY_2};
        DigitalOutput test4{Q_RELAY_3};
        DigitalOutput test5{Q_RELAY_4};
        DigitalOutput test6{Q_RELAY_5};
        DigitalOutput test7{Q_RELAY_6};

        // END User definitions
    public:
        unsigned long timer;
        App();
        ~App();

        bool setup();
        void loop();
    };
}

#endif