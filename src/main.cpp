#include <Arduino.h>

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
  display.println("Hello, Worlds !!!!");
  display.display();
  delay(2000);
}