#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>

// Replace with your network credentials
const char* ssid = "Rathalin";
const char* password = "???";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// stores the content of the index.html file we want the webserver to send
extern const char index_html[] PROGMEM;

void setup() {
  // Serial port for debugging purposes
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send_P(200, "text/html", "ESP32 webserver works. Use the /api endpoint");
  });

  // API
  server.on("/api/start", HTTP_POST, [](AsyncWebServerRequest* request) {
    Serial.println("Starting Besn");
    request->send_P(200, "json/application", "{ state: \"on\" }");
  });

  server.on("/api/stop", HTTP_POST, [](AsyncWebServerRequest* request) {
    Serial.println("Stoping Besn");
    request->send_P(200, "json/application", "{ state: \"off\" }");
  });

  // Start server
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  server.begin();
}

void loop() {
}
