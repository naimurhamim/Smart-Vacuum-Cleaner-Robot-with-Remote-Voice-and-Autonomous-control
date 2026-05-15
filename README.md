<div align="center">

# 🧹 Smart Vacuum Cleaner Robot

![Robotics](https://img.shields.io/badge/Robotics-Vacuum%20Cleaner-9cf?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![NodeMCU](https://img.shields.io/badge/NodeMCU-ESP8266-blue?style=for-the-badge)
![Voice Control](https://img.shields.io/badge/Voice-Google%20Assistant-4285F4?style=for-the-badge&logo=googleassistant&logoColor=white)
![Autonomous](https://img.shields.io/badge/Autonomous-Navigation-green?style=for-the-badge)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**A versatile cleaning robot with three control modes — autonomous navigation, voice control via Google Assistant, and remote operation via Android app.**

</div>

---

## 📖 About

The **Smart Vacuum Cleaner Robot** is a multi-mode autonomous cleaning robot built with Arduino and NodeMCU (ESP8266). It combines three distinct control mechanisms into a single platform — making it adaptable for fully automatic, voice-controlled, or manually-guided cleaning.

The robot uses ultrasonic sensors for obstacle detection during autonomous mode, Google Assistant integration for voice commands, and Bluetooth for remote Android app control — all in one compact device.

---

## 🎮 Three Control Modes

### 🟢 Mode 1 — Autonomous Navigation
The robot navigates independently using ultrasonic sensors to detect and avoid obstacles in real time. It continuously cleans until stopped.

### 🔵 Mode 2 — Voice Control (Google Assistant)
Using the NodeMCU and IFTTT/Blynk integration, the robot responds to voice commands through **Google Assistant** on your phone.

> *"Hey Google, start cleaning"* → Robot begins autonomous cleaning  
> *"Hey Google, stop robot"* → Robot halts immediately

### 🟡 Mode 3 — Remote Control (Android App)
Controlled via a **Bluetooth Android app** — move forward, backward, left, right, and activate/stop the vacuum motor with on-screen buttons.

---

## ⚙️ System Architecture

```
                    ┌────────────────────────────────┐
                    │         Control Input           │
                    └─────┬──────────┬───────────────┘
                          │          │           │
               [Ultrasonic]  [Google Assistant] [Android App]
               (Autonomous)  (Voice via WiFi)   (Bluetooth)
                          │          │           │
                    ┌─────▼──────────▼───────────▼─────┐
                    │         Arduino + NodeMCU          │
                    └──────────────┬───────────────────┘
                                   │
              ┌────────────────────┼────────────────────┐
              │                    │                     │
         [DC Motors]          [Vacuum Motor]       [Servo Motor]
         (Movement)           (Suction Fan)        (Brush Head)
```

---

## ✨ Features

| Feature | Description |
|---|---|
| 🤖 **Autonomous Mode** | Obstacle detection & avoidance using ultrasonic sensors |
| 🎙️ **Voice Control** | Google Assistant commands via NodeMCU + IFTTT |
| 📱 **Android App Control** | Bluetooth remote control with custom Android app |
| 🔊 **Ultrasonic Sensing** | HC-SR04 for real-time distance measurement |
| 🌀 **Vacuum Motor** | Suction system for actual dirt collection |
| 🔄 **Mode Switching** | Seamlessly switch between all 3 control modes |
| ⚡ **Battery Powered** | Portable and rechargeable power system |

---

## 🧰 Hardware Components

| Component | Purpose |
|---|---|
| **Arduino Uno** | Main robot controller |
| **NodeMCU ESP8266** | WiFi for Google Assistant & voice control |
| **HC-SR04 Ultrasonic Sensor** | Obstacle detection in autonomous mode |
| **HC-05 Bluetooth Module** | Android app remote control |
| **L298N Motor Driver** | Controls DC wheel motors |
| **DC Motors (x2)** | Robot movement (differential drive) |
| **Vacuum/Fan Motor** | Suction and dirt collection |
| **Servo Motor** | Brush head movement |
| **Robot Chassis** | Physical frame with wheels |
| **Li-Po / 12V Battery** | Power supply |
| **Relay Module** | Vacuum motor on/off control |

---

## 🗂️ Repository Contents

```
Smart-Vacuum-Cleaner-Robot-with-Remote-Voice-and-Autonomous-control/
│
├── Smart_vaccume_cleaner_Code/
│   └── bluetooth_control_voice_obstacle__1_/
│       └── bluetooth_control_voice_obstacle__1_.ino   # Main Arduino code
│
├── nodemcu/
│   └── nodemcu_code/
│       └── nodemcu_code.ino                           # NodeMCU WiFi code
│
├── report.pdf                       # Full project report
├── report_presentation.pptx         # Project presentation slides
├── Contact_me.docx                  # Contact information
└── LICENSE
```

📄 **[View Project Report](report.pdf)**  
📊 **[View Presentation](report_presentation.pptx)**

---

## 🛠️ Setup Instructions

### Arduino Setup
1. Open `Smart_vaccume_cleaner_Code/` in **Arduino IDE**
2. Set **Board:** Arduino Uno, select correct **Port**
3. Upload the code ▶️

### NodeMCU Setup (Voice Control)
1. Open `nodemcu/nodemcu_code/` in **Arduino IDE**
2. Install **ESP8266 board** from Board Manager
3. Enter your **WiFi credentials** in the code
4. Set up **IFTTT** applet linked to Google Assistant
5. Set **Board:** NodeMCU 1.0, upload ▶️

### Android App Setup (Bluetooth Control)
1. Install **Bluetooth RC Controller** app (or similar) on Android
2. Pair **HC-05** Bluetooth module with your phone
3. Connect in the app and use joystick/buttons to control

---

## 📐 Autonomous Navigation Logic

| Distance Reading | Robot Action |
|---|---|
| `> 30 cm` | Move forward, vacuum ON |
| `15–30 cm` | Slow down, scan sides |
| `< 15 cm` | Stop, turn away from obstacle |
| `Object on left` | Turn right |
| `Object on right` | Turn left |
| `Object on both sides` | Reverse and re-navigate |

---

## 🔮 Future Improvements

- [ ] Mapping capability (room layout tracking)
- [ ] Scheduled cleaning with timer
- [ ] Dirt/dust bin full detection sensor
- [ ] SLAM (Simultaneous Localization and Mapping)
- [ ] Camera for visual navigation
- [ ] Multi-room auto-docking and charging

---

## 📄 License

Licensed under the **MIT License** — see [LICENSE](LICENSE) for details.

---

## 👨‍💻 Author

**MD Naimur Rashid**  
Department of Internet of Things and Robotics Engineering  
University of Frontier Technology, Bangladesh (UFTB)

[![GitHub](https://img.shields.io/badge/GitHub-naimurhamim-181717?style=for-the-badge&logo=github)](https://github.com/naimurhamim)

---

<div align="center">
  <i>⭐ Star this repo if you love smart robotics and automation!</i>
</div>
