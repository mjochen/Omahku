/**
 * @file debug.h
 * @author Jonas Claes (jonas@jonasclaes.be)
 * @brief This file is used to turn info and debug statements on or off.
 * @version 0.1
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef OMAHKU_DEBUG
#define OMAHKU_DEBUG

#define INFO 1
#define DEBUG 0

#if INFO == 1
    #define info(x) Serial.print(x)
    #define infoln(x) Serial.println(x)
#else
    #define info(x)
    #define infoln(x)
#endif

#if DEBUG == 1
    #define debug(x) info(x)
    #define debugln(x) infoln(x)
#else
    #define debug(x)
    #define debugln(x)
#endif

#endif