#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include <ArduinoOTA.h>

const char* ssid = "NIKITOS"; // NIKITOS
const char* password = "nikita1234"; // nikita1234


#ifndef FW_VERSION
#define FW_VERSION "dev"
#endif


void checkForOTA() {
  Serial.println("Checking for firmware update...");

  WiFiClient client;
  client.setTimeout(15000);

  httpUpdate.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);

String url = String("http://10.192.161.87:8080/firmware.bin") +
             "?t=" + String(millis());

  t_httpUpdate_return ret = httpUpdate.update(client, url, FW_VERSION);

  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("Update failed: %s\n",
        httpUpdate.getLastErrorString().c_str());
      break;

    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("No update available");
      break;

    case HTTP_UPDATE_OK:
      Serial.println("Update successful!");
      break;
  }
}


void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Booting ESP32...");
  Serial.printf("Firmware version: %s\n", FW_VERSION);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");

  delay(3000);

  Serial.println("Checking for firmware update...");
  checkForOTA();   
}

void loop() {
  delay(10000);
  checkForOTA();
}
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include <ArduinoOTA.h>

const char* ssid = "NIKITOS"; // NIKITOS
const char* password = "nikita1234"; // nikita1234


#ifndef FW_VERSION
#define FW_VERSION "dev"
#endif


void checkForOTA() {
  Serial.println("Checking for firmware update...");

  WiFiClient client;
  client.setTimeout(15000);

  httpUpdate.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);

  const char* url =
    "http://10.192.161.87:8080/firmware.bin";

  t_httpUpdate_return ret = httpUpdate.update(client, url, FW_VERSION);

  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("Update failed: %s\n",
        httpUpdate.getLastErrorString().c_str());
      break;

    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("No update available");
      break;

    case HTTP_UPDATE_OK:
      Serial.println("Update successful!");
      break;
  }
}


void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Booting ESP32...");
  Serial.printf("Firmware version: %s\n", FW_VERSION);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");

  delay(3000);

  Serial.println("Checking for firmware update...");
  checkForOTA();   
}

void loop() {
  delay(10000);
  checkForOTA();
}
