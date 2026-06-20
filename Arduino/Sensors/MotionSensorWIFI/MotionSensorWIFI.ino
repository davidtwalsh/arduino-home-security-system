#include <WiFi.h>
#include <HTTPClient.h>
#include "../../credentials.h"

const char* backendUrl = "http://10.0.0.215:8000/motion";

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() - start > 20000) {
      Serial.println();
      Serial.println("WiFi connection failed, restarting...");
      ESP.restart();
    }
  }

  Serial.println();
  Serial.print("WiFi connected, IP address: ");
  Serial.println(WiFi.localIP());

  delay(5000);
  sendMotionEvent();
}

void loop() {
  // Nothing to do repeatedly for this example.
}

void sendMotionEvent() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected, cannot send motion event");
    return;
  }

  HTTPClient http;
  http.begin(backendUrl);
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST("{}");

  Serial.print("POST ");
  Serial.print(backendUrl);
  Serial.print(" -> ");

  if (httpCode > 0) {
    Serial.print("HTTP ");
    Serial.print(httpCode);
    Serial.print(", response: ");
    Serial.println(http.getString());
  } else {
    Serial.print("failed, error: ");
    Serial.println(http.errorToString(httpCode));
  }

  http.end();
}
