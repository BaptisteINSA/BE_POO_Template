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
    bool _state; // État interne

  public:
    /**
     * @brief Constructeur
     * @param pin : Le pin de la LED
     */
    Led(int pin);

    /**
     * @brief Destructeur
     */
    ~Led();

    /**
     * @brief Initialisation du hardware (pinMode)
     * @note Redéfinition de la méthode virtuelle pure
     */
    void init() override;

    /**
     * @brief Allume la LED
     */
    void on();

    /**
     * @brief Éteint la LED
     */
    void off();

    /**
     * @brief Inverse l'état de la LED
     */
    void toggle();
};

#endif
