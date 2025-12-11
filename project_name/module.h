/*********************************************************************
 * @file module.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Interface générique pour tous les capteurs et actionneurs
 *********************************************************************/
#ifndef MODULE_H_
#define MODULE_H_

#include <Arduino.h>

/**
 * @class Module
 * @brief Classe représentant un composant connecté
 */
class Module
{
  protected:
    int _pin; // Le pin sur lequel le Module est branché

  public:
    /**
     * @fn Module(int pin)
     * @brief Constructeur avec le pin
     */
    Module(int pin) : _pin(pin) {}

    /**
     * @fn ~Module()
     * @brief Destructeur virtuel
     */
    virtual ~Module() {}

    /**
     * @fn virtual void init()
     * @brief Méthode virtuelle : chaque Module doit définir son initialisation
     */
    virtual void init() = 0;
    
    // virtual void update() {} 
};

#endif
