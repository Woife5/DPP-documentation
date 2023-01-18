#pragma once

// stores the content of the index.html file we want the webserver to send
extern const char index_html[] PROGMEM;
// stores the state of the besn, stored in main.cpp
extern bool besair_active;
extern bool emergency;

/**
 * @file rest-server.h
 * @brief This file contains all rest server ralated functions.
 *
 * Copyright (C) BesAir Foundation 2023
 */
namespace BesAirWebserver
{
    void log(String msg);
    void on_setup();
    const String get_ip();
}
