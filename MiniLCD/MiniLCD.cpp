#include "Arduino.h"
#include <Wire.h>
#include "MiniLCD.h"

MiniLCD::MiniLCD(char address)
{
	Address = address; 
	
	Wire.begin();

	delay(50);
	
	SendDataToController(0b00111000); // function set

	SendDataToController(0b00111001); // function set

	SendDataToController(0b00010100); // osc frequency 

	SendDataToController(0b01110000); //contrast set, 0b01110000 

	SendDataToController(0b01010110); // power/contrast, 0b01010110 

	SendDataToController(0b01101100); // follower control

	delay(200);

	SendDataToController(0b00111000); // function set 

	SendDataToController(0b00001100); // display on/off

	SendDataToController(0b00000001); // clear display

	delay(2);
}


void MiniLCD::writeData(char controlByte, char data)
{
	Wire.beginTransmission(Address);

	Wire.write(controlByte);

	Wire.write(data);

	Wire.endTransmission();
}

void MiniLCD::SendDataToController(char data)
{
	writeData(0b00000000, data);
}

void MiniLCD::SendDataToScreen(char data)
{
	writeData(0b01000000, data);
}

void MiniLCD::ClearScreen()
{
	SendDataToController(0b00000001);
}
