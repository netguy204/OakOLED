/*
 * OakOLED Example:
 *
 * This example allows a display to be controlled via the Particle APIs.
 *
 * The easiest way to interact with this is through the Oak Terminal:
 * http://digistu.mp/oakterm
 *
 * Start by calling the write function with a brief (< 16 characters) message.
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
  Particle.function("write", writeOLED);
  Particle.function("ypos", yposOLED);
  Particle.function("clear", clearOLED);
  oled.begin();

  for(uint16_t ii = 0; ii < OLED_BUFFER_SIZE; ++ii) {
    oled.buffer[ii] = 0x81;
  }
  oled.display();

  oled.setTextSize(1);
  oled.setTextColor(1);
  oled.setCursor(0, 0);
}

unsigned int ypos = 0;

int writeOLED(String command) {
  oled.println(command.c_str());
  oled.display();
  return 0;
}

int yposOLED(String command) {
  ypos = atoi(command.c_str());
  oled.setCursor(0, ypos);
  return 0;
}

int clearOLED(String command) {
  oled.clearDisplay();
  oled.display();
  return 0;
}


uint16_t x0 = 0;
void loop() {
  Particle.process();
  /*
  oled.clearDisplay();
  oled.drawLine(x0, 0, OLED_WIDTH / 2, OLED_HEIGHT / 2, 1);
  oled.display();
  x0 = (x0 + 1) % OLED_WIDTH;
  */
}