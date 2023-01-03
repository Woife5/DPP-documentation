#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "rest-server.h"
#include "hardware-communicator.h"

bool besnState = true;

void setup(void)
{

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

int timeout = 0;
int fan_state = 0;

void loop()
{
    float total_acc_sq = BesAir::get_acceleration();

    if (total_acc_sq > 150)
    {
        timeout = 0;

        if (fan_state == 0)
        {
            if (besnState == false)
            {
                Serial.println("Besn is turned off :(");
            }
            else
            {
                Serial.println("Fan state: ON");
                BesAir::start_motor();
                fan_state = 1;
            }
        }
    }

    if (timeout > 10 || besnState == false)
    {
        if (fan_state == 1)
        {
            Serial.println("Fan state: OFF");
            BesAir::stop_motor();
            fan_state = 0;
        }
    }

    timeout += 1;
    delay(100);
}