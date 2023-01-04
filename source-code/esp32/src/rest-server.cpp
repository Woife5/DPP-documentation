#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>
#include "rest-server.h"
#include "sound-player.h"

using namespace BesAirWebserver;

// Replace with your network credentials
const char *ssid = "TheBois";
const char *password = "a1234567890";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void BesAirWebserver::on_setup()
{
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connecting to WiFi..");
    BesAirSound::play_sound("wifi1.mp3");
  }
  Serial.print("Connected to ");
  Serial.print(ssid);
  Serial.println();

  BesAirSound::play_sound("wifi2.mp3");

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", "ESP32 webserver works. Use the /api endpoint"); });

  // API
  server.on("/api/start", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    Serial.println("Besn activated");
    besnState = true;
    BesAirSound::queue_sound("ini2.mp3");
    request->send_P(200, "json/application", "{ \"state\": \"on\" }"); });

  server.on("/api/stop", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    Serial.println("Besn deactivated");
    besnState = false;
    BesAirSound::queue_sound("shutdown.mp3");
    request->send_P(200, "json/application", "{ \"state\": \"off\" }"); });

  server.on("/api/state", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    Serial.println("Sending Besn state");
    String responseBody = "{ \"state\": \"";
    responseBody += besnState ? "on" : "off";
    responseBody += "\" }";
    request->send_P(200, "json/application", responseBody.c_str()); });

  /**
   * Endpoint for changing the spoken language of BesAir®
   */
  server.on("/api/language", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    if (request->hasParam("lang", true))
    {
      String lang = request->getParam("lang", true)->value();
      BesAirSound::change_language(lang.c_str());
      BesAirSound::queue_sound("lang.mp3");
      request->send_P(200, "json/application", "{ \"status\": \"ok\" }");
    }
    else
    {
      request->send_P(400, "json/application", "{ \"status\": \"error\" }");
    } });

  /**
   * Endpoint for immediately queueing a sound file
   */
  server.on("/api/sound", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    if (request->hasParam("file", true))
    {
      String sound = request->getParam("file", true)->value();
      BesAirSound::queue_sound(sound.c_str());
      request->send_P(200, "json/application", "{ \"status\": \"ok\" }");
    }
    else
    {
      request->send_P(400, "json/application", "{ \"status\": \"error\" }");
    } });

  // Start server
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  server.begin();
}
