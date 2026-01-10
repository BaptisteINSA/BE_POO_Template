/*********************************************************************
 * @file GasSensor.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Gas
 *********************************************************************/
#ifndef GASSENSOR_H_
#define GASSENSOR_H_

#include "module.h"

class GasSensor : public Module
{
  private:
    float _volts;
    float _ratio;

  public:
    GasSensor(int pin);
    ~GasSensor();

    void init() override;
    void read();

    float getVolts();
    float getRatio();
};

#endif