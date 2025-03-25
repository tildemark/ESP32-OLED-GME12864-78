#include <Arduino.h>      // Includes the Arduino core library for basic Arduino functions
#include <Wire.h>         // Includes the Wire library for I2C communication
#include <Adafruit_GFX.h> // Includes the Adafruit GFX library for graphics functions
#include <Adafruit_SH110X.h> // Includes the Adafruit SH110X library for the OLED display driver

// Defines the screen dimensions
#define SCREEN_WIDTH 128  // OLED display width in pixels
#define SCREEN_HEIGHT 64   // OLED display height in pixels
#define OLED_ADDR 0x3C    // I2C address of the OLED display (often 0x3C or 0x3D)

// Creates an instance of the Adafruit SH1106G display object
// The parameters are:
// - width of the display
// - height of the display
// - pointer to the Wire instance (for I2C)
// - reset pin (not used here, so -1)
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);  // Initializes serial communication at 115200 baud rate

  // Initializes the OLED display
  // The parameters are:
  // - I2C address of the display
  // - reset (true/false)
  if (!display.begin(OLED_ADDR, true)) {
    Serial.println("SH110X OLED not found"); // Prints an error message if the display doesn't initialize
    while (1)  // Infinite loop to stop the program if the display is not found
      ;
  }

  display.display(); // Clears the display and shows the Adafruit splashscreen
  delay(2000);       // Waits for 2000 milliseconds (2 seconds)

  // Draw a rectangle
  display.clearDisplay(); // Clears the display buffer
  display.drawRect(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1,
                   SH110X_WHITE); // Draws a rectangle outline
                                  // Parameters: x, y, width, height, color
  display.setTextSize(1);        // Sets the text size
  display.setTextColor(SH110X_WHITE); // Sets the text color
  display.setCursor(5, 10);      // Sets the cursor position for text
  display.println("Hello, World!!!!"); // Prints "Hello, World!!!!" to the display
  display.display();             // Displays the contents of the buffer on the OLED
  delay(2000);                   // Waits for 2000 milliseconds (2 seconds)
}

void loop() {
  // Clear the buffer
  display.clearDisplay(); // Clears the display buffer

  // Draw a simple line
  display.drawLine(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1,
                   SH110X_WHITE); // Draws a line
                                  // Parameters: x0, y0, x1, y1, color
  display.display();             // Displays the buffer on the OLED
  delay(1000);                   // Waits for 1000 milliseconds (1 second)

  // Draw a rectangle
  display.clearDisplay(); // Clears the display buffer
  display.drawRect(10, 10, 108, 44,
                   SH110X_WHITE); // Draws a rectangle outline
  display.display();             // Displays the buffer
  delay(1000);

  // Draw a filled rectangle.
  display.clearDisplay(); // Clears the display buffer
  display.fillRect(20, 20, 88, 24,
                   SH110X_WHITE); // Draws a filled rectangle
  display.display();             // Displays the buffer
  delay(1000);

  display.clearDisplay(); // Clears the display buffer
  display.drawRect(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1,
                   SH110X_WHITE); // Draws a rectangle outline
  display.setTextSize(1);        // Sets the text size
  display.setTextColor(SH110X_WHITE); // Sets the text color
  display.setCursor(5, 10);      // Sets the cursor position
  display.println("Hello, Worlds !!!!"); // Prints "Hello, Worlds !!!!"
  display.display();             // Displays the buffer
  delay(2000);                   // Waits for 2000 milliseconds (2 seconds)
}