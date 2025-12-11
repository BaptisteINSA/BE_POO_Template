/*********************************************************************
 * @file led.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module de gestion d'une LED
 *********************************************************************/
#include "Led.h"

Led::Led(int pin) : Module(pin), _state(false) {}

Led::~Led()
{
    off();
}

void Led::init()
{
    pinMode(_pin, OUTPUT);
    off();
}

void Led::on()
{
    digitalWrite(_pin, HIGH);
    _state = true;
}

void Led::off()
{
    digitalWrite(_pin, LOW);
    _state = false;
}

void Led::toggle()
{
    if (_state) {
        off();
    } else {
        on();
    }
}
