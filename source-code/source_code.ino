#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

#define dht_apin A0 // analog pin sensor is connected to
dht DHT;

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the lcd address to 0x27 for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);
  lcd.init();         // initialize the lcd
  lcd.backlight();    // turn on the lcd screen backlight
  delay(500);         // delay to let system boot
  lcd.setCursor(0, 0);
  lcd.print("Project 1: z");
  lcd.setCursor(0, 1);
  lcd.print("Weather Station");
  delay(4000);        // wait before accessing sensor
}

void loop() {
  // read data from dht11 sensor
  DHT.read11(dht_apin);

  // display data on lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print("C");

  delay(5000);  // wait 5 seconds before accessing sensor again.
}