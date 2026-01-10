/*********************************************************************
 * @file  Apllication.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include <Wire.h>

#define DHTPIN  0      // D2 on Groove shield
#define DHTTYPE DHT11
#define GASPIN  A0     // Analog pin for gas

Application::Application()
{
    myLed = nullptr;
    _pmSensor  = nullptr;
    _dhtSensor = nullptr;
    _gasSensor = nullptr;
    _screen    = nullptr;
}

Application::~Application()
{
    delete myLed;
    delete _pmSensor;
    delete _dhtSensor;
    delete _gasSensor;
    delete _screen;
}

void Application::init(void)
{
  myLed = new Led(LED_BUILTIN);
  myLed->init();

    Serial.println("System Initializing...");

    // Start I2C once
    Wire.begin();

    // Instantiate Modules
    _pmSensor  = new ParticulateSensor();
    _dhtSensor = new TempHumSensor(DHTPIN, DHTTYPE);
    _gasSensor = new GasSensor(GASPIN);
    _screen    = new OledScreen(128, 32);

    // Init Modules
    _pmSensor->init();
    _dhtSensor->init();
    _gasSensor->init();
    _screen->init();

    Serial.println("System Ready.");
}



void Application::run(void)
{
    myLed->toggle();
    // 1. Read Sensors
    _pmSensor->read();
    _dhtSensor->read();
    _gasSensor->read();

    // 2. Debug Output to Serial (Optional, but good for verification)
    Serial.print("T: "); Serial.print(_dhtSensor->getTemperature());
    Serial.print(" | PM2.5: "); Serial.println(_pmSensor->getPM2_5());

    // 3. Update Screen
    _screen->updateInfo(
        _dhtSensor->getHeatIndex(), // Display heat index as per original code [cite: 24]
        _dhtSensor->getHumidity(),
        _pmSensor->getPM1(),
        _pmSensor->getPM2_5(),
        _pmSensor->getPM10(),
        _gasSensor->getRatio()
    );

    delay(500);
}
