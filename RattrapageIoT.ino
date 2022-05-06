// /-------------------------\
// |         Imports         |
// \-------------------------/

#include "Wifi.h"
#include "WebServer.h"
#include "Adafruit.h"


void setup() {
  setupWifi();
  setupWebServer();
  setupAdafruitIO();
}

void loop() {
  loopWebServer();
  loopAdafruitIO();
}
