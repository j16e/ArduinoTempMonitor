// Simple DHT11 Read to Serial

// Include the DHT library
#include <DHT.h>

// Setup the sensor on Pin 2
DHT sensor(2, DHT11);


void setup() {
  // Enable Serial output
  Serial.begin(9600);
  Serial.println("DHT11 Serial");

  // Start the sensor
  sensor.begin();
}

void loop() {
  // Read Temperature
  float temperature = sensor.readTemperature();
  
  // Read Humidity
  float humidity = sensor.readHumidity();
  
  // Compute Heat Index
  float heatIndex = sensor.computeHeatIndex(temperature, humidity, false);
  
  // Print the results
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("c \tHumidity: ");
  Serial.print(humidity);
  Serial.print("% \tFeels Like: ");
  Serial.print(heatIndex);
  Serial.println("c");
  
  // Delay for 2 seconds between readings
  delay(2000);
}
