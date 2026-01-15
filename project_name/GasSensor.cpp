/*********************************************************************
 * @file GasSensor.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Gas
 *********************************************************************/
#include "GasSensor.h"

GasSensor::GasSensor(int pin) : Module(pin), volts(0.0), ratio(0.0) {}

GasSensor::~GasSensor() {}

void GasSensor::init()
{
    pinMode(pin, INPUT);
    status = true;
}

void GasSensor::read()
{
    int sensorValue = analogRead(pin);
    volts = (float)sensorValue / 1024 * 5.0;
    
    // Calculate RS gas and Ratio
    float RS_gas = (5.0 - volts) / volts;
    
    // R0 is 0.19 based on previous calibration
    ratio = RS_gas / 0.19; 
}

float GasSensor::getVolts() {
    return volts;
}

float GasSensor::getRatio() {
    return ratio;
}
