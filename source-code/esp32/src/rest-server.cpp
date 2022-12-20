#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>

// Replace with your network credentials
const char *ssid = "Rathalin";
const char *password = "Besn2022";

// Besn state
bool besnOn = false;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// stores the content of the index.html file we want the webserver to send
extern const char index_html[] PROGMEM;

void on_setup()
{
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.print("Connected to ");
  Serial.print(ssid);
  Serial.println();

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", "ESP32 webserver works. Use the /api endpoint"); });

  // API
  server.on("/api/start", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    Serial.println("Starting Besn");
    besnOn = true;
    request->send_P(200, "json/application", "{ \"state\": \"on\" }"); });

  server.on("/api/stop", HTTP_POST, [](AsyncWebServerRequest *request)
            {
    Serial.println("Stoping Besn");
    besnOn = false;
    request->send_P(200, "json/application", "{ \"state\": \"off\" }"); });

  server.on("/api/state", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    Serial.println("Sending Besn state");
    String responseBody = "{ \"state\": \"";
    responseBody += besnOn ? "on" : "off";
    responseBody += "\" }";
    request->send_P(200, "json/application", responseBody.c_str()); });

  // Start server
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  server.begin();
}
