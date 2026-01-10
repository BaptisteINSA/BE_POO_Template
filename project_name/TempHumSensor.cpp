/*********************************************************************
 * @file DhtSensor.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module du capteur Temperature & Humidity (DHT)
 *********************************************************************/
#include "TempHumSensor.h"

TempHumSensor::TempHumSensor(int pin, uint8_t type) : Module(pin), _type(type)
{
    _dht = new DHT(pin, type);
    _temperature = 0.0;
    _humidity = 0.0;
}

TempHumSensor::~TempHumSensor()
{
    delete _dht;
}

void TempHumSensor::init()
{
    _dht->begin();
}

void TempHumSensor::read()
{
    float h = _dht->readHumidity();
    float t = _dht->readTemperature(); // Celsius by default

    // Validate reading
    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    _humidity = h;
    _temperature = t;
    _heatIndex = _dht->computeHeatIndex(t, h, false);
}

float TempHumSensor::getTemperature() 
{
    return _temperature;
}

float TempHumSensor::getHumidity()
{
    return _humidity;
}

float TempHumSensor::getHeatIndex()
{
    return _heatIndex;
}
