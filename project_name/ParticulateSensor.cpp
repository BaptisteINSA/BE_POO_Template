/*********************************************************************
 * @file ParticulateSensor.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Particule Sensor
 *********************************************************************/
#include "ParticulateSensor.h"

ParticulateSensor::ParticulateSensor() : Module(-1), _pm1(0), _pm2_5(0), _pm10(0) {}

ParticulateSensor::~ParticulateSensor() {}

void ParticulateSensor::init()
{
    // Sensor init requires Wire to be started externally or internally
    if (_sensor.init()) {
        Serial.println("HM330X init failed!");
    }
}

uint16_t ParticulateSensor::readU16(const uint8_t *data, uint8_t i)
{
    return ((uint16_t)data[i * 2] << 8) | data[i * 2 + 1];
}

bool ParticulateSensor::read()
{
    if (_sensor.read_sensor_value(_buf, 29)) {
        Serial.println("HM330X read failed!");
        return false;
    }
    // Parse Atmospheric environment (indices 5, 6, 7) [cite: 5, 6, 7]
    _pm1   = readU16(_buf, 5);
    _pm2_5 = readU16(_buf, 6);
    _pm10  = readU16(_buf, 7);
    return true;
}

uint16_t ParticulateSensor::getPM1() 
{
  return _pm1; 
}

uint16_t ParticulateSensor::getPM2_5() 
{
  return _pm2_5;
}

uint16_t ParticulateSensor::getPM10()  
{
  return _pm10;
}
