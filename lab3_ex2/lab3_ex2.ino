volatile int TimerFlag = 0;
//void TimerISR() {
  // TimerFlag = 1;
//}

enum SM1_STATES { SM1_SMStart, SM1_init, SM1_red, SM1_green, SM1_yellow, SM1_waitGreen, SM1_waitYellow, SM1_waitRed} SM1_STATE;
void Tick_LoHi() { 
   switch (SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_init;
         }
         break;
      case SM1_init:
         if (1) {
            SM1_STATE = SM1_red;
         }
         break;
      case SM1_red:
         if (digitalRead(13)) {
            SM1_STATE = SM1_waitGreen;
         }
         else if (!digitalRead(13)
) {
            SM1_STATE = SM1_red;
         }
         else {
            SM1_STATE = SM1_red;
         }
         break;
      case SM1_green:
         if (!digitalRead(13)) {
            SM1_STATE = SM1_green;
         }
         else if (digitalRead(13)) {
            SM1_STATE = SM1_waitYellow;
         }
         else {
            SM1_STATE = SM1_green;
         }
         break;
      case SM1_yellow:
         if (digitalRead(13)) {
            SM1_STATE = SM1_waitRed;
         }
         else if (!digitalRead(13)) {
            SM1_STATE = SM1_yellow;
         }
         else {
            SM1_STATE = SM1_yellow;
         }
         break;
      case SM1_waitGreen:
         if (digitalRead(13)) {
            SM1_STATE = SM1_waitGreen;
         }
         else if (!digitalRead(13)) {
            SM1_STATE = SM1_green;
         }
         else {
            SM1_STATE = SM1_waitGreen;
         }
         break;
      case SM1_waitYellow:
         if (digitalRead(13)) {
            SM1_STATE = SM1_waitYellow;
         }
         else if (!digitalRead(13)) {
            SM1_STATE = SM1_yellow;
         }
         else {
            SM1_STATE = SM1_waitYellow;
         }
         break;
      case SM1_waitRed:
         if (digitalRead(13)) {
            SM1_STATE = SM1_waitRed;
         }
         else if (!digitalRead(13)) {
            SM1_STATE = SM1_red;
         }
         else {
            SM1_STATE = SM1_waitRed;
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
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
         break;
      case SM1_red:
     	digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
         break;
      case SM1_green:
     	digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, HIGH);
         break;
      case SM1_yellow:
     	digitalWrite(2, LOW);
		digitalWrite(3, HIGH);
		digitalWrite(4, LOW);
         break;
      case SM1_waitGreen:
     	digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
         break;
      case SM1_waitYellow:
     	digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, HIGH);
         break;
      case SM1_waitRed:
     	digitalWrite(2, LOW);
		digitalWrite(3, HIGH);
		digitalWrite(4, LOW);
         break;
   }
}

void setup()
{
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}


void loop()
{
  Tick_LoHi();
}
