#ifndef Keypad_h
#define Keypad_h

#include "Arduino.h"

class Keypad 
{
	public:
		Keypad(int numCols, int numRows, int *cols, int *rows, char *buttonMap);
		char getButtonPressed();
	
	private:
		int NumberColumns;
		int NumberRows;
		
		int *Columns;
		int *Rows;
		char *ButtonMap;
		char LastButtonPressed = -1;
};

#endif