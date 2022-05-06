
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

/************************* Configuration *************************************/
// Connexion Adafruit
#define IO_SERVER             "io.adafruit.com"
#define IO_SERVERPORT         1883
#define IO_USERNAME           "CarmiLog"                                // = Bluetooth DEVICE_NAME
#define IO_KEY                "aio_TtNw93SfVtCtwENHhHwzCx9dIAbP"        // Modifier pour mettre le sien
#define DEVICE_ID             1                                         // Modifier en fonction de quelle carte est branchée

// Feeds
#define FEED_EDS1       "/feeds/etatdesantec1"
#define FEED_EDS2       "/feeds/etatdesantec2"

// Frequence d'envoi des données
#define FEED_FREQ         5


/************************** Variables ****************************************/
// Instanciation du client WiFi qui servira à se connecter au broker Adafruit
WiFiClient client;
// Instanciation du client Adafruit avec les informations de connexion
Adafruit_MQTT_Client MyAdafruitMqtt(&client, IO_SERVER, IO_SERVERPORT, IO_USERNAME, IO_USERNAME, IO_KEY);
// Variable de stockage de la valeur du slider
String EDS1_Value;
String EDS2_Value;
extern String EDS;

/****************************** Feeds ****************************************/
// Création des Feed auxquels nous allons souscrire :

Adafruit_MQTT_Subscribe EDS1_feed = Adafruit_MQTT_Subscribe(&MyAdafruitMqtt, FEED_EDS1);
Adafruit_MQTT_Subscribe EDS2_feed = Adafruit_MQTT_Subscribe(&MyAdafruitMqtt, FEED_EDS2);

Adafruit_MQTT_Publish DefaultEDS1 = Adafruit_MQTT_Publish(&MyAdafruitMqtt, FEED_EDS1);
Adafruit_MQTT_Publish DefaultEDS2 = Adafruit_MQTT_Publish(&MyAdafruitMqtt, FEED_EDS2);

void passageEtatMalade() {
  
  if (WiFi.status() != WL_CONNECTED){setupWifi();}     // Vérification de la connexion WiFi
  
  if(DEVICE_ID == 1) {
    DefaultEDS1.publish("Malade");
  } else if (DEVICE_ID == 2) {
    DefaultEDS2.publish("Malade");
  } else {
    Serial.print("MAUVAIS ID PRESENT");
  }
  
}

void passageBonneSante() {
  
  if (WiFi.status() != WL_CONNECTED){setupWifi();}     // Vérification de la connexion WiFi
  
  if(DEVICE_ID == 1) {
    DefaultEDS1.publish("Bonne Sante");
  } else if (DEVICE_ID == 2) {
    DefaultEDS2.publish("Bonne Sante");
  } else {
    Serial.print("MAUVAIS ID PRESENT");
  }
  
}

void EDS1callback(char *data, uint16_t len) {
  if (!strcmp(data, "Malade")){
    DefaultEDS2.publish("Cas Contact");
    EDS = "Malade";
  }
  else if (!strcmp(data, "Cas Contact")) { 
    EDS = "Cas Contact";
  }
}

void EDS2callback(char *data, uint16_t len) {
  if (!strcmp(data, "Malade")){
    DefaultEDS1.publish("Cas Contact");
    EDS = "Malade";
  }
  else if (!strcmp(data, "Cas Contact")) { 
    EDS = "Cas Contact";
  }
}

void setupAdafruitIO() {

  if (WiFi.status() != WL_CONNECTED){setupWifi();}     // Vérification de la connexion WiFi

  passageBonneSante();

  if(DEVICE_ID == 1) {
    EDS2_feed.setCallback(EDS2callback);
  } else if (DEVICE_ID == 2) {
    EDS1_feed.setCallback(EDS1callback);
  } else {
    Serial.print("MAUVAIS ID PRESENT");
  }
  
  // Souscription aux FEEDs
  MyAdafruitMqtt.subscribe(&EDS1_feed);
  MyAdafruitMqtt.subscribe(&EDS2_feed);
}

void connectAdafruitIO() {
  if (MyAdafruitMqtt.connected()) { return; }                 
  
  int8_t ret;
  while ((ret = MyAdafruitMqtt.connect()) != 0) {              
     MyAdafruitMqtt.disconnect();                                  // Deconnexion pour être propre
     delay(10000);                                                 // On attend 10 secondes avant de retenter le coup
  }
}

void loopAdafruitIO() {
  connectAdafruitIO();
  MyAdafruitMqtt.processPackets(10000);
  if(! MyAdafruitMqtt.ping()) {
    MyAdafruitMqtt.disconnect();
  }
}
