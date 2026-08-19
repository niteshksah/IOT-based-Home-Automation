# IoT-Based Voice-Activated Home Automation System

**Institution:** Sir M Visvesvaraya Institute of Technology, Department of Electrical and Electronics Engineering  
**Course:** Arduino Project Report (BEEL456D), Sem: IV, Sec: A (AY: 2024-25)  
**Objective:** To develop skills required to build IoT based projects.

## Abstract
This project presents a Voice-Controlled Home Automation System using an ESP8266 Wi-Fi module (NodeMCU), a DHT11 temperature sensor, and an LDR light sensor. The system enables voice-based control of household appliances like fans and lights by a smartphone app with voice assistant integration. The ESP8266 connects to Wi-Fi and controls relays to turn on/off devices based on voice commands. The DHT11 monitors temperature, while the LDR detects light levels to automate appliance control. 

## Features & Working Logic

1. **Voice-Based Control (NodeMCU):**
   * Flow: Google Assistant → Sinric Pro → NodeMCU.
   * The NodeMCU sends serial commands (e.g., "FAN ON" or "LIGHT_OFF") to the Arduino.
   * NodeMCU sets control mode to manual override, disabling sensor control.
   * Relay CH1 and CH3 switch ON/OFF as per the voice command.

2. **Sensor-Based Automatic Control (Arduino):**
   * When no voice command is given, the Arduino controls the appliances.
   * **Fan:** Turns ON if the temperature > **30°C**.
   * **Light:** Turns ON if the ambient light falls below the threshold.
   * Uses Relay CH2 and CH4.

3. **Priority Handling:**
   * Voice commands override sensor decisions. 
   * If a voice command is given, Arduino sets `manualFanControl = true` or `manualLightControl = true`, keeping appliances in their commanded state regardless of sensor readings.
   * Commands like "FAN AUTO" reset the system back to automatic sensor mode.

## Hardware Requirements & Cost

| Component                      | Cost (INR) 
| :---                           | :--- 
| Arduino Uno                    | 550 
| NodeMCU ESP8266                | 200 
| 4-Channel Relay Module (5V)    | 150 
| DHT11 Temperature Sensor       | 80 
| LDR (Light Dependent Resistor) | 10 
| 10k Ohm Resistor               | 2 
| Breadboard + Jumper Wires      | 150 
| AC Bulb and Holder             | 50 
| AC Fan (220v)                  | 200 
| **Total Estimated Cost**       | 1400

*Relay Channel Assignment:*
* **CH1:** Light (Voice control via NodeMCU)
* **CH2:** Light (Sensor-based via Arduino)
* **CH3:** Fan (Voice control via NodeMCU)
* **CH4:** Fan (Sensor-based via Arduino)

## Team Members
* Astitwa Singh (1MV23EE011)
* Manohar Kumar (1MV23EE034)
* Mayank Kumar (1MV23EE035)
* Nitesh Kumar Sah (1MV23EE046)