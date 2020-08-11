#include "Arduino.h"
#include "Keypad.h"

Keypad::Keypad(int numCols, int numRows, int *cols, int *rows, char *buttonMap)
{
	NumberColumns = numCols;
	NumberRows = numRows;
	
	Columns = cols;
	Rows = rows; 
	
	ButtonMap = buttonMap;
	
	for (int row; row < NumberRows; row++)
	{
		pinMode(Rows[row], INPUT_PULLUP);
	}
	
	for (int column; column < NumberColumns; column++)
	{
		pinMode(Columns[column], OUTPUT);
	}
	
	Serial.begin(9600);
}

char Keypad::getButtonPressed()
{
	char buttonPressed = -1;
	
	for (int column = 0; column < NumberColumns; column++)
	{
		digitalWrite(Columns[column], LOW);

		for (int row = 0; row < NumberRows; row++)
		{
			if (!digitalRead(Rows[row]))
			{
				buttonPressed = ButtonMap[(row * 4) + column];
				
				if (LastButtonPressed == buttonPressed)
				{
					return -1;
				}
			}
		}

    digitalWrite(Columns[column], HIGH);
  }
  
  LastButtonPressed = buttonPressed;
  
  return buttonPressed;
}
