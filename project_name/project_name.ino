/*********************************************************************
 * @file  project_name.ino
 * @author Jules Augereau & Baptiste Peyrot
 * @brief 
 *********************************************************************/
#include "Application.h"

Application app;

void setup()
{
    Serial.begin(115200);
    delay(100); 
    app.init();
}

void loop()
{
    app.run();
}