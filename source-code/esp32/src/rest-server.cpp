#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>
#include "rest-server.h"
#include "sound-player.h"

// Replace with your network credentials
const char *ssid = "BesAir";
const char *password = "BesAir200";

void BesAirWebserver::log(String msg)
{
  Serial.print("[Server] ");
  Serial.println(msg);
}

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void BesAirWebserver::on_setup()
{
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  uint wifiConnectionTries = 1;
  while (WiFi.status() != WL_CONNECTED)
  {
    BesAirWebserver::log("Connecting to WiFi (" + String(wifiConnectionTries) + ")");
    wifiConnectionTries++;
    BesAirSound::play_sound("wifi1.mp3");
    delay(100);
  }
  BesAirWebserver::log("Connected to " + String(ssid));

  BesAirSound::play_sound("wifi2.mp3");

  // Print ESP32 Local IP Address
  BesAirWebserver::log("IP address: " + WiFi.localIP().toString());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", "ESP32 webserver works. Use the /api endpoint"); });

  // API
  server.on("/api/alive", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    BesAirWebserver::log("Confirming connection");
    request->send_P(200, "json/application", "{}"); });

  server.on("/api/start", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    if (emergency == true)
    {
      request->send_P(500, "json/application", "{ \"status\": \"error\" }");
      return;
    }

    if (besnState == false)
    {
      BesAirWebserver::log("Turning ON");
      besnState = true;
      BesAirSound::queue_sound("active.mp3");
    }
    else
    {
      BesAirWebserver::log("Already ON");
    }
    request->send_P(200, "json/application", "{ \"state\": \"on\" }"); });

  server.on("/api/stop", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    if (emergency == true)
    {
      request->send_P(500, "json/application", "{ \"status\": \"error\" }");
      return;
    }

    if (!besnState) {
      BesAirWebserver::log("Already OFF");
    } else {
      BesAirWebserver::log("Turning OFF");
      besnState = false;
      BesAirSound::queue_sound("shutdown.mp3");
    }
    request->send_P(200, "json/application", "{ \"state\": \"off\" }"); });

  server.on("/api/state", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    String stateStr = besnState ? "on" : "off";
    String stateStrUpper = stateStr;
    stateStrUpper.toUpperCase();
    BesAirWebserver::log("Sending state " + stateStrUpper);
    String responseBody = "{ \"state\": \"";
    responseBody += stateStr;
    responseBody += "\" }";
    request->send_P(200, "json/application", responseBody.c_str()); });

  server.on("/api/language", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    String language = BesAirSound::get_language();
    String langUpper = String(language);
    langUpper.toUpperCase();
    BesAirWebserver::log("Sending language " + langUpper);
    request->send_P(200, "json/application", String{ "{ \"lang\": \"" + language + "\" }" }.c_str()); });

  server.on("/api/language", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    if (emergency == true)
    {
      request->send_P(500, "json/application", "{ \"status\": \"error\" }");
      return;
    }

    if (request->hasParam("lang", true))
    {
      String language = request->getParam("lang", true)->value();
      String langUpper = String(language);
      langUpper.toUpperCase();
      BesAirWebserver::log("Set language to " + langUpper);
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
    if (emergency == true)
    {
      request->send_P(500, "json/application", "{ \"status\": \"error\" }");
      return;
    }

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

  /**
   * Endpoint for emergency procedure
   */
  server.on("/api/alarm", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    if (emergency == true)
    {
      request->send_P(500, "json/application", "{ \"status\": \"error\" }");
      return;
    }

    BesAirSound::queue_sound("problem.mp3");
    emergency = true;
    request->send_P(200, "json/application", "{ \"status\": \"ok\" }"); });

  // Start server
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Private-Network", "true");
  server.begin();
}

const String BesAirWebserver::get_ip()
{
  return WiFi.localIP().toString();
}
