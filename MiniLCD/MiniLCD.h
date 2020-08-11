#ifndef MiniLCD_h
#define MiniLCD_h

#include "Arduino.h"

class MiniLCD 
{
	public:
		MiniLCD(char address);
		void SendDataToController(char data);
		void SendDataToScreen(char data);
		void ClearScreen();
		
	private:
		void writeData(char controlByte, char data);
		byte Address; 
};

#endif