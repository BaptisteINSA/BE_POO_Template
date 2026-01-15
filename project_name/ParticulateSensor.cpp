/*********************************************************************
 * @file ParticulateSensor.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Particule Sensor
 *********************************************************************/
#include "ParticulateSensor.h"

ParticulateSensor::ParticulateSensor() : Module(-1), pm1(0), pm2_5(0), pm10(0) {
    buffer.resize(30);
}

ParticulateSensor::~ParticulateSensor() {}

void ParticulateSensor::init()
{
    if (_sensor.init()) {
        status = false;
        Serial.println("HM330X init failed!");
    }
    status = true;
}

uint16_t ParticulateSensor::readU16(int index)
{
    return ((uint16_t)buffer[index * 2] << 8) | buffer[index * 2 + 1];
}

bool ParticulateSensor::read()
{
    if (_sensor.read_sensor_value(buffer.data(), 29)) {
        Serial.println("HM330X read failed!");
        return false;
    }
    // Parse Atmospheric environment
    pm1 = readU16(5);
    pm2_5 = readU16(6);
    pm10 = readU16(7);
    return true;
}

uint16_t ParticulateSensor::getPM1() 
{
  return pm1; 
}

uint16_t ParticulateSensor::getPM2_5() 
{
  return pm2_5;
}

uint16_t ParticulateSensor::getPM10()  
{
  return pm10;
}
