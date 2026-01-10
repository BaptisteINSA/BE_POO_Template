/*********************************************************************
 * @file ParticulateSensor.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Particule Sensor
 *********************************************************************/
#ifndef PARTICULATESENSOR_H_
#define PARTICULATESENSOR_H_

#include "module.h"
#include <Seeed_HM330X.h>

class ParticulateSensor : public Module
{
  private:
    HM330X _sensor;
    uint8_t _buf[30];
    uint16_t _pm1;
    uint16_t _pm2_5;
    uint16_t _pm10;

    // Helper to extract data from buffer
    uint16_t readU16(const uint8_t *data, uint8_t i);

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