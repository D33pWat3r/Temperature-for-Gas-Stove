#include <Arduino.h>
#include <Wire.h>

#include <U8x8lib.h>
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display

#include "max6675.h"

MAX6675 thermocouple(D5, D8, D6); //SCLK, CS, MISO
  
void setup() {
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_r);
  
  u8x8.setInverseFont(1);
  u8x8.setCursor(0,0);u8x8.print("Ofentemperatur");
  u8x8.setInverseFont(0);  
  
  u8x8.drawString(0,3,"Celsius:");
  u8x8.drawString(0,6,"Fahrenheit:");
}

void loop() {
  
   u8x8.setCursor(9,4);u8x8.print(thermocouple.readCelsius());
   u8x8.setCursor(9,7);u8x8.print(thermocouple.readFahrenheit());
 
   delay(1000);
}
