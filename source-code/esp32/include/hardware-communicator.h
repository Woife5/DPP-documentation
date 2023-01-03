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

    float get_acceleration();
}