/*********************************************************************
 * @file  Apllication.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include <Wire.h>

#define DHTPIN 0 // D2 on Groove shield
#define DHTTYPE DHT11
#define GASPIN A0 // Analog pin for gas

Application::Application()
{
    myLed = nullptr;
    pmSensor = nullptr;
    dhtSensor = nullptr;
    gasSensor = nullptr;
    screen = nullptr;
}

Application::~Application()
{
    delete myLed;
    delete pmSensor;
    delete dhtSensor;
    delete gasSensor;
    delete screen;
}

void Application::init(void)
{
    // Start I2C
    Wire.begin();

    // Instantiate Modules
    myLed = new Led(LED_BUILTIN);
    pmSensor = new ParticulateSensor();
    dhtSensor = new TempHumSensor(DHTPIN, DHTTYPE);
    gasSensor = new GasSensor(GASPIN);
    screen = new OledScreen(128, 32);

    // Init module
    myLed->init();
    pmSensor->init();
    dhtSensor->init();
    gasSensor->init();
    screen->init();
}



void Application::run(void)
{
    myLed->toggle();
    pmSensor->read();
    dhtSensor->read();
    gasSensor->read();

    // Update Screen
    screen->updateInfo(
        dhtSensor->getHeatIndex(),
        dhtSensor->getHumidity(),
        pmSensor->getPM1(),
        pmSensor->getPM2_5(),
        pmSensor->getPM10(),
        gasSensor->getRatio()
    );

    delay(500);
}
