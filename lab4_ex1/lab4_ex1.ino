#include "Timer.h"



enum SM1_STATES { SM1_SMStart, SM1_init, SM1_off, SM1_waitOn1, SM1_on1, SM1_waitOn2, SM1_on2, SM1_waitOff } SM1_STATE;
unsigned char i = 0;
unsigned char lightOn = 0;
void Tick_LoHi() { 
   switch (SM1_STATE) { 
      case SM1_SMStart:
            SM1_STATE = SM1_init;
         break;
      case SM1_init:
            SM1_STATE = SM1_off;
         break;
      case SM1_off:
        i=0;
         if (!digitalRead(10)) {
            SM1_STATE = SM1_off;
         }
         else if (digitalRead(10)) {
            SM1_STATE = SM1_waitOn1;
         }
         break;
      case SM1_waitOn1:
         if (digitalRead(10)) {
            SM1_STATE = SM1_waitOn1;
         }
         else if (!digitalRead(10)) {
            SM1_STATE = SM1_on1;
         }
         break;
      case SM1_on1:
         if (!digitalRead(10)) {
            SM1_STATE = SM1_on1;
         }
         else if (digitalRead(10)) {
            SM1_STATE = SM1_waitOn2;
         }
         break;
      case SM1_waitOn2:
         if (digitalRead(10)) {
            SM1_STATE = SM1_waitOn2;
         }
         else if (!digitalRead(10)) {
            SM1_STATE = SM1_on2;
         }
         break;
      case SM1_on2:
         if (!digitalRead(10)) {
            SM1_STATE = SM1_on2;
         }
         else if (digitalRead(10)) {
            SM1_STATE = SM1_waitOff;
         }
         break;
      case SM1_waitOff:
         if (digitalRead(10)) {
            SM1_STATE = SM1_waitOff;
         }
         else if (!digitalRead(10)) {
            SM1_STATE = SM1_off;
         }
         break;
      default:
         SM1_STATE = SM1_init;
         break;
   }
   switch (SM1_STATE) { 
      case SM1_SMStart:
        //  Serial.print("state: start\n");
         break;
      case SM1_init:
        //  Serial.print("state: init\n");
         digitalWrite(2,LOW);
         break;
      case SM1_off:
          // Serial.print("state: off\n");
         digitalWrite(2,LOW);
         break;
      case SM1_waitOn1:
         break;
      case SM1_on1:
        // Serial.print("state: on1\n");
        // Serial.print(i);
         if (i%4==0 || i%4==1)  
         {
            digitalWrite(2,HIGH);
            // Serial.print("on1   turn on\n");
           lightOn = 1;
           i++;
         }
         else 
         {
            digitalWrite(2,LOW);
            // Serial.print("on1   turn off\n");
           lightOn = 0;
           i++;
         }
         break;
      case SM1_waitOn2:
         if (i%4==0 || i%4==1)  
         {
            digitalWrite(2,HIGH);
            // Serial.print("on1   turn on\n");
           lightOn = 1;
           i++;
         }
         else 
         {
            digitalWrite(2,LOW);
            Serial.print("on1   turn off\n");
           lightOn = 0;
           i++;
         }
         break;
      case SM1_on2:
         if (!lightOn)  
         {
           digitalWrite(2,HIGH);
           lightOn = 1;
         }
         else  
         {
           digitalWrite(2,LOW);
           lightOn = 0;
         }
         break;
      case SM1_waitOff:
         if (!lightOn) 
         {
           digitalWrite(2,HIGH);
           lightOn = 1;
         }
         else  
         {
           digitalWrite(2,LOW);
           lightOn = 0;
         }
         break;
   }
}

void setup()
{
  pinMode(10, INPUT);
  pinMode(2, OUTPUT);
  TimerSet(100); //this value (100) is the period in ms
  TimerOn();
  // Serial.begin(9600);
}

void loop()
{
  
  Tick_LoHi();
  while(!TimerFlag){}
  TimerFlag = 0;  
}
