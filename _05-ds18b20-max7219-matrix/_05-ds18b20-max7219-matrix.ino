// Include the OneWire library
#include <OneWire.h>

// Include the Dallas Temperature library
#include <DallasTemperature.h>

// Setup the OneWire bus on Pin 2
OneWire bus(2);

// Setup DallasTemperature to work on the OneWire bus
DallasTemperature sensors(&bus);


#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 4;
int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String message = String("Current Temperature: ");
int wait = 30; // In milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels

void setup() {

  matrix.setIntensity(2); // Use a value between 0 and 15 for brightness

  matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
  matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
  matrix.setPosition(2, 2, 0); // The third display is at <2, 0>
  matrix.setPosition(3, 3, 0); // And the last display is at <3, 0>

  matrix.setRotation(0, 1);
  matrix.setRotation(1, 1);
  matrix.setRotation(2, 1);
  matrix.setRotation(3, 1);

  // Start the sensors
  sensors.begin();
}

void loop() {

  // Update the sensor readings
  sensors.requestTemperatures();
  
  // Read Temperature
  float temperature = sensors.getTempCByIndex(0);

  String tape = message + temperature + "c";

  for ( int i = 0 ; i < width * tape.length() + matrix.width() - 1 - spacer; i++ ) {

    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically

    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < tape.length() ) {
        matrix.drawChar(x, y, tape.charAt(letter), HIGH, LOW, 1);
      }

      letter--;
      x -= width;
    }

    matrix.write(); // Send bitmap to display

    delay(wait);
  }
}

