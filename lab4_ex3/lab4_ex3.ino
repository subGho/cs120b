#include "Timer.h"

enum SM1_STATES { SM1_SMStart, SM1_init, SM1_off, SM1_waitForOn, SM1_on } SM1_STATE;
unsigned char i = 0;
void Tick_LoHi() { 
   switch (SM1_STATE) { 
      case SM1_SMStart:
            SM1_STATE = SM1_init;
            i=0;
         break;
      case SM1_init:
            SM1_STATE = SM1_off;
         break;
      case SM1_off:
        Serial.println("case Off");
        Serial.println(analogRead(A0));
         if (analogRead(A0) < 10) 
         {
            SM1_STATE = SM1_waitForOn;
            i=0;
         }
         else
         {
          SM1_STATE = SM1_off;
         }
         break;
      case SM1_waitForOn:
        Serial.println("case waitForOn");
        // Serial.println(i);
        Serial.println(analogRead(A0));
         if (analogRead(A0) >= 10) 
         {
            SM1_STATE = SM1_off;
         }
         else
         {
          if (i >= 8)
          {
            SM1_STATE = SM1_on;
            i=0;
          }
         }
         i++;
         break;
      case SM1_on:
        Serial.println("case On");
        Serial.println(analogRead(A0));
        Serial.println(analogRead(A0));
        Serial.println(analogRead(A0));
        Serial.println(analogRead(A0));
         if (analogRead(A0) < 100) 
         {
            SM1_STATE = SM1_on;
         }
         else
         {
          SM1_STATE = SM1_off;
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
         break;
      case SM1_off:
        digitalWrite(9,LOW);
         break;
      case SM1_waitForOn:
         break;
      case SM1_on:
        digitalWrite(9,HIGH);
         break;
   }
}

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  TimerSet(500); //this value (500) is the period in ms
  TimerOn();
  Serial.begin(9600);
}

void loop()
{
  
  Tick_LoHi();
  while(!TimerFlag){}
  TimerFlag = 0;  
}



