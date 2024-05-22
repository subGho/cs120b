#include "Timer.h"
int x = 0;
enum SM1_STATES { SM1_SMStart,
                  SM1_off1,
                  SM1_on1,
                  SM1_off2,
                  SM1_off3,
                  SM1_off4,
                  SM1_off5,
                  SM1_on2,
                  SM1_on3,
                  SM1_on4,
                  SM1_on5,
                  SM1_waitOff1,
                  SM1_waitOn1,
                  SM1_waitOff2,
                  SM1_waitOn2,
                  SM1_waitOff3,
                  SM1_waitOn3,
                  SM1_waitOff4,
                  SM1_waitOn4,
                  SM1_waitOff5,
                  SM1_waitOn5 } SM1_STATE;
void Tick_LoHi() {
  switch (SM1_STATE) {
    case SM1_SMStart:
      SM1_STATE = SM1_on1;
      break;
    case SM1_off1:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_off2;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_off1;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn1;
      }
      break;
    case SM1_on1:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_on2;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_on1;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff1;
      }
      break;
    case SM1_off2:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_off3;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_off1;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn2;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_off2;
      }
      break;
    case SM1_off3:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_off4;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_off2;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn3;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_off3;
      }
      break;
    case SM1_off4:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_off5;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_off3;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn4;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_off4;
      }
      break;
    case SM1_off5:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_off5;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_off4;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn5;
      }
      break;
    case SM1_on2:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_on3;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_on1;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff2;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_on2;
      }
      break;
    case SM1_on3:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_on4;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_on2;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff3;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_on3;
      }
      break;
    case SM1_on4:
      if ((analogRead(A0) < 100) && digitalRead(12)) {
        SM1_STATE = SM1_on5;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_on3;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff4;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_on4;
      }
      break;
    case SM1_on5:
      if ((analogRead(A0) < 100)) {
        SM1_STATE = SM1_on5;
      } else if ((analogRead(A0) > 900) && digitalRead(12)) {
        SM1_STATE = SM1_on4;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff5;
      }
      break;
    case SM1_waitOff1:
      if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff1;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_off1;
      }
      break;
    case SM1_waitOn1:
      if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn1;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_on1;
      }
      break;
    case SM1_waitOff2:
      if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff2;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_off2;
      }
      break;
    case SM1_waitOn2:
      if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn2;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_on2;
      }
      break;
    case SM1_waitOff3:
      if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff3;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_off3;
      }
      break;
    case SM1_waitOn3:
      if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn3;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_on3;
      }
      break;
    case SM1_waitOff4:
      if (digitalRead(12)) {
        SM1_STATE = SM1_off4;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff4;
      }
      break;
    case SM1_waitOn4:
      if (digitalRead(12)) {
        SM1_STATE = SM1_on4;
      } else if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn4;
      }
      break;
    case SM1_waitOff5:
      if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOff5;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_off5;
      }
      break;
    case SM1_waitOn5:
      if (!digitalRead(12)) {
        SM1_STATE = SM1_waitOn5;
      } else if (digitalRead(12)) {
        SM1_STATE = SM1_on5;
      }
      break;
    default:
      SM1_STATE = SM1_on1;
      break;
  }
  switch (SM1_STATE) {
    case SM1_SMStart:
      break;
    case SM1_off1:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case SM1_on1:
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case SM1_off2:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case SM1_off3:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case SM1_off4:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case SM1_off5:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case SM1_on2:
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case SM1_on3:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case SM1_on4:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      break;
    case SM1_on5:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      break;
    case SM1_waitOff1:
      break;
    case SM1_waitOn1:
      break;
    case SM1_waitOff2:
      break;
    case SM1_waitOn2:
      break;
    case SM1_waitOff3:
      break;
    case SM1_waitOn3:
      break;
    case SM1_waitOff4:
      break;
    case SM1_waitOn4:
      break;
    case SM1_waitOff5:
      break;
    case SM1_waitOn5:
      break;
  }
}


void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(12, INPUT);
  digitalWrite(12, HIGH);
  
  TimerSet(150);  //this value (500) is the period in ms
  TimerOn();
  Serial.begin(9600);
}

void loop() {
  Tick_LoHi();
  while (!TimerFlag) {}
  TimerFlag = 0;
  Serial.println(analogRead(A0));
  // Serial.println(digitalRead(12));
}

// int main() {
//    int LoHiElapsedTime = 1000;
//    int periodGCD = 1000;
//    SM1_STATE = SM1_SMStart;
//    TimerSet(periodGCD);
//    TimerOn();
//    while (1) {
//       if (LoHiElapsedTime >= 1000) {
//          Tick_LoHi();
//          LoHiElapsedTime = 0;
//       }
//       LoHiElapsedTime += 1000;
//       while (!TimerFlag) {}
//       TimerFlag = 0;
//    }
// }
