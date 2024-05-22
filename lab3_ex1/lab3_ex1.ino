volatile int TimerFlag = 0;
//void TimerISR() {
  // TimerFlag = 1;
//}

enum SM1_STATES { SM1_SMStart, SM1_init, SM1_off, SM1_on, SM1_waitOn, SM1_waitOff} SM1_STATE;
void Tick_LoHi() { 
   switch (SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_init;
         }
         break;
      case SM1_init:
         if (1) {
            SM1_STATE = SM1_off;
         }
         break;
      case SM1_off:
         if (digitalRead(13)) {
            SM1_STATE = SM1_waitOn;
         }
         else if (!digitalRead(13)
) {
            SM1_STATE = SM1_off;
         }
         else {
            SM1_STATE = SM1_off;
         }
         break;
      case SM1_on:
         if (!digitalRead(13)) {
            SM1_STATE = SM1_on;
         }
         else if (digitalRead(13)) {
            SM1_STATE = SM1_waitOff;
         }
         else {
            SM1_STATE = SM1_on;
         }
         break;
      case SM1_waitOn:
         if (digitalRead(13)) {
            SM1_STATE = SM1_waitOn;
         }
         else if (!digitalRead(13)) {
            SM1_STATE = SM1_on;
         }
         else {
            SM1_STATE = SM1_waitOn;
         }
         break;
      case SM1_waitOff:
         if (digitalRead(13)) {
            SM1_STATE = SM1_waitOff;
         }
         else if (!digitalRead(13)) {
            SM1_STATE = SM1_off;
         }
         else {
            SM1_STATE = SM1_waitOff;
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
         digitalWrite(2, LOW);
         break;
      case SM1_off:
         digitalWrite(2, LOW);
         break;
      case SM1_on:
         digitalWrite(2, HIGH);
         break;
      case SM1_waitOn:
         digitalWrite(2, LOW);
         break;
      case SM1_waitOff:
         digitalWrite(2, HIGH);
         break;
   }
}

void setup()
{
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
}


void loop()
{
  Tick_LoHi();
}
