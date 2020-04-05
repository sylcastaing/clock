#include <ESP8266WiFi.h>

#include <time/ClockTime.h>
#include <wifi/ClockWifi.h>
#include <display/ClockDisplay.h>

boolean initialized = false;

void setup() {
  Serial.begin(9600);

  delay(10);

  initDisplay();

  initWifi();
  initTime();

  initialized = true;
}

int oldHours = 0;
int oldMinutes = 0;

void loop() {
  if (initialized) {
    int newHours = getHours();
    int newMinutes = getMinutes();

    if (newHours != oldHours || newMinutes != oldMinutes) {
      oldHours = newHours;
      oldMinutes = newMinutes;

      displayTime(newHours, newMinutes);
    }

    delay(500);
  }
}