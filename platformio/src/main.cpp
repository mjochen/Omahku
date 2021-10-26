#include "App.h"

// Fancy C hack to let the processor force-reset.
// This is done using a null-pointer, yay!
void (* reset) (void) = 0;

// Create an empty instance of the application.
Omahku::App app;

void setup()
{
    if (!app.setup())
    {
        reset();       
    }
}

void loop()
{
    app.loop();
}