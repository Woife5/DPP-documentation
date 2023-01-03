#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "rest-server.h"
#include "hardware-communicator.h"
#include "esp_timer.h"

bool besnState = true;

void setup(void)
{
    Serial.begin(115200);
    BesAirWebserver::on_setup();
    BesAir::on_setup();

    // BesAir starting sequence (needs cooling)
    Serial.print("Starting BesAir 200 Beta 3.2");
    BesAir::start_motor();

    for (int i = 0; i < 20; i++)
    {
        Serial.print(".");
        delay(200);
    }

    BesAir::stop_motor();

    Serial.println("");
}

uint64_t last_viable_acc = 0.0;
int fan_state = 0;

void loop()
{
    float total_acc_sq = BesAir::get_acceleration();
    if (total_acc_sq > 150)
    {
        last_viable_acc = esp_timer_get_time();

        if (fan_state == 0 && besnState == true)
        {
            Serial.println("Fan state: ON");
            BesAir::start_motor();
            fan_state = 1;
        }
    }

    uint64_t passed_time = esp_timer_get_time() - last_viable_acc;
    if ((passed_time > 1000000 || besnState == false) && fan_state == 1)
    {
        Serial.println("Fan state: OFF");
        BesAir::stop_motor();
        fan_state = 0;
    }
}
