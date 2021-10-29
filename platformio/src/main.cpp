/**
 * @file main.cpp
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief This is the main entry point for Arduino code.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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