
#include "Keypad.h"
#include "MiniLCD.h"
#include <Wire.h>

#define NumberColumns 4
#define NumberRows 5
#define Address 0b0111110

int Columns[NumberColumns] = {A0,A1,A2,A3};
int Rows[NumberRows] = {7,9,10,11,12};

char ButtonMap[NumberColumns * NumberRows] = {'c', 's', '%', '/', 
                                              '7', '8', '9', 'x', 
                                              '4', '5', '6', '-',
                                              '1', '2', '3', '+', 
                                              '0', '0', '.', '='};

Keypad keypad(NumberColumns, NumberRows, Columns, Rows, ButtonMap);
MiniLCD *miniLCD;

void setup() 
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  miniLCD = new MiniLCD(Address);
}

char Numbers[8] = {};
int Index = 0;
char Operation = ' ';

void loop() 
{
  int buttonPressed = keypad.getButtonPressed(); 
  
  if (buttonPressed != -1)
  {
    if (buttonPressed == 'c')
    {
      Index = 0;
      miniLCD->ClearScreen();
    }
    else if (buttonPressed == '+' || buttonPressed == '-' ||
             buttonPressed == 'x' || buttonPressed == '/')
    {
        Operation = buttonPressed; 
        miniLCD->SendDataToScreen(buttonPressed);   
    }
    else if (buttonPressed == '=')
    {
      Calculate();
    }
    else 
    {
      Numbers[Index] = buttonPressed;
      Index++;
      miniLCD->SendDataToScreen(buttonPressed); 
    }
  }
  
  delay(100);
}

void Calculate()
{
   miniLCD->SendDataToScreen('=');
   delay(100);

  int result = 0; 

  if (Operation == '+')
  {
    for (int i = 0; i < Index; i++)
    {
      result = result + Numbers[i] - '0';
    }
  }
  else if (Operation == '-')
  {
    //TODO
  }
  else if (Operation == 'x')
  {
    //TODO
  }
  else if (Operation == '/')
  {
    //TODO
  }

  miniLCD->SendDataToScreen(result + '0');

  Index = 0;
}
