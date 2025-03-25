# ESP32 OLED Display Connection Guide

This repository contains the necessary information and code to connect an ESP32 to a 1.3-inch OLED display (128x64 pixels) using the Arduino IDE.

## Table of Contents

- [ESP32 OLED Display Connection Guide](#esp32-oled-display-connection-guide)
  - [Table of Contents](#table-of-contents)
  - [Prerequisites](#prerequisites)
  - [Components](#components)
  - [Hardware Connection](#hardware-connection)
  - [Arduino Code](#arduino-code)

## Prerequisites

Before you begin, ensure you have the following installed and configured:

1.  **Arduino IDE:** Download and install the Arduino IDE from the official Arduino website ([https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)).
2.  **ESP32 Board Module:**
    * Open the Arduino IDE.
    * Go to `File` > `Preferences`.
    * In the "Additional Board Manager URLs" field, add the following URL: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`.
    * Click "OK".
    * Go to `Tools` > `Board` > `Boards Manager...`.
    * Search for "ESP32" and install the "esp32 by Espressif Systems" package.
    * Go to `Tools` > `Board` > `ESP32 Arduino` and select your ESP32 board.
3.  **Adafruit SH110X Library:**
    * In the Arduino IDE, go to `Sketch` > `Include Library` > `Manage Libraries...`.
    * Search for "Adafruit SH110X" and install the "Adafruit SH110X by Adafruit" library.
    * Also install the "Adafruit GFX Library" by Adafruit.

## Components

* **ESP32 (CH340C, USB Type C):** [Makerlab Electronics](https://www.makerlab-electronics.com/products/type-c-esp32-development-board-30-pins-38-pins?variant=43922035540159)
* **ESP32 Expansion Board (X0R7 Black):** [Makerlab Electronics](https://www.makerlab-electronics.com/products/expansion-board-for-30pin-38pin-esp32-development-board-terminal-block-type?_pos=1&_psq=esp32+expansion+board&_ss=e&_v=1.0)
* **OLED Display 1.3-inch White (128x64):** [Makerlab Electronics](https://www.makerlab-electronics.com/products/oled-0-96-128x64-i2c?_pos=1&_psq=oled+128&_ss=e&_v=1.0)
* **Breadboard:** [Makerlab Electronics](https://www.makerlab-electronics.com/) (Search for "breadboard")
* **Jumper wires (4 pcs, Male to Female):** [Makerlab Electronics](https://www.makerlab-electronics.com/) (Search for "jumper wires")


## Hardware Connection

1.  **Power Configuration:**
    * On the ESP32 expansion board, locate the yellow jumper.
    * Move the jumper from the 3.3V position to the 5V position. This will allow the OLED to receive 5v power.
2.  **Wiring:**
    * Place the OLED display on the breadboard.
    * Connect the following pins between the ESP32 expansion board and the OLED display:
        * ESP32 Expansion Board VCC to OLED VCC
        * ESP32 Expansion Board GND to OLED GND
        * ESP32 Expansion Board D21 to OLED SDA
        * ESP32 Expansion Board D22 to OLED SCL

## Arduino Code

```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);

    if (!display.begin(OLED_ADDR, true)) {
        Serial.println("SH110X OLED not found");
        while (1);
    }

    display.display();
    delay(2000);

    // Draw a rectangle
    display.clearDisplay();
    display.drawRect(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, SH110X_WHITE);
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(5, 10);
    display.println("Hello, World!!!!");
    display.display();
    delay(2000);
}

void loop() {
  // Clear the buffer
  display.clearDisplay();

  // Draw a simple line
  display.drawLine(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, SH110X_WHITE);
  display.display();
  delay(1000);

  // Draw a rectangle
  display.clearDisplay();
  display.drawRect(10, 10, 108, 44, SH110X_WHITE);
  display.display();
  delay(1000);

  //Draw a filled rectangle.
  display.clearDisplay();
  display.fillRect(20,20, 88,24, SH110X_WHITE);
  display.display();
  delay(1000);

  display.clearDisplay();
  display.drawRect(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, SH110X_WHITE);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(5, 10);
  display.println("Hello, World!!!!");
  display.display();
  delay(2000);
}