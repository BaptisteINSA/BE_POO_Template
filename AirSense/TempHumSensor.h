/*********************************************************************
 * @file DhtSensor.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Temperature & Humidity (DHT)
 *********************************************************************/
#ifndef TEMPHUMSENSOR_H_
#define TEMPHUMSENSOR_H_

#include "module.h"
#include <DHT.h>

class TempHumSensor : public Module
{
  private:
    DHT* _dht;
    uint8_t _type;
    float _temperature;
    float _humidity;
    float _heatIndex;

  public:
    TempHumSensor(int pin, uint8_t type);
    ~TempHumSensor();
    void init() override;
    void read();
    float getTemperature();
    float getHumidity();
    float getHeatIndex();
};

#endif