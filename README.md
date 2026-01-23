# Projet AirSense

Jules Augereau
Baptiste Peyrot

Ce projet est une station de mesure de la qualité de l'air réalisée sur un microcontrôleur ESP8266. Elle affiche la température, l'humidité, le niveau de particules fines et la présence de gaz sur un écran OLED.

## 1. Matériel requis
* Carte NodeMCU 1.0 (ESP-12E Module)
* Shield Grove
* Capteurs : DHT11 (Temp/Hum), Capteur de Gaz (MQ), Capteur de particules (HM3301)
* Écran OLED I2C

## 2. Configuration de l'IDE Arduino
Avant de compiler :

1.  Installer les cartes ESP8266 dans le gestionnaire de cartes.
2.  Sélectionner le type de carte : **NodeMCU 1.0 (ESP-12E Module)**.
3.  Installer les bibliothèques suivantes via le "Gestionnaire de bibliothèques" :
    * Adafruit BusIO
    * Adafruit GFX Library
    * Adafruit SSD1306
    * Adafruit Unified Sensor
    * DHT sensor library
    * Grove - Laser PM2.5 Sensor HM3301 (Seeed)

## 3. Branchements
* Capteur Gaz : Port *A0
* Capteur DHT : Port D2
* Écran OLED & Capteur PM2.5 : Ports I2C
* LED : Utilisation de la LED interne (Built-in)

## 4. Compilation et Exécution
1.  Ouvrir le fichier AirSense.ino avec l'IDE Arduino
2.  Brancher la carte en USB
3.  Cliquer sur le bouton Téléverser
4.  Une fois le téléversement fini, l'écran OLED s'allume et affiche les valeurs. La LED bleu clignote

## 5. Interaction

* **Test Gaz :** Approchez un briquet (sans flamme) ou soufflez sur le capteur de gaz. L'écran affichera "DETECTED!" au lieu de "Safe".
* **Test Température/Humidité :** Soufflez de l'air chaud sur le capteur bleu (DHT) pour voir les valeurs changer sur la première ligne de l'écran.
* **Qualité de l'air :** Si le capteur détecte beaucoup de particules (poussière), l'indicateur passera de "GOOD" à "FAIR" ou "BAD".
