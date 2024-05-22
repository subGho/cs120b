// C++ code
//
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 10, 5, 4, 3, 2);
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Enter a phrase");
  while(Serial.available() == 0){}
  String userInput = Serial.readString();
  lcd.setCursor(0,0); 
  lcd.print(userInput);
  
  Serial.println("Enter a second phrase");
  while(Serial.available() == 0){}
  userInput = Serial.readString();
  lcd.setCursor(0,1); 
  lcd.print(userInput);
  
  Serial.println("Enter any key to clear");
  while(Serial.available() == 0){}
  userInput = Serial.readString();
  lcd.clear();
}