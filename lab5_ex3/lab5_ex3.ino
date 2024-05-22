#include "Timer.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 10, 5, 4, 3, 2);  

unsigned char xCord = 0;
unsigned char yCord = 0;
unsigned char index = 0;
unsigned char letters[] = {'S', 'U', 'B', 'H', 'O', 'N'};

enum SM1_STATES { SM1_SMStart, SM1_hover, SM1_rightShift, SM1_downShift, SM1_leftShift, SM1_upShift, SM1_waitPlace, SM1_place, SM1_placeClear} SM1_STATE;
void Tick_LoHi() { 
   switch (SM1_STATE) { 
      case SM1_SMStart:
          // Serial.println("currState: Start");
          SM1_STATE = SM1_hover;
         break;
      case SM1_hover:
        // Serial.println("currState: Hover");
         if ((analogRead(A0) > 900)) {
            SM1_STATE = SM1_leftShift;
         }
         else if ((analogRead(A0) < 100)) {
            SM1_STATE = SM1_rightShift;
         }
         else if ((analogRead(A1) > 900)) {
            SM1_STATE = SM1_upShift;
         }
         else if ((analogRead(A1) < 100)) {
          // Serial.println("WOOOOO");
            SM1_STATE = SM1_downShift;
         }
         else if (!digitalRead(13)) {
            SM1_STATE = SM1_waitPlace;
         }
         else
         {
            SM1_STATE = SM1_hover;
         }
         break;
      case SM1_rightShift:
         if (!(analogRead(A0) < 100)) {
            SM1_STATE = SM1_hover;
         }
         else if ((analogRead(A0) < 100)) {
            SM1_STATE = SM1_rightShift;
         }
         break;
      case SM1_downShift:
         if (!(analogRead(A0) > 900)) {
            SM1_STATE = SM1_hover;
         }
         else if ((analogRead(A0) > 900)) {
            SM1_STATE = SM1_downShift;
         }
         break;
      case SM1_leftShift:
         if (!(analogRead(A0) > 900)) {
            SM1_STATE = SM1_hover;
         }
         else if ((analogRead(A0) > 900)) {
            SM1_STATE = SM1_leftShift;
         }
         break;
      case SM1_upShift:
         if ((analogRead(A1) > 900)) {
            SM1_STATE = SM1_upShift;
         }
         else if (!(analogRead(A1) > 900)) {
            SM1_STATE = SM1_hover;
         }
         break;
      case SM1_waitPlace:
         if (!digitalRead(13)) {
            SM1_STATE = SM1_waitPlace;
         }
         else if (digitalRead(13)) {
            SM1_STATE = SM1_place;
         }
         break;
      case SM1_place:
        if (index > 5)
        {
          SM1_STATE = SM1_placeClear;
        }
        else SM1_STATE = SM1_hover;
          
         break;
      case SM1_placeClear:
          SM1_STATE = SM1_hover;
          break;
      default:
         SM1_STATE = SM1_SMStart;
         break;
   }
   switch (SM1_STATE) { 
      case SM1_SMStart:
         break;
      case SM1_hover:
         break;
      case SM1_rightShift:
         if (xCord<15)
         {
          xCord++;
         }
         else 
         {
          xCord=0;
         }
         break;
      case SM1_downShift:
        // Serial.println("case downShift");
         if (yCord==1) yCord=0;
         else yCord=1;
         break;
      case SM1_leftShift:
         if (xCord>0) xCord--;
         else xCord=15;
         break;
      case SM1_upShift:
      // Serial.println("case upShift");
         if (yCord==0) yCord=1;
         else yCord=0;
         break;
      case SM1_waitPlace:
         break;
      case SM1_place:
          lcd.setCursor(xCord,yCord);
          lcd.print((char) letters[index]);
          // lcd.print(index);
          Serial.println((char) letters[index]);
          index++;
         break;
      case SM1_placeClear:
          lcd.clear();
          index = 0;
          xCord = 0;
          yCord = 0;
          lcd.setCursor(xCord,yCord);
          break;
   }
}

void setup()
{
  digitalWrite(13, HIGH);
  lcd.begin(16, 2);
  TimerSet(150);  //this value (500) is the period in ms
  TimerOn();
  Serial.begin(9600);
}

void loop() {
  Tick_LoHi();
  while (!TimerFlag) {}
  TimerFlag = 0;
  // Serial.print("button:  ");
  // Serial.println(digitalRead(13));
  // Serial.print("X_Cord:  ");
  // Serial.println(xCord);
  // // Serial.println(analogRead(A0));
  // Serial.print("Y_Cord:  ");
  // Serial.println(yCord);
  // Serial.println(analogRead(A1));
  // Serial.println(digitalRead(12));
}
