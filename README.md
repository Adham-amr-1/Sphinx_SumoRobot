# 🤖 Sphinx Sumo Robot | Award-Winning Autonomous Combat Bot (Arduino Nano)

**Sphinx** is an autonomous **sumo robot** developed using the **Arduino Nano** microcontroller. It was engineered for real-world competitive robotics, employing obstacle detection, boundary avoidance, and aggressive combat tactics. The robot integrates ultrasonic and infrared sensors with DC motor control logic, making decisions in real time without the use of any real-time operating system (RTOS).

> 🥈 **2nd Place Winner** in a regional sumo robot competition — recognized for performance, speed, and autonomous strategy.

---

## 📌 Project Goals

- Build an autonomous sumo robot that competes effectively in a ring.
- Detect opponents using ultrasonic sensors.
- Avoid exiting the ring using infrared line sensors.
- Implement fast and reliable embedded control logic using Arduino C++.
- Maintain modular, easy-to-extend codebase for embedded robotics applications.

---

## 🚀 Key Features

| Feature                      | Description                                                                 |
|------------------------------|-----------------------------------------------------------------------------|
| ✅ Autonomous Combat Logic    | Detects and attacks opponents in real time.                                 |
| ✅ Boundary Detection         | Uses dual IR sensors to prevent falling out of the ring.                    |
| ✅ Efficient Motor Control    | Controls two DC motors via an L298N driver for movement and turning.        |
| ✅ Modular Arduino Codebase   | Clean and structured code for sensors, motors, and control flow.            |

---

## 🏆 Competition Achievement

> 🥈 **Second Place** in the [insert competition name/location if applicable]  
> Demonstrated strategic behavior, fast reaction time, and reliable sensor integration.

---

## 🔧 Hardware Components

| Component            | Description                                     |
|----------------------|-------------------------------------------------|
| **Microcontroller**  | Arduino Nano (ATmega328P @ 16 MHz)              |
| **Ultrasonic Sensor**| HC-SR04 — used for opponent detection           |
| **IR Sensors**       | 2× IR line sensors — detect arena boundaries    |
| **Motor Driver**     | L298N Dual H-Bridge — controls left/right motors|
| **DC Motors**        | 2× high-torque motors with differential control |
| **Chassis**          | Sumo robot frame (custom-built or pre-assembled)|
| **Power Supply**     | 3.7V Li-ion battery              |

---

## 📁 Project Structure

```
Sphinx_SumoRobot/
│
├── include/                  # Header files
│   ├── ultrasonic.h          # HC-SR04 sensor functions
│   ├── ir.h                  # Line sensor functions
│   ├── motor.h               # Motor control interface
│   └── macros.h              # Constants and macros
│
├── src/                      # Source files
│   ├── main.ino              # Main Arduino sketch
│   ├── ultrasonic.cpp        # Ultrasonic sensor logic
│   ├── ir.cpp                # IR sensor logic
│   └── motor.cpp             # Motor control implementation
│
├── Makefile (optional)       # For AVR CLI builds
└── README.md                 # Project documentation
```

---

## ⚙️ System Behavior

1. **Initialization**  
   - Sets up pins, timers, and sensors.
2. **Search Mode**  
   - Rotates in place scanning for an opponent with the ultrasonic sensor.
3. **Attack Mode**  
   - If an opponent is detected, the robot charges forward.
4. **Evade Mode**  
   - If a boundary is detected via IR sensors, the robot reverses and reorients.

---

## 🔨 Getting Started

### 1. Clone the repository
```bash
git clone https://github.com/Adham-amr-1/Sphinx_SumoRobot.git
cd Sphinx_SumoRobot
```

### 2. Open and upload
- Open `main.ino` using the Arduino IDE.
- Select **Board**: Arduino Nano.
- Select **Processor**: ATmega328P (Old Bootloader if needed).
- Select the appropriate **COM port**.
- Click **Upload**.

> ✅ No additional libraries required (fully based on native Arduino functions).

---

## 🧩 Future Improvements

- Add LCD display or LEDs for real-time debugging.
- Improve direction decisions using multi-angle ultrasonic sensing.
- Tune motor PWM values for more aggressive engagement.
- Introduce mode switch for test/debug vs. competition behavior.

---

## 📜 License

This project is licensed under the [MIT License](LICENSE). Feel free to reuse or adapt it with proper credit.

---

## 👤 Author

**Adham Amr**  
🏆 Embedded Systems Engineer | Competitive Robotics Developer  
🔗 [GitHub](https://github.com/Adham-amr-1) | [LinkedIn](https://www.linkedin.com/in/adhamamr1/)

---
