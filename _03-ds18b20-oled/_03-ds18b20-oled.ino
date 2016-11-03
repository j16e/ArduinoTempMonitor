// DS18B20 Read to 128x64 OLED Display

// Include the OneWire library
#include <OneWire.h>

// Include the Dallas Temperature library
#include <DallasTemperature.h>

// Setup the OneWire bus on Pin 2
OneWire bus(2);

// Setup DallasTemperature to work on the OneWire bus
DallasTemperature sensors(&bus);

// Include the U8glib Library
#include <U8glib.h>

// Configure the OLED Screen (I2C)
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST);

float temperature;
char temperatureString[6] = "-";

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_fur11);
  u8g.drawStr( 0, 22, "Temp:");
  u8g.setFont(u8g_font_fub25);
  u8g.drawStr( 0, 54, temperatureString);
}

void setup() {
  // Start the sensors
  sensors.begin();
}

void loop() {
  // picture loop  
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // Update the sensor readings
  sensors.requestTemperatures();
  
  // Read Temperature
  temperature = sensors.getTempCByIndex(0);
  dtostrf(temperature, 2, 2, temperatureString);
  
  // Delay for 2 seconds between readings
  delay(2000);
}
