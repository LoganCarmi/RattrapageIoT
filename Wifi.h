// /-------------------------\
// |         Imports         |
// \-------------------------/

#include <WiFi.h>    // Wifi

// /-------------------------\
// |        Variables        |
// \-------------------------/

// pour la configuration de la Station
const char* Station_SSiD     = "Bbox-B2D877CB";      
const char* Station_PWD      = "pywa4awhixEEMPfDAk";

// Pour la configuration de l'Access Point
const char* AP_SSiD          = "RattrapageIoT";
const char* AP_PWD           = "Mdp123456";

// /-------------------------\
// |      Configuration      |
// \-------------------------/


void setupWifi() {
  WiFi.mode(WIFI_AP_STA);                       // Config carte mode Access Point + Station
  WiFi.softAP(AP_SSiD, AP_PWD);                 // Démarrage mode Access Point
  WiFi.begin(Station_SSiD, Station_PWD);        // Démarrage mode Station 
}
