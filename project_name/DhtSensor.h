/*********************************************************************
 * @file DhtSensor.h
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Module de gestion du capteur DHT (Température et Humidité)
 *********************************************************************/
#ifndef DHTSENSOR_H_
#define DHTSENSOR_H_

#include "module.h"
#include <DHT.h>

/**
 * @class DhtSensor
 * @brief Classe gérant le capteur de température et d'humidité (DHT11)
 */
class DhtSensor : public Module
{
  private:
    DHT* _dht;   // Pointeur vers l'objet de la librairie DHT
    int _type;   // Type de capteur (DHT11, DHT22, etc.)

  public:
    /**
     * @brief Constructeur
     * @param pin : Le pin du capteur
     * @param type : Le type de capteur (par défaut DHT11)
     */
    DhtSensor(int pin, int type = DHT11);

    /**
     * @brief Destructeur
     */
    ~DhtSensor();

    /**
     * @brief Initialisation du capteur
     * @note Redéfinition de la méthode virtuelle pure
     */
    void init() override;

    /**
     * @brief Lit le taux d'humidité
     * @return L'humidité en pourcentage (ou NaN si erreur)
     */
    float readHumidity();

    /**
     * @brief Lit la température
     * @return La température en Celsius (ou NaN si erreur)
     */
    float readTemperature();

    /**
     * @brief Calcule l'indice de chaleur (ressenti)
     * @return La température ressentie en Celsius
     */
    float readHeatIndex();
};

#endif
