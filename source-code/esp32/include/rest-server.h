#pragma once

// stores the content of the index.html file we want the webserver to send
extern const char index_html[] PROGMEM;
// stores the state of the besn, stored in main.cpp
extern bool besnState;
extern bool emergency;

namespace BesAirWebserver
{
    void log(String msg);
    void on_setup();
    const String get_ip();
}
