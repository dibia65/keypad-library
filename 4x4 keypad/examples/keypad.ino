#include "5x5keypad.h"

void setup()
{

  //i'm using esp8266 nodemcu it also applies to other boards!! 
  key_column[0]=D0;
  key_column[1]=D1;
  key_column[2]=D3;// i'm using only 3 column pins, i left out the fourth and fifth one
  key_row[0]=D4;
  key_row[1]=D5;
  key_row[2]=D6;//i'm using only 3 row pins , i left out the fourth and fifth one
  Serial.begin(9600);
  keypad_init();
 }
void loop()
{
  
}
