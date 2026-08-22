# 🏠 IoT-Based Smart Home Automation

### Sensor-Based Automation and Remote Home Control using ESP8266/ESP32, Sinric Pro & Google Home

---

## 📌 Overview

The **IoT-Based Smart Home Automation System** is designed to control and monitor home appliances using both **automatic sensor-based control** and **remote voice/app-based control**.

The system combines sensors, microcontrollers, relay modules, and IoT services to provide convenient and intelligent control of electrical appliances.

Users can control appliances remotely through **Sinric Pro** and voice commands using **Google Home**.

---

## 🎯 Objectives

- Control home appliances remotely
- Automate appliances based on sensor conditions
- Monitor environmental conditions
- Enable voice-based appliance control
- Integrate the system with Google Home
- Provide a simple and low-cost IoT home automation solution

---

## ⚙️ Key Features

| Feature | Implementation |
|---|---|
| 💡 Appliance Control | Relay Module |
| 🌡️ Temperature Monitoring | DHT11 |
| ☀️ Light Detection | LDR |
| 📡 IoT Connectivity | ESP8266 / ESP32 |
| 📱 Remote Control | Sinric Pro |
| 🎙️ Voice Control | Google Home |
| 🤖 Automatic Control | Sensor-Based Logic |
| ⚡ Switching | Relay Module |

---

## 🔧 Hardware Components

- ESP8266 / ESP32
- Arduino UNO (if used)
- DHT11 Temperature & Humidity Sensor
- LDR Sensor
- Relay Module
- AC Bulb / Fan / Other Loads
- Power Supply
- Connecting Wires

---

## 💻 Software & Technologies

- Arduino IDE
- C/C++
- ESP8266 / ESP32
- Sinric Pro
- Google Home
- IoT
- Embedded Systems

---

## 🏠 Working Principle

The system provides two modes of operation:

### 1. 🤖 Automatic Sensor Control

Sensors continuously monitor the environment.

For example:

- LDR detects light intensity
- DHT11 measures temperature and humidity

Based on predefined conditions, the controller can automatically switch appliances through the relay module.

### 2. 📱 Remote & Voice Control

The ESP8266/ESP32 connects to the Internet and communicates with **Sinric Pro**.

Users can control connected appliances remotely and issue voice commands through **Google Home**.

---

## 🎙️ Voice Control

Example commands:

```text
"Hey Google, turn on the light."

"Hey Google, turn off the light."

"Hey Google, turn on the fan."

"Hey Google, turn off the fan."
