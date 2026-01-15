/*********************************************************************
 * @file DhtOledScreen.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module OLED Screen
 *********************************************************************/
#include "OledScreen.h"

OledScreen::OledScreen(int width, int height) : Module(-1), _width(width), _height(height)
{
    _display = new Adafruit_SSD1306(width, height, &Wire, -1);
}

OledScreen::~OledScreen()
{
    delete _display;
}

void OledScreen::init()
{
    // Address 0x3C for 128x32
    if (!_display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed");
        for (;;);
    }
    _display->clearDisplay();
    _display->setTextColor(SSD1306_WHITE);
    _display->display();
}

String OledScreen::getQualityLabel(uint16_t pm25)
{
    // seuils simplifiés OMS/Europe
    if (pm25 < 15) return "GOOD"; // Air pur
    if (pm25 < 45) return "FAIR"; // Moyen
    return "BAD!"; // Pollué
}

void OledScreen::updateInfo(float temp, float hum, uint16_t pm1, uint16_t pm25, uint16_t pm10, float gasRatio)
{
    _display->clearDisplay();

    // Line 1: Temp & Humidity
    _display->setTextSize(1);
    
    _display->setCursor(0, 0);
    _display->print("T:");
    _display->print(temp, 1); // 1 decimal
    _display->print((char)247); // °
    _display->print("C");

    _display->setCursor(64, 0);
    _display->print("H:");
    _display->print(hum, 0);
    _display->print("%");

    // Line 2: Particles (PM2.5 est le plus important)
    _display->setCursor(0, 12);
    _display->print("PM2.5: ");
    _display->print(pm25);
    _display->print("ug");

    // Affichage de la qualité globale à droite
    String quality = getQualityLabel(pm25);
    _display->setCursor(80, 12);
    _display->print(quality);

    // --Line 3: Gas Ratio
    _display->setCursor(0, 24);
    _display->print("Gas: ");
    if (gasRatio < 1.0) { 
        _display->print("DETECTED!"); 
    } else {
        _display->print("Safe");
    }

    _display->display();
}