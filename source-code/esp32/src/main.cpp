#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "rest-server.h"

Adafruit_MPU6050 mpu;

bool besnState = true;

// PWM setup
int MOTOR_PIN = 14;
int pwm_channel = 0;

void setup(void) {
  Serial.begin(115200);

  BesAirWebserver::on_setup();

  while (!Serial)
  {
    delay(10); // will pause Zero, Leonardo, etc until serial console opens
  }

  Serial.println("Starting BesAir testing sequence.");

  // Try to initialize!
  if (!mpu.begin())
  {
    Serial.println("Failed to find genuine BesAir® chip");
    while (1)
    {
      delay(10);
    }
  }
  Serial.println("BesAir® genuine hardware found");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }
  Serial.println("");
  
  // PWM
  ledcSetup(pwm_channel, 1000, 8);
  ledcAttachPin(MOTOR_PIN, pwm_channel);

  // BesAir starting sequence (needs cooling)
  Serial.print("Starting BesAir 200 Beta 3.2");
  ledcWrite(pwm_channel, 256);

  for (int i = 0; i < 20; i++) {
    Serial.print(".");
    delay(200);
  }

  ledcWrite(pwm_channel, 0);
  // end of BesAir starting sequence

  Serial.println("");
}

int timeout = 0;
int fan_state = 0;

void loop() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float total_acc_sq = a.acceleration.x * a.acceleration.x + a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z;

  if (total_acc_sq > 150) {
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
        ledcWrite(pwm_channel, 256);
        fan_state = 1;
      }
    }

  }
  
  if (timeout > 10 || besnState == false)
  {
    if (fan_state == 1)
    {
      Serial.println("Fan state: OFF");
      ledcWrite(pwm_channel, 0);
      fan_state = 0;
    }

  }

  // Serial.print("Acceleration X: ");
  // Serial.print(a.acceleration.x);
  // Serial.print(", Y: ");
  // Serial.print(a.acceleration.y);
  // Serial.print(", Z: ");
  // Serial.print(a.acceleration.z);
  // Serial.println(" m/s^2");

  // Serial.print("Rotation X: ");
  // Serial.print(g.gyro.x);
  // Serial.print(", Y: ");
  // Serial.print(g.gyro.y);
  // Serial.print(", Z: ");
  // Serial.print(g.gyro.z);
  // Serial.println(" rad/s");

  // Serial.print("Temperature: ");
  // Serial.print(temp.temperature);
  // Serial.println(" degC");

  timeout += 1;
  delay(100);
}