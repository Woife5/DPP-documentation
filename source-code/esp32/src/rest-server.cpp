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

String appPrefix = "[WEB] ";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void BesAirWebserver::on_setup()
{
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  int wifiConnectionTries = 1;
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(appPrefix);
    Serial.print("Connecting to WiFi ");
    Serial.print("(");
    Serial.print(wifiConnectionTries);
    Serial.println(")");
    wifiConnectionTries++;
    BesAirSound::play_sound("wifi1.mp3");
  }
  Serial.print(appPrefix);
  Serial.print("Connected to ");
  Serial.print(ssid);
  Serial.println();

  BesAirSound::play_sound("wifi2.mp3");

  // Print ESP32 Local IP Address
  Serial.print(appPrefix);
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", "ESP32 webserver works. Use the /api endpoint"); });

  // API
  server.on("/api/alive", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    Serial.print(appPrefix);
    Serial.println("Confirming connection");
    request->send_P(200, "json/application", "{}"); });

  server.on("/api/start", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    Serial.print(appPrefix);
    if (besnState)
    {
      Serial.println("Already ON");
    }
    else
    {
      Serial.println("Turning ON");
      besnState = true;
      BesAirSound::queue_sound("ini2.mp3");
    }
    request->send_P(200, "json/application", "{ \"state\": \"on\" }"); });

  server.on("/api/stop", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    Serial.print(appPrefix);
    if (!besnState) {
      Serial.println("Already OFF");
    } else {
      Serial.println("Turning OFF");
      besnState = false;
      BesAirSound::queue_sound("shutdown.mp3");
    }
    request->send_P(200, "json/application", "{ \"state\": \"off\" }"); });

  server.on("/api/state", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    String stateStr = besnState ? "on" : "off";
    String stateStrUpper = stateStr;
    stateStrUpper.toUpperCase();
    Serial.print(appPrefix);
    Serial.print("Sending state ");
    Serial.println(stateStrUpper);
    String responseBody = "{ \"state\": \"";
    responseBody += stateStr;
    responseBody += "\" }";
    request->send_P(200, "json/application", responseBody.c_str()); });

  server.on("/api/language", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    Serial.print(appPrefix);
    Serial.print("Sending language ");
    String language = BesAirSound::get_language();
    String langUpper = String(language);
    langUpper.toUpperCase();
    Serial.println(langUpper);
    request->send_P(200, "json/application", String{ "{ \"lang\": \"" + language + "\" }" }.c_str()); });

  server.on("/api/language", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    if (request->hasParam("lang", true))
    {
      String language = request->getParam("lang", true)->value();
      Serial.print(appPrefix);
      Serial.print("Set language to ");
      String langUpper = String(language);
      langUpper.toUpperCase();
      Serial.println(langUpper);
      BesAirSound::change_language(language.c_str());
      BesAirSound::queue_sound("lang.mp3");
      String responseBody = "{ \"lang\": \"" + language + "\" }";
      request->send_P(200, "json/application", responseBody.c_str());
    }
    else
    {
      request->send_P(400, "json/application", "");
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
