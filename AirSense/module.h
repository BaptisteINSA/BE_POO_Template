/*********************************************************************
 * @file module.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Interface générique pour tous les capteurs et actionneurs
 *********************************************************************/
#ifndef MODULE_H_
#define MODULE_H_

#include <Arduino.h>

class Module
{
  protected:
    int pin; // Le pin sur lequel le Module est branché
    bool status; // for use operator

  public:
    Module(int pin) : pin(pin), status(false) {}
    virtual ~Module() {}
    virtual void init() = 0;
    
    operator bool() const { // operator
        return status;
    }
};

#endif
