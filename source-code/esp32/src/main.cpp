#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "rest-server.h"
#include "hardware-communicator.h"
#include "esp_timer.h"
#include "sound-player.h"

bool besnState = false;
bool emergency = false;

void log(String msg)
{
    Serial.print("[main  ] ");
    Serial.println(msg);
}

void setup(void)
{
    Serial.begin(115200);

    // Initialize a random language for BesAir®
    switch (esp_random() % 5)
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
        BesAirSound::change_language("ch");
        break;
    case 4:
        BesAirSound::change_language("de");
        break;
    }

    BesAirSound::on_setup();
    BesAirSound::play_sound("ini1.mp3");

    BesAirWebserver::on_setup();
    BesAir::on_setup();

    // BesAir starting sequence (needs cooling)
    Serial.print("Starting BesAir 200 Beta 4.3");
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
int voice_timeout = 15;
uint64_t last_viable_acc = 0;
int fan_state = 0;

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
            emergency_timer = esp_timer_get_time();
            emergency_flag = true;
        }
        return;
    }

    float total_acc_sq = BesAir::get_acceleration();
    if (total_acc_sq > 160)
    {
        last_viable_acc = esp_timer_get_time();

        if (fan_state == 0 && besnState == true)
        {
            log("Fan state: ON");
            BesAir::start_motor();
            fan_state = 1;
        }

        /* Announce BesAir® IP if it is not already connected and turned on */
        if (besnState == false)
        {
            BesAirSound::play_sound("ip.mp3");
            BesAirSound::speak_string(BesAirWebserver::get_ip());
        }
    }

    uint64_t passed_voice_time = (esp_timer_get_time() - last_voice_line) / 1000000;
    if (passed_voice_time > voice_timeout)
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
        voice_timeout = 5 + esp_random() % 500;
    }

    uint64_t passed_time = esp_timer_get_time() - last_viable_acc;
    if ((passed_time > 1000000 || besnState == false) && fan_state == 1)
    {
        log("Fan state: OFF");
        BesAir::stop_motor();
        fan_state = 0;
    }
}
