/*********************************************************************
 * @file ParticulateSensor.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Particule Sensor
 *********************************************************************/
#ifndef PARTICULATESENSOR_H_
#define PARTICULATESENSOR_H_

#include "module.h"
#include <Seeed_HM330X.h>
#include <vector> // for STL 

using namespace std;

class ParticulateSensor : public Module
{
  private:
    HM330X _sensor;
    vector<uint8_t> buffer;
    uint16_t pm1;
    uint16_t pm2_5;
    uint16_t pm10;

    uint16_t readU16(int index);

  public:
    ParticulateSensor(); // I2C, no specific pin needed
    ~ParticulateSensor();

    void init() override;
    bool read(); // Returns true if read was successful

    uint16_t getPM1();
    uint16_t getPM2_5();
    uint16_t getPM10();
};

#endif