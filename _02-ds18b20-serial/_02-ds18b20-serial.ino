// Simple DS18B20 Read to Serial

// Include the OneWire library
#include <OneWire.h>

// Include the Dallas Temperature library
#include <DallasTemperature.h>

// Setup the OneWire bus on Pin 2
OneWire bus(2);

// Setup DallasTemperature to work on the OneWire bus
DallasTemperature sensors(&bus);


void setup() {
  // Enable Serial output
  Serial.begin(9600);
  Serial.println("DS18B20 Serial");
  
  // Start the sensors
  sensors.begin();
}

void loop() {
  // Update the sensor readings
  sensors.requestTemperatures();
  
  // Read Temperature
  float temperature = sensors.getTempCByIndex(0);
  
  // Print the results
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("c");
  
  // Delay for 2 seconds between readings
  delay(2000);
}
