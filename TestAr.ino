/*
 Name:		TestAr.ino
 Created:	13.11.2018 17:14:10
 Author:	Виталий
*/

#include <SPI.h>
#include <Ethernet.h>
#include <Arduino.h>
#include "Rov.h"

Rov rov;

void setup()
{
	rov.init();
}

void loop() 
{
	rov.run();
}
