/*********************************************************************
 * @file DhtSensor.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Implémentation du module DHT
 *********************************************************************/
#include "DhtSensor.h"

DhtSensor::DhtSensor(int pin, int type) : Module(pin), _type(type)
{
    _dht = new DHT(pin, type);
}

DhtSensor::~DhtSensor()
{
    if (_dht != nullptr) {
        delete _dht;
    }
}

void DhtSensor::init()
{
    _dht->begin();
}

float DhtSensor::readHumidity()
{
    return _dht->readHumidity();
}

float DhtSensor::readTemperature()
{
    return _dht->readTemperature(false); // false -> Celsius
}

float DhtSensor::readHeatIndex()
{
    float h = readHumidity();
    float t = readTemperature();

    if (isnan(h) || isnan(t)) {
        return NAN;
    }
    
    // Calcul de l'indice de chaleur en Celsius (isFahrenheit = false)
    return _dht->computeHeatIndex(t, h, false);
}
