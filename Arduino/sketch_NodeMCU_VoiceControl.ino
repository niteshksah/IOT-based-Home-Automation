#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif
#include <Arduino.h>
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32) || defined(ARDUINO_ARCH_RP2040)
#include <WiFi.h>
#endif
#include "SinricPro.h"
#include "SinricProSwitch.h"
#define WIFI_SSID "POCO C51"
#define WIFI_PASS "12345678"
#define APP_KEY "e3c4a688-5621-42ab-8605-f660dad95ffc"
#define APP_SECRET "2e1e2690-19d1-4d20-8592-8e1f634f60a4-6904a14e-e4a9-400b-8bc8-1c103a546f2c"
#define SWITCH_ID_1 "68135335dc4a25d5c3c0a786"
#define SWITCH_ID_2 "681cd741bddfc53e33f1f6d7"
#define RELAYPIN_1 5
#define RELAYPIN_2 4
#define BAUD_RATE 115200

bool onPowerState1 (const String &deviceld, bool &state) {
  Serial.printf("Light turned %s\n", state? "ON": "OFF");
  digitalWrite(RELAYPIN_1, state? HIGH: LOW);
  return true;
}

bool onPowerState2 (const String &deviceld, bool &state) {
  Serial.printf("Fan turned %s\n", state? "ON": "OFF");
  digitalWrite(RELAYPIN_2, state? HIGH: LOW);
  return true;
}

void setupWiFi() {
  Serial.println("\n[WiFi): Connecting...");
  #if defined(ESP8266)
  WiFi.setSleepMode (WIFI_NONE_SLEEP);
  WiFi.setAutoReconnect(true);
  #elif defined(ESP32)
  WiFi.setSleep(false);
  WiFi.setAutoReconnect(true);
  #endif
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(250);
  }
  Serial.printf("\n[WiFi]: Connected. IP Address: %s\n", WiFi.localIP().toString().c_str());
}

void setupSinricPro() {
  pinMode(RELAYPIN_1, OUTPUT);
  pinMode(RELAYPIN_2, OUTPUT);
  digitalWrite(RELAYPIN_1, LOW);
  digitalWrite(RELAYPIN_2, LOW);
  SinricProSwitch& mySwitch1 = SinricPro [SWITCH_ID_1];
  mySwitch1.onPowerState(onPowerState1);
  SinricProSwitch& mySwitch2 = SinricPro [SWITCH_ID_2];
  mySwitch2.onPowerState (onPowerState2);
  SinricPro.onConnected([]() {
    Serial.println("Connected to SinricPro");
  });
  SinricPro.onDisconnected ([] () {
    Serial.println("Disconnected from SinricPro");
  });
  SinricPro.begin(APP_KEY, APP_SECRET);
}

void setup() {
  Serial.begin(BAUD_RATE);
  Serial.println("\n\n--- Starting NodeMCU ---");
  setupWiFi();
  setupSinricPro();
}

void loop() {
  SinricPro.handle();
}