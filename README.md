# 4-LED Scanner: Serial Speed Control & AVR Registers

📌 **Project Overview**

This project implements a 4-LED scanner (Knight Rider effect) using an Arduino Uno, four LEDs, and the Serial Monitor[cite: 1]. 

The scanner lights up one LED at a time sequentially from Pin 4 to Pin 7 and back[cite: 1]. Pin directions and states are controlled directly using AVR registers (`DDRD` and `PORTD`) instead of standard `pinMode()` and `digitalWrite()` functions[cite: 1]. Additionally, users can control the scanning speed in real-time by typing 'f' (faster) or 's' (slower) into the Serial Monitor[cite: 1].

🎯 **Objectives**

- Wire and control 4 LEDs connected to digital pins 4, 5, 6, and 7 on an Arduino Uno[cite: 1].
- Create a back-and-forth 4-LED scanner effect using standard delay/speed control[cite: 1].
- Configure pin directions using the `DDRD` register[cite: 1].
- Turn LEDs ON/OFF using the `PORTD` register[cite: 1].
- Read user input via `Serial.read()` to dynamically change speed[cite: 1].
- Print real-time updates (`"New Speed: X ms"`) back to the Serial Monitor using `Serial.println()`[cite: 1].

🛠️ **Components Required**

- Arduino Uno
- 4 × LEDs
- 4 × 220Ω Resistors
- Jumper Wires
- Breadboard

🔌 **Pin Configuration**

| Component | Arduino Pin | Register Bit |
| :--- | :--- | :--- |
| LED 1 | D4 | PD4 |
| LED 2 | D5 | PD5 |
| LED 3 | D6 | PD6 |
| LED 4 | D7 | PD7 |

⚙️ **Working Principle**

1. Pins 4, 5, 6, and 7 are configured as OUTPUT using the `DDRD` register.
2. Serial communication is initialized at 9600 baud.
3. The program loops through the LEDs sequentially (4 -> 5 -> 6 -> 7 -> 6 -> 5 -> ...) using `PORTD` register manipulation.
4. During each step, `Serial.available()` checks for incoming serial input.
5. Typing **'f'** decreases the delay (increases speed), while typing **'s'** increases the delay (decreases speed).
6. The new delay value is printed to the Serial Monitor.

💻 **Code**

The Arduino source code is available in `sketch.ino`.

🔗 **Simulation Links**

- Wokwi Simulation: https://wokwi.com/projects/480214609069874177

📚 **Registers Used**

- `DDRD` – Data Direction Register D
- `PORTD` – Port D Data Register

👩‍💻 **Project Information**

Platform: Arduino Uno[cite: 1]  
Simulator: Tinkercad / Wokwi[cite: 1]  
Project Type: Embedded Systems / Register Manipulation & Serial Communication  
Language: C++  

---
This project was developed as part of an Arduino Register Manipulation task.
