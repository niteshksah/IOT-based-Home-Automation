#include <DHT.h>
#define LDR_PIN A0 // LDR sensor connected to analog pin A0
#define DHT_PIN 2 // DHT11 sensor connected to digital pin 2
#define DHT_TYPE DHT11
#define LIGHT_RELAY 8 // Light relay connected to pin 8
#define FAN_RELAY 9 // Fan relay connected to pin 9
#define NODEMCU_LIGHT_STATUS 7 // Reads NodeMCU D7 (light priority signal)
#define NODEMCU_FAN_STATUS 6 // Reads NodeMCU D8 (fan priority signal)

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LIGHT_RELAY, OUTPUT);
  pinMode(FAN_RELAY, OUTPUT);
  pinMode(NODEMCU_LIGHT_STATUS, INPUT);
  pinMode(NODEMCU_FAN_STATUS, INPUT);
  digitalWrite(LIGHT_RELAY, LOW); // Initially OFF
  digitalWrite(FAN_RELAY, LOW); // Initially OFF
}

void loop() {
  bool lightPriority = digitalRead(NODEMCU_LIGHT_STATUS);
  bool fanPriority = digitalRead(NODEMCU_FAN_STATUS);
  int ldrValue = analogRead(LDR_PIN);
  
  Serial.print("LDR: "); Serial.println(ldrValue);
  
  if (!lightPriority) {
    if (ldrValue < 500) {
      digitalWrite(LIGHT_RELAY, HIGH); // Turn on light (it's dark)
    } else {
      digitalWrite(LIGHT_RELAY, LOW); // Turn off light
    }
  }
  
  float temperature = dht.readTemperature();
  Serial.print("Temp: "); Serial.println(temperature);
  
  if (!fanPriority) {
    if (temperature > 30.0) {
      digitalWrite(FAN_RELAY, HIGH); // Turn on fan (it's hot)
    } else {
      digitalWrite(FAN_RELAY, LOW); // Turn off fan
    }
  }
  
  delay(2000); // Wait before next reading
}