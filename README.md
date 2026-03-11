# embedded ultrasonic liquid level monitor
This project implements an embedded ultrasonic liquid level monitoring system with an LCD interface. The system measures the distance from the sensor to the liquid surface and converts this measurement into a calibrated percentage fill level.

Real-time distance and level data are displayed on a 16x2 LCD interface, and a four-stage LED indicator provides visual feedback corresponding to the tank fill level. 

## Features
- Ultrasonic time-of-flight distance measurement
- Real-time distance display on LCD
- Percentage fill level calculation using calibrated full and empty distances
- Four-stage LED level indicator
- Blinking low-level warning indicator

## Hardware Used
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- 16x2 I2C LCD Display
- LEDs with resistors
- Breadboard and jumper wires

## System Operation
1) The ultrasonic sensor measures the distance to the liquid surface.
2) The microcontroller converts this distance into a percentage fill level using calibrated full and empty reference measurements.
3) Distance and level values are displayed on the LCD screen.
4) LED indicators provide visual feedback for fill levels:
   - 0-25% blinking red LED
   - 25-50% 2 LEDs active
   - 50-75% 3 LEDs active
   - 75-100% 4 LEDs active

## Images

### System Setup
![image alt](https://github.com/johnathantobar-gif/embedded-ultrasonic-liquid-level-monitor/blob/0a03818f373f145a1d41fbc68a321543220ea9d2/Project%20photo%203.jpeg)
![image alt](https://github.com/johnathantobar-gif/embedded-ultrasonic-liquid-level-monitor/blob/bf79a983af862f30a801693130622c0d269da597/Project%20photo%202.jpeg)
### LCD Display
![LCD Output](images/lcd_display.jpg)

### LED Level Indicator 
![LED Indicator](images/led_indicator.jpg)

## Demo Video 
[Project Demonstration](video/demo.mp4

## Code
The project firmware is written in C++ using the Arduino framework.
The code performs ultrasonic measurement, calibration-based level calculation, LCD display control, and LED threshold logic.

## Author
**Jonathan Tobar**
Electrical Engineering Student

