#pragma once

extern bool besair_active;
extern bool emergency;
extern bool fan_state;

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
    void init_lights();
    void update_lights(float acc);
    void danger_lights();
    void show_lights();

    float get_acceleration();
}
