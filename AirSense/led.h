/*********************************************************************
 * @file led.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module de gestion d'une LED
 *********************************************************************/
#ifndef SIMPLELED_H_
#define SIMPLELED_H_

#include "module.h"

class Led : public Module
{
  private:
    bool state;

  public:
    Led(int pin);
    ~Led();
    void init() override;
    void on();
    void off();
    void toggle();
};

#endif
