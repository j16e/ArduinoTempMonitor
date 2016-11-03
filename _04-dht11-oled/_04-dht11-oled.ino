// DHT11 Read to 128x64 OLED Display

// Include the DHT library
#include <DHT.h>

// Setup the sensor on Pin 2
DHT sensor(2, DHT11);

// Include the U8glib Library
#include <U8glib.h>

// Configure the OLED Screen (I2C)
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST);

float temperature;
float humidity;
float heatIndex;
char temperatureString[6] = "-";
char humidityString[6] = "-";
char heatIndexString[6] = "-";

void draw(void) {
  // temp
  u8g.setFont(u8g_font_fur11);
  u8g.drawStr( 0, 14, "Temp:");
  u8g.drawStr( 80, 14, temperatureString);
  
  // Humidity
  u8g.drawStr( 0, 30, "Humidity:");
  u8g.drawStr( 80, 30, humidityString);

  // Feels Like
  u8g.drawStr( 0, 45, "Feels Like:");
  u8g.drawStr( 80, 45, heatIndexString . "c");
}

void setup() {
  // Start the sensor
  sensor.begin();
}

void loop() {
  // picture loop  
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // Read Temperature
  temperature = sensor.readTemperature();
  
  // Read Humidity
  humidity = sensor.readHumidity();
  
  // Compute Heat Index
  heatIndex = sensor.computeHeatIndex(temperature, humidity, false);
  
  dtostrf(temperature, 2, 2, temperatureString);
  dtostrf(humidity, 2, 2, humidityString);
  dtostrf(heatIndex, 2, 2, heatIndexString);
  
  // Delay for 2 seconds between readings
  delay(2000);
}
