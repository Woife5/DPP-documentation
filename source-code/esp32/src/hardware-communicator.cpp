#include "hardware-communicator.h"
#include "sound-player.h"
#include <Adafruit_NeoPixel.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
const int PWM_MOTOR_PIN = 27;
const int PWM_MOTOR_CHANNEL = 0;

const int MOTOR_PIN = 12;

const int LED_STRIP_PIN = 21;
const int LED_RING_PIN = 16;

const int LED_STRIP_PIXELS = 28;
const int LED_RING_PIXELS = 30;

const float EARTH_GRAVITY_SQ = 96.3;
const uint8_t LED_STRIP_MAX_ACC = 150;

Adafruit_NeoPixel led_strip(LED_STRIP_PIXELS, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_ring(LED_RING_PIXELS, LED_RING_PIN, NEO_GRB + NEO_KHZ800);

bool motor_on = false;

void log_besair(String msg)
{
    Serial.print("[BesAir] ");
    Serial.println(msg);
}

void BesAir::on_setup()
{
    while (!Serial)
    {
        delay(10); // will pause Zero, Leonardo, etc until serial console opens
    }

    log_besair("Starting BesAir testing sequence.");

    // Initialize the mpu (gyro and accelerometer)
    if (!mpu.begin())
    {
        log_besair("Failed to find genuine BesAir® chip");
        while (1)
        {
            delay(10);
        }
    }
    log_besair("BesAir® genuine hardware found");

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    Serial.print("[BesAir] Accelerometer range set to: ");
    switch (mpu.getAccelerometerRange())
    {
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
    Serial.print("[BesAir] Gyro range set to: ");
    switch (mpu.getGyroRange())
    {
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
    Serial.print("[BesAir] Filter bandwidth set to: ");
    switch (mpu.getFilterBandwidth())
    {
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

    // Initialize PWM channels (pwm motor)
    // ledcSetup(PWM_MOTOR_CHANNEL, 1000, 8);
    // ledcAttachPin(PWM_MOTOR_PIN, PWM_MOTOR_CHANNEL);

    pinMode(MOTOR_PIN, OUTPUT);

    // LED setup
    log_besair("Initializing LED strips");

    led_strip.begin();
    led_strip.show();
    led_strip.setBrightness(50);

    led_ring.begin();
    led_ring.show();
    led_ring.setBrightness(50);
}

uint32_t hue_to_rgba(float hue)
{
    float C = 1.0;
    float X = 1 - abs(fmod(hue / 60.0, 2) - 1);
    float m = 1.0 - C;
    float r, g, b;

    if (hue >= 0 && hue < 60)
    {
        r = C, g = X, b = 0;
    }
    else if (hue >= 60 && hue < 120)
    {
        r = X, g = C, b = 0;
    }
    else if (hue >= 120 && hue < 180)
    {
        r = 0, g = C, b = X;
    }
    else if (hue >= 180 && hue < 240)
    {
        r = 0, g = X, b = C;
    }
    else if (hue >= 240 && hue < 300)
    {
        r = X, g = 0, b = C;
    }
    else
    {
        r = C, g = 0, b = X;
    }

    return led_strip.Color(r * 255, g * 255, b * 255);
}

uint32_t get_pixel_color(size_t pixel, size_t total_pixels)
{
    float hue = 360.0 * pixel / total_pixels;
    return hue_to_rgba(hue);
}

uint64_t last_led_update = esp_timer_get_time();

const uint32_t LED_RING_ON_COLOR = led_ring.Color(3, 244, 252);
const uint32_t LED_RING_OFF_COLOR = led_ring.Color(255, 0, 0);
const uint8_t LED_RING_ON_COUNT = 3;
uint8_t ring_leds_on[LED_RING_ON_COUNT] = {0, 1, 2};
uint32_t strip_led_colors[LED_STRIP_PIXELS] = {0};

void BesAir::reset_lights()
{
    for (size_t i = 0; i < led_strip.numPixels(); i++)
    {
        led_strip.setPixelColor(i, led_strip.Color(0, 0, 0));
    }

    for (size_t i = 0; i < led_ring.numPixels(); i++)
    {
        led_ring.setPixelColor(i, led_ring.Color(0, 0, 0));
    }
}

float average_acc = 0;

void BesAir::update_lights(float acc)
{
    average_acc = (average_acc * 0.9) + (acc * 0.1);

    if (esp_timer_get_time() - last_led_update < 10000)
    {
        return;
    }

    last_led_update = esp_timer_get_time();
    BesAir::reset_lights();

    // LEDs should be turned off if sound is currently playing
    if (BesAirSound::is_playing() || emergency == true)
    {
        BesAir::show_lights();
        return;
    }

    // LED ring should flash when motor is on and spin if it is off.
    if (motor_on == false)
    {
        for (size_t i = 0; i < LED_RING_ON_COUNT; i++)
        {
            led_ring.setPixelColor(ring_leds_on[i], besnState == true ? LED_RING_ON_COLOR : LED_RING_OFF_COLOR);
            ring_leds_on[i] = (ring_leds_on[i] + 1) % LED_RING_PIXELS;
        }
    }
    else
    {
        for (size_t i = 0; i < LED_RING_PIXELS; i++)
        {
            led_ring.setPixelColor(i, led_ring.Color(random(255), random(255), random(255)));
        }
    }

    // LED strip should be lit up based on the acceleration
    Serial.printf("Acceleration: %f\n", average_acc);
    long max_led = map(average_acc, 0, LED_STRIP_MAX_ACC, 0, LED_STRIP_PIXELS);
    for (size_t i = 0; i < LED_STRIP_PIXELS; i++)
    {
        if (i < max_led)
        {
            strip_led_colors[i] = get_pixel_color(i, LED_STRIP_PIXELS);
        }
        else
        {
            strip_led_colors[i] = led_strip.Color(0, 0, 0);
        }
    }

    for (size_t i = 0; i < LED_STRIP_PIXELS; i++)
    {
        led_strip.setPixelColor(LED_STRIP_PIXELS - i, strip_led_colors[i]);
    }

    BesAir::show_lights();
}

void BesAir::show_lights()
{
    led_ring.show();
    led_strip.show();
}

void BesAir::start_motor()
{
    // ledcWrite(PWM_MOTOR_CHANNEL, 256);
    digitalWrite(MOTOR_PIN, HIGH);
    motor_on = true;
}

void BesAir::stop_motor()
{
    // ledcWrite(PWM_MOTOR_CHANNEL, 0);
    digitalWrite(MOTOR_PIN, LOW);
    motor_on = false;
}

/**
 * @brief Get the squared acceleration of the BesAir® device.
 */
float BesAir::get_acceleration()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    float total_acc = a.acceleration.x * a.acceleration.x + a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z;
    return abs(EARTH_GRAVITY_SQ - total_acc);

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
}
