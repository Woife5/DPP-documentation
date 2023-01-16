#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "rest-server.h"
#include "hardware-communicator.h"
#include "esp_timer.h"
#include "sound-player.h"

bool besnState = false;
bool emergency = false;

// How long the fan will stay on once it is turned on
const size_t FAN_TIMEOUT = 0.7 * 1000 * 1000;

// The minimum squared accelleration at which the fan will turn on
const uint8_t FAN_ACTIVASION_THRESHOLD = 65;

void log(String msg)
{
    Serial.print("[main  ] ");
    Serial.println(msg);
}

void setup(void)
{
    Serial.begin(115200);

    BesAir::on_setup();
    BesAir::init_lights();
    BesAir::show_lights();

    // Initialize a random language for BesAir®
    switch (esp_random() % 4)
    {
    case 0:
        BesAirSound::change_language("ru");
        break;
    case 1:
        BesAirSound::change_language("jp");
        break;
    case 2:
        BesAirSound::change_language("us");
        break;
    case 3:
        BesAirSound::change_language("de");
        break;
    }

    BesAirSound::on_setup();
    BesAirSound::play_sound("ini1.mp3");

    BesAirWebserver::on_setup();

    // BesAir starting sequence (needs cooling)
    Serial.print("Starting BesAir");
    BesAir::start_motor();

    for (int i = 0; i < 20; i++)
    {
        Serial.print(".");
        delay(200);
    }

    BesAir::stop_motor();
    Serial.println("");
    BesAirSound::play_sound("ini2.mp3");
}

uint64_t last_voice_line = esp_timer_get_time();
uint64_t last_viable_acc = 0;
uint16_t random_voice_timeout = 15;
bool fan_state = false;

bool emergency_flag = false;
uint64_t emergency_timer = 0;

void loop()
{
    BesAirSound::on_loop();

    if (emergency_flag == true && emergency_timer + 40000000 < esp_timer_get_time())
    {
        ESP.restart();
    }

    if (emergency == true)
    {
        if (emergency_flag == false)
        {
            BesAir::danger_lights();
            emergency_timer = esp_timer_get_time();
            emergency_flag = true;
        }
        return;
    }

    float total_acc_sq = BesAir::get_acceleration();
    BesAir::update_lights(total_acc_sq);

    if (total_acc_sq > FAN_ACTIVASION_THRESHOLD)
    {
        last_viable_acc = esp_timer_get_time();

        if (fan_state == false && besnState == true)
        {
            log("Fan state: ON");
            BesAir::start_motor();
            fan_state = true;
        }

        /* Announce BesAir® IP if it is not already connected and turned on */
        if (besnState == false)
        {
            BesAirSound::play_sound("ip.mp3");
            BesAirSound::speak_string(BesAirWebserver::get_ip());
        }
    }

    uint64_t passed_voice_time = (esp_timer_get_time() - last_voice_line) / 1000000;
    if (passed_voice_time > random_voice_timeout)
    {
        int random = esp_random() % 5;

        if (random == 0)
        {
            BesAirSound::queue_sound("charge1.mp3");
        }
        else if (random == 1)
        {
            BesAirSound::queue_sound("slogan1.mp3");
        }
        else if (random == 2)
        {
            BesAirSound::queue_sound("slogan2.mp3");
        }
        else if (random == 3)
        {
            BesAirSound::queue_sound("slogan3.mp3");
        }
        else if (random == 4)
        {
            BesAirSound::queue_sound("calibr1.mp3");
        }

        last_voice_line = esp_timer_get_time();
        random_voice_timeout = 20 + esp_random() % 500;
    }

    uint64_t passed_time = esp_timer_get_time() - last_viable_acc;
    if ((passed_time > FAN_TIMEOUT || besnState == false) && fan_state == true)
    {
        log("Fan state: OFF");
        BesAir::stop_motor();
        fan_state = false;
    }
}
