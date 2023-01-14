#pragma once

#include <Adafruit_MPU6050.h>

/**
 * @file sound-player.h
 * @brief This file contains all functions related to sound.
 *
 * Copyright (C) BesAir Foundation 2023
 */
namespace BesAirSound
{
    void log(String msg);
    void on_setup();
    void on_loop();

    bool is_playing();
    void queue_sound(const String &filename);
    void play_sound(const String &filename);
    String get_language();
    void change_language(const char *new_lang);

    void speak_string(String str);
}
