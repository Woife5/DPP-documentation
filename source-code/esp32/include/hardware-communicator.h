#pragma once

extern bool besnState;
extern bool emergency;

/**
 * @file hardware-communicator.h
 * @brief This file contains all hardware-communication functions.
 *
 * Copyright (C) BesAir Foundation 2023
 */
namespace BesAir
{
    void on_setup();

    void start_motor();
    void stop_motor();

    void reset_lights();
    void update_lights(float acc);
    void show_lights();

    float get_acceleration();
}
