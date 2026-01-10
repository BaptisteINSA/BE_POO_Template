/*********************************************************************
 * @file DhtOledScreen.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module OLED Screen
 *********************************************************************/
#include "OledScreen.h"

OledScreen::OledScreen(int width, int height) : Module(-1), _width(width), _height(height)
{
    // Address -1 passes to Wire lib default
    _display = new Adafruit_SSD1306(width, height, &Wire, -1);
}

OledScreen::~OledScreen()
{
    delete _display;
}

void OledScreen::init()
{
    // Address 0x3C for 128x32 [cite: 10]
    if (!_display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 allocation failed");
        for (;;);
    }
    _display->clearDisplay();
    _display->setTextColor(SSD1306_WHITE);
    _display->display();
}

void OledScreen::updateInfo(float temp, float hum, uint16_t pm1, uint16_t pm25, uint16_t pm10, float gasRatio)
{
    _display->clearDisplay();

    // --- Line 1: Temp & Humidity ---
    _display->setTextSize(1);
    
    _display->setCursor(0, 0);
    _display->print("T:");
    _display->print(temp, 1); // 1 decimal
    _display->print((char)247); // °
    _display->print("C");

    _display->setCursor(64, 0); // Middle of screen
    _display->print("H:");
    _display->print(hum, 0);
    _display->print("%");

    // --- Line 2: Particles ---
    _display->setCursor(0, 8);
    _display->print("P1:");
    _display->print(pm1);

    _display->setCursor(45, 8);
    _display->print("P2.5:");
    _display->print(pm25);

    _display->setCursor(95, 8);
    _display->print("P10:");
    _display->print(pm10);

    // --- Line 3: Gas Ratio ---
    _display->setCursor(0, 16);
    _display->print("Gas R:");
    _display->print(gasRatio);

    _display->display();
}