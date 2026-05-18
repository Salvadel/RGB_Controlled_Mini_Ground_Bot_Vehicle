<h1 align="center">RGB Controlled Mini Ground Bot Vehicle</h1>

<p align="center">
An Arduino-based autonomous mini robot that uses RGB color detection and ultrasonic sensing to navigate and respond to environmental input in real time.
</p>

## Overview

This project is a compact embedded systems robot built on an Arduino platform. It demonstrates real-time sensor fusion, decision-making logic, and actuator control in a mobile robotic system.

The bot interprets **colored input cards** using a custom RGB sensor module. Each detected color maps to a specific movement command:

- Forward  
- Reverse  
- Left  
- Right  
- Stop  

In addition to color-based control, the system includes an ultrasonic sensor for obstacle detection. If an object is detected within a predefined threshold distance, the bot automatically halts to prevent collisions.

This creates a hybrid control system combining:
- **Manual-like command input (RGB cards)**
- **Autonomous safety override (ultrasonic sensing)**

## Key Features

- RGB-based color recognition for command input
- Custom mapping of colors to movement instructions
- Ultrasonic obstacle detection and automatic stop behavior
- Real-time decision-making loop
- Servo-driven movement system
- Embedded C++ logic via Arduino IDE

## Hardware Components

- Arduino UNO R4 Microcontroller Board
- Custom RGB Light Sensor Module
- Ultrasonic Distance Sensor (HC-SR04 or equivalent)
- Servo Motors (continuous rotation / modified continuous servos)
- Chassis and wheel assembly
- External power supply

## Software / Tools

- Arduino IDE
- C++ (Arduino framework)

## System Behavior

1. RGB sensor reads reflected light from colored cards
2. Color value is processed and mapped to a movement command
3. Arduino sends signals to servo motors
4. Ultrasonic sensor continuously monitors distance
5. If an obstacle is detected within range:
   - Movement is overridden
   - Bot enters STOP state
6. System resumes once path is clear

## Program Walkthrough

### Wiring & Sensor Setup

<p align="center">
  <img src="https://i.imgur.com/fb9UuzN.jpeg" width="80%" alt="RGB sensor wiring diagram">
</p>

### Base Robot Platform (Pre-Sensor Integration)

<p align="center">
  <img src="https://i.imgur.com/nZKINic.jpeg" width="80%">
</p>

<p align="center">
  <img src="https://i.imgur.com/GGJQIzz.jpeg" width="80%">
</p>

<p align="center">
  <img src="https://i.imgur.com/MdL4lTe.jpeg" width="80%">
</p>

## Engineering Concepts Demonstrated

- Embedded systems programming
- Sensor fusion (RGB + ultrasonic)
- Real-time control loops
- Hardware-software integration
- Actuator control via PWM signals
- State-based decision logic

## Future Improvements

- Replace RGB sensor with calibrated TCS34725 module for higher accuracy
- Add wireless control (Bluetooth or RF module)
- Implement path memory / mapping behavior
- Upgrade to PID-controlled movement stability
- Add LED status feedback system (system state indicator)
- Improve chassis for better torque and stability

## Notes

This project is intended for educational purposes to demonstrate embedded systems design, sensor integration, and robotic control logic using Arduino hardware.
