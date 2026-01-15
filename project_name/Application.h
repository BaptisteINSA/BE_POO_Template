/*********************************************************************
 * @file  Apllication.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "led.h"
#include "ParticulateSensor.h"
#include "TempHumSensor.h"
#include "GasSensor.h"
#include "OledScreen.h"

/**
  * @class Application
  * @brief Classe Application 
*/
class Application
{
  private :
    Led* myLed;
    ParticulateSensor* pmSensor;
    TempHumSensor* dhtSensor;
    GasSensor* gasSensor;
    OledScreen* screen;

  public :
    Application();
    ~Application();    
    void init(void);
    void run(void);
};

#endif
