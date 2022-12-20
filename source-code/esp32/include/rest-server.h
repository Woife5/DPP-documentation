#pragma once

// stores the content of the index.html file we want the webserver to send
extern const char index_html[] PROGMEM;
// stores the state of the besn, stored in main.cpp
extern bool besnState;

namespace BesAirWebserver {
    void on_setup();
}
