/*********************************************************************
 * @file DhtOledScreen.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module OLED Screen
 *********************************************************************/
#ifndef OLEDSCREEN_H_
#define OLEDSCREEN_H_

#include "module.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OledScreen : public Module
{
  private:
    Adafruit_SSD1306* _display;
    int _width;
    int _height;

  public:
    OledScreen(int width, int height);
    ~OledScreen();

    void init() override;
    
    // Updates the display with all relevant data
    void updateInfo(float temp, float hum, uint16_t pm1, uint16_t pm25, uint16_t pm10, float gasRatio);
};

#endif