# ARDUINO_BTCAR_WITH_FINGERPRINT_AUTH
# Arduino Bluetooth Car with Fingerprint Authentication

This project demonstrates a secure, Bluetooth-controlled smart car built using Arduino. It features **biometric authentication** with a fingerprint sensor, ensuring only authorized users can control the car via Bluetooth.

## 🚗 Features

- 🔒 **Fingerprint Authentication**  
  Only authorized fingerprints can unlock the car controls.

- 📱 **Bluetooth Control**  
  Control the car remotely using a smartphone app (via HC-05 Bluetooth module).

- ⚙️ **Motor Driver Integration**  
  Use of L298N Motor Driver for controlling car movement (forward, backward, left, right, stop).

- 💡 **Secure Startup**  
  The car remains locked until a valid fingerprint is scanned.

## 🛠️ Components Used

- Arduino UNO or Nano
- Fingerprint Sensor (R307 or similar)
- HC-05 Bluetooth Module
- L298N Motor Driver
- 2 DC Motors with Wheels
- 9V Battery or suitable power source
- Chassis, jumper wires, breadboard, etc.

## 🔌 Wiring Overview

| Component         | Arduino Pin |
|------------------|-------------|
| Fingerprint TX    | Pin 10      |
| Fingerprint RX    | Pin 11      |
| HC-05 TX          | Pin 0 (RX)  |
| HC-05 RX          | Pin 1 (TX)  |
| L298N IN1-IN4     | Pins 4, 5, 6, 7 |
| Enable Pins       | 5V (or PWM pins) |
| Servo (optional)  | Pin 9       |

*Adjust pins as per your design*

## 📱 Bluetooth App

You can use any serial Bluetooth terminal or design a custom Android app using MIT App Inventor.

### Command Mapping:
| Command | Action         |
|---------|----------------|
| F       | Move Forward   |
| B       | Move Backward  |
| L       | Turn Left      |
| R       | Turn Right     |
| S       | Stop           |

## 🧠 How It Works

1. System powers on and waits for valid fingerprint scan.
2. Once authenticated, it enables Bluetooth command control.
3. User sends directional commands via Bluetooth.
4. Car responds accordingly using motor driver.
