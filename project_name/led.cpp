/*********************************************************************
 * @file led.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module de gestion d'une LED
 *********************************************************************/
#include "Led.h"

Led::Led(int pin) : Module(pin), state(false) {}

Led::~Led()
{
    off();
}

void Led::init()
{
    pinMode(pin, OUTPUT);
    off();
    status = true;
}

void Led::on()
{
    digitalWrite(pin, HIGH);
    state = true;
}

void Led::off()
{
    digitalWrite(pin, LOW);
    state = false;
}

void Led::toggle()
{
    if (state) {
        off();
    } else {
        on();
    }
}
