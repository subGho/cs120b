#include "Timer.h"

enum SM1_STATES { SM1_SMStart, SM1_init, SM1_red, SM1_yellow, SM1_green, SM1_waitGreen } SM1_STATE;
unsigned char i = 0;
void Tick_LoHi() { 
   switch (SM1_STATE) { 
      case SM1_SMStart:
          SM1_STATE = SM1_init;
         break;
      case SM1_init:
          SM1_STATE = SM1_red;
         break;
      case SM1_red:

         if (!digitalRead(10)) {
            SM1_STATE = SM1_red;
         }
         else if (digitalRead(10)) {
            SM1_STATE = SM1_waitGreen;
         }
         break;
      case SM1_yellow:
         if (i>=20)
         {
          i=0;
          SM1_STATE = SM1_red;
         }
         else
         {
          SM1_STATE = SM1_yellow;
         }
         i++;
         break;
      case SM1_green:
         if (i>=40)
         {
          i=0;
          SM1_STATE = SM1_yellow;
         }
         else
         {
          SM1_STATE = SM1_green;
         }
         i++;
         break;
      case SM1_waitGreen:
         if (digitalRead(10)) {
            SM1_STATE = SM1_waitGreen;
         }
         else if (!digitalRead(10)) {
            SM1_STATE = SM1_green;
         }
         break;
      default:
         SM1_STATE = SM1_init;
         break;
   }
   switch (SM1_STATE) { 
      case SM1_SMStart:
         break;
      case SM1_init:
         i=0;
         digitalWrite(2,LOW);
         digitalWrite(3,LOW);
         digitalWrite(4,LOW);
         break;
      case SM1_red:
         i=0;
         digitalWrite(2,HIGH);
         digitalWrite(3,LOW);
         digitalWrite(4,LOW);
         break;
      case SM1_yellow:
         digitalWrite(2,LOW);
         digitalWrite(3,HIGH);
         digitalWrite(4,LOW);
         break;
      case SM1_green:
         digitalWrite(2,LOW);
         digitalWrite(3,LOW);
         digitalWrite(4,HIGH);
         break;
      case SM1_waitGreen:
         digitalWrite(2,HIGH);
         digitalWrite(3,LOW);
         digitalWrite(4,LOW);
         break;
   }
}

void setup()
{
  pinMode(10, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  TimerSet(250); //this value (250) is the period in ms
  TimerOn();
  // Serial.begin(9600);
}

void loop()
{
  
  Tick_LoHi();
  while(!TimerFlag){}
  TimerFlag = 0;  
}
