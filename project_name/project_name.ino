#include "Application.h"

#include "DHT.h" //DHT sensor library & Adafruit Unified Sensor: bilbliotheque du capteur de temperature et d'humidité
#define DHTPIN 0 // pin D2 sur la groove base shield
#define DHTTYPE DHT11 //modèle du capteur de temperature/humidité
DHT dht(DHTPIN, DHTTYPE);

Application myApplication;

void setup()
{
  // put your setup code here, to run once:
  
  myApplication.init();
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  
  //récupération des informations du DHT11 :
  delay(2000);
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
  float f = dht.readTemperature(false); // je veux pas lire en fahrenheit on est en france ici
  
  //debug en cas de problème avec le capteur
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(F("\n"));

  myApplication.run();
}
