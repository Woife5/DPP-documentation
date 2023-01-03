#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include "sound-player.h"

// Specifically for use with the Adafruit Feather, the pins are pre-set here!

// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <SD.h>
#include <Adafruit_VS1053.h>

// These are the pins used
#define VS1053_RESET -1 // VS1053 reset pin (not used!)

// Feather ESP8266
#if defined(ESP8266)
#define VS1053_CS 16  // VS1053 chip select pin (output)
#define VS1053_DCS 15 // VS1053 Data/command select pin (output)
#define CARDCS 2      // Card chip select pin
#define VS1053_DREQ 0 // VS1053 Data request, ideally an Interrupt pin

// Feather ESP32
#elif defined(ESP32) && !defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S2)
#define VS1053_CS 32   // VS1053 chip select pin (output)
#define VS1053_DCS 33  // VS1053 Data/command select pin (output)
#define CARDCS 14      // Card chip select pin
#define VS1053_DREQ 15 // VS1053 Data request, ideally an Interrupt pin

// Feather Teensy3
#elif defined(TEENSYDUINO)
#define VS1053_CS 3   // VS1053 chip select pin (output)
#define VS1053_DCS 10 // VS1053 Data/command select pin (output)
#define CARDCS 8      // Card chip select pin
#define VS1053_DREQ 4 // VS1053 Data request, ideally an Interrupt pin

// WICED feather
#elif defined(ARDUINO_STM32_FEATHER)
#define VS1053_CS PC7    // VS1053 chip select pin (output)
#define VS1053_DCS PB4   // VS1053 Data/command select pin (output)
#define CARDCS PC5       // Card chip select pin
#define VS1053_DREQ PA15 // VS1053 Data request, ideally an Interrupt pin

#elif defined(ARDUINO_NRF52832_FEATHER)
#define VS1053_CS 30   // VS1053 chip select pin (output)
#define VS1053_DCS 11  // VS1053 Data/command select pin (output)
#define CARDCS 27      // Card chip select pin
#define VS1053_DREQ 31 // VS1053 Data request, ideally an Interrupt pin

// Feather M4, M0, 328, ESP32S2, nRF52840 or 32u4
#else
#define VS1053_CS 6   // VS1053 chip select pin (output)
#define VS1053_DCS 10 // VS1053 Data/command select pin (output)
#define CARDCS 5      // Card chip select pin
// DREQ should be an Int pin *if possible* (not possible on 32u4)
#define VS1053_DREQ 9 // VS1053 Data request, ideally an Interrupt pin

#endif

Adafruit_VS1053_FilePlayer musicPlayer =
    Adafruit_VS1053_FilePlayer(VS1053_RESET, VS1053_CS, VS1053_DCS, VS1053_DREQ, CARDCS);

bool sound_available = true;

// File listing helper
void printDirectory(File dir, int numTabs)
{
    while (true)
    {
        File entry = dir.openNextFile();
        if (!entry)
        {
            // no more files
            break;
        }
        for (uint8_t i = 0; i < numTabs; i++)
        {
            Serial.print('\t');
        }
        Serial.print(entry.name());
        if (entry.isDirectory())
        {
            Serial.println("/");
            printDirectory(entry, numTabs + 1);
        }
        else
        {
            // files have sizes, directories do not
            Serial.print("\t\t");
            Serial.println(entry.size(), DEC);
        }
        entry.close();
    }
}

void BesAirSound::on_setup()
{
    Serial.println("Sound playe initializing.");
    Serial.println("\nAdafruit VS1053 Feather Test");

    if (!musicPlayer.begin())
    {
        Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
        sound_available = false;
    }

    Serial.println(F("VS1053 found"));

    // musicPlayer.sineTest(0x44, 500);    // Make a tone to indicate VS1053 is working

    if (!SD.begin(CARDCS))
    {
        Serial.println(F("SD failed, or not present"));
        sound_available = false;
    }
    Serial.println("SD OK!");

    // list files
    // printDirectory(SD.open("/"), 0);

    // Set volume for left, right channels. lower numbers == louder volume!
    musicPlayer.setVolume(50, 50);

    musicPlayer.sciWrite(VS1053_REG_WRAMADDR, VS1053_GPIO_DDR);
    musicPlayer.sciWrite(VS1053_REG_WRAM, 3);
    musicPlayer.sciWrite(VS1053_REG_WRAMADDR, VS1053_GPIO_ODATA);
    musicPlayer.sciWrite(VS1053_REG_WRAM, 0);
    delay(100);
    musicPlayer.softReset();

#if defined(__AVR_ATmega32U4__)
    // Timer interrupts are not suggested, better to use DREQ interrupt!
    // but we don't have them on the 32u4 feather...
    musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int
#else
    // If DREQ is on an interrupt pin we can do background
    // audio playing
    musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT); // DREQ int
#endif
}

void BesAirSound::on_loop()
{
    if (musicPlayer.DREQFlag)
    {
        /* feed buffer when DREQ interrupt */
        musicPlayer.feedBuffer();
        musicPlayer.DREQFlag = false;
    }
}

char language[4] = "/ru";
void BesAirSound::queue_sound(const String &filename)
{
    if (sound_available)
    {
        char buf[100];
        sprintf(buf, "%s/%s", language, filename.c_str());
        Serial.println("Queueing file: " + String(buf));
        musicPlayer.startPlayingFile(buf);
    }
}

void BesAirSound::play_sound(const String &filename)
{
    if (sound_available)
    {
        char buf[100];
        sprintf(buf, "%s/%s", language, filename.c_str());
        Serial.println("Playing file: " + String(buf));
        musicPlayer.playFullFile(buf);
    }
}

void BesAirSound::change_language(const char *new_lang)
{
    language[1] = new_lang[0];
    language[2] = new_lang[1];
}
