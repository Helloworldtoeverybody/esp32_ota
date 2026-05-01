#include <WiFi.h>
#include <HTTPClient.h>
#include <Update.h>
#include <WiFiClientSecure.h>

const char* ssid = "YOUR_HOTSPOT";
const char* password = "YOUR_PASS";

const char* firmwareURL =
"https://github.com/USER/REPO/releases/latest/download/firmware.bin";

void updateFirmware() {
  WiFiClientSecure client;
  client.setInsecure();  // ⚠️ easy mode (skip cert validation)

  HTTPClient http;
  http.begin(client, firmwareURL);

  int code = http.GET();

  if (code == HTTP_CODE_OK) {

    int len = http.getSize();
    WiFiClient *stream = http.getStreamPtr();

    if (Update.begin(len)) {
      size_t written = Update.writeStream(*stream);

      if (written == len) {
        Serial.println("Update successful!");
      }

      Update.end(true);
    }
  } else {
    Serial.printf("HTTP error: %d\n", code);
  }

  http.end();
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");

  updateFirmware();
}

void loop() {}
