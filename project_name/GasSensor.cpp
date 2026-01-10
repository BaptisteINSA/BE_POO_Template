/*********************************************************************
 * @file GasSensor.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Gas
 *********************************************************************/
#include "GasSensor.h"

GasSensor::GasSensor(int pin) : Module(pin), _volts(0.0), _ratio(0.0) {}

GasSensor::~GasSensor() {}

void GasSensor::init()
{
    pinMode(_pin, INPUT);
}

void GasSensor::read()
{
    int sensorValue = analogRead(_pin);
    _volts = (float)sensorValue / 1024 * 5.0;
    
    // Calculate RS gas and Ratio
    float RS_gas = (5.0 - _volts) / _volts;
    
    // R0 is 0.19 based on previous calibration
    _ratio = RS_gas / 0.19; 
}

float GasSensor::getVolts() {
    return _volts;
}

float GasSensor::getRatio() {
    return _ratio;
}
