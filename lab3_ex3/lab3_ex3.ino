volatile int TimerFlag = 0;
//void TimerISR() {
  // TimerFlag = 1;
//}

enum SM1_STATES { SM1_SMStart, SM1_0Btn, SM1_1BtnWait, SM1_1Btn, SM1_2BtnWait, SM1_2Btn, SM1_3BtnWait, SM1_3Btn, SM1_Init, SM1_OnOff, SM1_0BtnWait} SM1_STATE;
char lightOn = 0;
//char btn1 = 0;
//char btn2 = 0;
//char btn3 = 0;
void Tick_LoHi() { 
   switch (SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_Init;
         }
         break;
      case SM1_0Btn:
         if (digitalRead(13) && !digitalRead(12) && !digitalRead(11)) {
            SM1_STATE = SM1_1BtnWait;
         }
         else if (!(digitalRead(13) && !digitalRead(12) && !digitalRead(11))) {
            SM1_STATE = SM1_0Btn;
         }
         else {
            SM1_STATE = SM1_0Btn;
         }
         break;
      case SM1_1BtnWait:
         if (digitalRead(13) && !digitalRead(12) && !digitalRead(11)) {
            SM1_STATE = SM1_1BtnWait;
         }
         else if (!digitalRead(13) && !digitalRead(12) && !digitalRead(11)) {
            SM1_STATE = SM1_1Btn;
         }
         else {
            SM1_STATE = SM1_1BtnWait;
         }
         break;
      case SM1_1Btn:
         if (!digitalRead(13) && !digitalRead(12) && !digitalRead(11)) {
            SM1_STATE = SM1_1Btn;
         }
         else if (!(digitalRead(11) && !digitalRead(13) && !digitalRead(12))) {
            SM1_STATE = SM1_0Btn;
         }
         else if (digitalRead(11) && !digitalRead(13) && !digitalRead(12)) {
            SM1_STATE = SM1_2BtnWait;
         }
         else {
            SM1_STATE = SM1_1Btn;
         }
         break;
      case SM1_2BtnWait:
         if (digitalRead(11) && !digitalRead(13) && !digitalRead(12)) {
            SM1_STATE = SM1_2BtnWait;
         }
         else if (!digitalRead(13) && !digitalRead(12) && !digitalRead(11)) {
            SM1_STATE = SM1_2Btn;
         }
         else {
            SM1_STATE = SM1_2BtnWait;
         }
         break;
      case SM1_2Btn:
         if (!digitalRead(11) && !digitalRead(12) && !digitalRead(13)) {
            SM1_STATE = SM1_2Btn;
         }
         else if (!(digitalRead(12) && !digitalRead(13) && !digitalRead(11))) {
            SM1_STATE = SM1_0Btn;
         }
         else if (digitalRead(12) && !digitalRead(13) && !digitalRead(11)) {
            SM1_STATE = SM1_3BtnWait;
         }
         else {
            SM1_STATE = SM1_2Btn;
         }
         break;
      case SM1_3BtnWait:
         if (digitalRead(12) && !digitalRead(13) && !digitalRead(11)) {
            SM1_STATE = SM1_3BtnWait;
         }
         else if (!digitalRead(13) && !digitalRead(12) && !digitalRead(11)) {
            SM1_STATE = SM1_3Btn;
         }
         else {
            SM1_STATE = SM1_3BtnWait;
         }
         break;
      case SM1_3Btn:
         if (1) {
            SM1_STATE = SM1_OnOff;
         }
         break;
      case SM1_Init:
         if (1) {
            SM1_STATE = SM1_0Btn;
         }
         break;
      case SM1_OnOff:
         if (1) {
            SM1_STATE = SM1_0BtnWait;
         }
         break;
      case SM1_0BtnWait:
         if (digitalRead(13) && !digitalRead(12) && !digitalRead(11)) {
            SM1_STATE = SM1_1BtnWait;
         }
         else if (!digitalRead(13) && !digitalRead(12) && !digitalRead(11)) {
            SM1_STATE = SM1_0BtnWait;
         }
         else if (!(digitalRead(13) && !digitalRead(12) && !digitalRead(11))) {
            SM1_STATE = SM1_0Btn;
         }
         else {
            SM1_STATE = SM1_0BtnWait;
         }
         break;
      default:
         SM1_STATE = SM1_Init;
         break;
   }
   switch (SM1_STATE) { 
      case SM1_SMStart:
         
         break;
      case SM1_0Btn:
         
         break;
      case SM1_1BtnWait:
         
         break;
      case SM1_1Btn:
         
         break;
      case SM1_2BtnWait:
         
         break;
      case SM1_2Btn:
         
         break;
      case SM1_3BtnWait:
         
         break;
      case SM1_3Btn:
         
         break;
      case SM1_Init:
         digitalWrite(2, LOW);
         break;
      case SM1_OnOff:
         if (!lightOn) 
         {
           digitalWrite(2, HIGH);
           lightOn = 1;
         }
		else 
        {
          digitalWrite(2, LOW);
          lightOn = 0;
        }
         break;
      case SM1_0BtnWait:
         
         break;
   }
}


void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(2, OUTPUT);
}


void loop()
{
  Tick_LoHi();
}
