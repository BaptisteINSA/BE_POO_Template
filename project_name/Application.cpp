/*********************************************************************
 * @file  Apllication.cpp
 * @author Jules Augereau & Baptiste Peyrot
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

Application::Application()
{
  myLed = nullptr;
}

Application::~Application()
{
  if (myLed != nullptr)
  {
    delete myLed;
  }
}

void Application::init(void)
{
  myLed = new Led(LED_BUILTIN);
  myLed->init();
}

void Application::run(void)
{
  myLed->toggle();
  delay(500);
}
