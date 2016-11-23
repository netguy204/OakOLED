/*
 * OakOLED Example:
 *
 * Displays "hello, world" in true programmer fashion.
 *
 */

#include "Wire.h"
#include "Adafruit_GFX.h"
#include "OakOLED.h"


/////// GLOBALS //////

OakOLED oled;

///////////////////////

void setup() {
  Serial.begin(115200);
  oled.begin();

  oled.setTextSize(1);
  oled.setTextColor(1);
  oled.setCursor(0, 0);

  oled.println("hello, world!");
  oled.display();
}

void loop() {

}