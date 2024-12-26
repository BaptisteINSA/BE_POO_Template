/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include <Arduino.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

Application::Application()
{
  // Code
  ; 
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
    // Parametrage de l'objet LCD (16X2)
    lcd.begin(16, 2);

    // Affichge de test
    lcd.print("| Project Name |");
    lcd.setCursor(0, 1);
    lcd.print("|Wede|Dece|2024|");

    delay(1000);
}


void Application::run(void)
{
    delay(100);
}
