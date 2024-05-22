#include "Timer.h"

int toRight = 0;
int toLeft = 0;
int next = 0;
int score = 0;
int incremented = 0;
int i = 0;

int clickGreen = 0;
int clickRed = 0;

enum SM1_STATES { SM1_SMStart, SM1_one, SM1_two, SM1_three, SM1_four, SM1_incScore, SM1_five, SM1_six, SM1_seven } SM1_STATE;
void Tick_Flash() { 
   switch (SM1_STATE) { 
      case SM1_SMStart:
         if (1) {
            SM1_STATE = SM1_one;
         }
         break;
      case SM1_one:
        // Serial.println("case: ONE");
        // Serial.print("button:   ");
          // Serial.println(digitalRead(13));x
         if (toLeft && !toRight && !digitalRead(13) && i==7) {
          
            SM1_STATE = SM1_two;
            i=0;
         }
         else if (digitalRead(13) && i==7) {
            SM1_STATE = SM1_one;
            score = 0;
            next = 0;
            i=0;
         }
         i++;
         break;
      case SM1_two:
         if (toLeft && !toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_three;
            i=0;
         }
         else if (!toLeft && toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_one;
            i=0;
         }
         else if (digitalRead(13) && i==7) {
            SM1_STATE = SM1_two;
            score = 0;
            next = 0;
            i=0;
         }
         i++;
         break;
      case SM1_three:
         if (toLeft && !toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_four;
            i=0;
         }
         else if (!toLeft && toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_two;
            i=0;
         }
         else if (digitalRead(13) && i==7) {
            SM1_STATE = SM1_three;
            score = 0;
            next = 0;
            i=0;
         }
         i++;
         break;
      case SM1_four:
        // Serial.println("||STATE FOUR||");
         if (toLeft && !toRight && !digitalRead(13) && i==7) {
            incremented = 0;
            SM1_STATE = SM1_five;
            i=0;
         }
         else if (!toLeft && toRight && !digitalRead(13) && i==7) {
            incremented = 0;
            SM1_STATE = SM1_three;
            i=0;
         }
         else if (digitalRead(13)) {
            // Serial.print("BUTTON CLICKED, increment:   ");
            // Serial.println(incremented);
            if (!incremented)
            {
              
              SM1_STATE = SM1_incScore;
              // Serial.println("entered");
            }
            else
            {
              SM1_STATE = SM1_four;
              i=0;
              
            }
         }
         i++;
         break;
      case SM1_incScore:
        //  Serial.println("   ||STATE SCORE||   ");
        //  Serial.print("came back, increment:   ");
        //  Serial.println(incremented);
         if (incremented)
         {
          SM1_STATE = SM1_four;
         }
         else
         {
          SM1_STATE = SM1_incScore;
         }
         break;
      case SM1_five:
         if (toLeft && !toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_six;
            i=0;
         }
         else if (!toLeft && toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_four;
            i=0;
         }
         else if (digitalRead(13) && i==7) {
            SM1_STATE = SM1_five;
            score = 0;
            next = 0;
            i=0;
         }
         i++;
         break;
      case SM1_six:
         if (toLeft && !toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_seven;
            i=0;
         }
         else if (!toLeft && toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_five;
            i=0;
         }
         else if (digitalRead(13)) {
            SM1_STATE = SM1_six;
            score = 0;
            next = 0;
            i=0;
         }
         i++;
         break;
      case SM1_seven:
         if (!toLeft && toRight && !digitalRead(13) && i==7) {
            SM1_STATE = SM1_six;
            i=0;
         }
         else if (digitalRead(13) && i==7) {
            SM1_STATE = SM1_seven;
            score = 0;
            next = 0;
            i=0;
         }
         i++;
         break;
      default:
         SM1_STATE = SM1_one;
         break;
   }
   switch (SM1_STATE) { 
      case SM1_SMStart:
         break;
      case SM1_one:
         toRight = 0;
         toLeft = 1;
         digitalWrite(2, HIGH);
         digitalWrite(3, LOW);
         digitalWrite(4, LOW);
         digitalWrite(5, LOW);
         digitalWrite(6, LOW);
         digitalWrite(7, LOW);
         digitalWrite(8, LOW);
         break;
      case SM1_two:
         digitalWrite(2, LOW);
         digitalWrite(3, HIGH);
         digitalWrite(4, LOW);
         digitalWrite(5, LOW);
         digitalWrite(6, LOW);
         digitalWrite(7, LOW);
         digitalWrite(8, LOW);
         break;
      case SM1_three:
         digitalWrite(2, LOW);
         digitalWrite(3, LOW);
         digitalWrite(4, HIGH);
         digitalWrite(5, LOW);
         digitalWrite(6, LOW);
         digitalWrite(7, LOW);
         digitalWrite(8, LOW);
         break;
      case SM1_four:
         digitalWrite(2, LOW);
         digitalWrite(3, LOW);
         digitalWrite(4, LOW);
         digitalWrite(5, HIGH);
         digitalWrite(6, LOW);
         digitalWrite(7, LOW);
         digitalWrite(8, LOW);
         break;
      case SM1_incScore:
        //  Serial.println("DID I GET HERE??");
         incremented = 1;
         if (score < 9)
         {
          score++;
         }
         else
         {
          score = 0;
          next++;
         }
         
         break;
      case SM1_five:
         digitalWrite(2, LOW);
         digitalWrite(3, LOW);
         digitalWrite(4, LOW);
         digitalWrite(5, LOW);
         digitalWrite(6, HIGH);
         digitalWrite(7, LOW);
         digitalWrite(8, LOW);
         break;
      case SM1_six:
         digitalWrite(2, LOW);
         digitalWrite(3, LOW);
         digitalWrite(4, LOW);
         digitalWrite(5, LOW);
         digitalWrite(6, LOW);
         digitalWrite(7, HIGH);
         digitalWrite(8, LOW);
         break;
      case SM1_seven:
         toRight = 1;
         toLeft = 0;
         digitalWrite(2, LOW);
         digitalWrite(3, LOW);
         digitalWrite(4, LOW);
         digitalWrite(5, LOW);
         digitalWrite(6, LOW);
         digitalWrite(7, LOW);
         digitalWrite(8, HIGH);
         break;
   }
}


enum SM2_STATES { SM2_SMStart, SM2_0, SM2_n0, SM2_1, SM2_n1, SM2_3, SM2_n3, SM2_4, SM2_n4, SM2_5, SM2_n5, SM2_6, SM2_n6, SM2_7, SM2_n7, SM2_8, SM2_n8, SM2_9, SM2_n9, SM2_2, SM2_n2 } SM2_STATE;
void Tick_Score() { 
   switch (SM2_STATE) { 
      case SM2_SMStart:
          SM2_STATE = SM2_0;
         break;
      case SM2_0:
         if (score == 1) {
            SM2_STATE = SM2_1;
            // score++;
         }
         else {
          SM2_STATE = SM2_0;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n0:
         if (next == 1) {
            SM2_STATE = SM2_n1;
            // score++;
         }
         else {
          SM2_STATE = SM2_n0;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_1:
         if (score == 0) {
            SM2_STATE = SM2_0;
         }
         else if (score == 2) {
            SM2_STATE = SM2_2;
            // score++;
         }
         else {
            SM2_STATE = SM2_1;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n1:
         if (next == 0) {
            SM2_STATE = SM2_n0;
         }
         else if (next == 2) {
            SM2_STATE = SM2_n2;
         }
         else {
            SM2_STATE = SM2_n1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_3:
         if (score == 0) {
            SM2_STATE = SM2_0;
            // score = 0;
         }
         else if (score == 4) {
            SM2_STATE = SM2_4;
            // score++;
         }
         else {
            SM2_STATE = SM2_3;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n3:
         if (next == 0) {
            SM2_STATE = SM2_n0;
            // score = 0;
         }
         else if (next == 4) {
            SM2_STATE = SM2_n4;
            // score++;
         }
         else {
            SM2_STATE = SM2_n3;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_4:
         if (score == 0) {
            SM2_STATE = SM2_0;
            // score = 0;
         }
         else if (score == 5) {
            SM2_STATE = SM2_5;
            // score++;
         }
         else {
            SM2_STATE = SM2_4;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n4:
         if (next == 0) {
            SM2_STATE = SM2_n0;
            // score = 0;
         }
         else if (next == 5) {
            SM2_STATE = SM2_n5;
            // score++;
         }
         else {
            SM2_STATE = SM2_n4;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_5:
         if (score == 0) {
            SM2_STATE = SM2_0;
         }
         else if (score == 6) {
            SM2_STATE = SM2_6;
            // score++;
         }
         else {
            SM2_STATE = SM2_5;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n5:
         if (next == 0) {
            SM2_STATE = SM2_n0;
         }
         else if (next == 6) {
            SM2_STATE = SM2_n6;
            // score++;
         }
         else {
            SM2_STATE = SM2_n5;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_6:
         if (score == 0) {
            SM2_STATE = SM2_0;
            // score = 0;
         }
         else if (score == 7) {
            SM2_STATE = SM2_7;
            // score++;
         }
         else {
            SM2_STATE = SM2_6;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n6:
         if (next == 0) {
            SM2_STATE = SM2_n0;
            // score = 0;
         }
         else if (next == 7) {
            SM2_STATE = SM2_n7;
            // score++;
         }
         else {
            SM2_STATE = SM2_n6;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_7:
         if (score == 0) {
            SM2_STATE = SM2_0;
            // score = 0;
         }
         else if (score == 8) {
            SM2_STATE = SM2_8;
            // score++;
         }
         else {
            SM2_STATE = SM2_7;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n7:
         if (next == 0) {
            SM2_STATE = SM2_n0;
            // score = 0;
         }
         else if (next == 8) {
            SM2_STATE = SM2_n8;
            // score++;
         }
         else {
            SM2_STATE = SM2_n7;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_8:
         if (score == 0) {
            SM2_STATE = SM2_0;
            // score = 0;
         }
         else if (score == 9) {
            SM2_STATE = SM2_9;
            // score++;
         }
         else {
            SM2_STATE = SM2_8;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n8:
         if (next == 0) {
            SM2_STATE = SM2_n0;
            // score = 0;
         }
         else if (next == 9) {
            SM2_STATE = SM2_n9;
            // score++;
         }
         else {
            SM2_STATE = SM2_n8;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_9:
         if (score == 0) {
            SM2_STATE = SM2_0;
            // score = 0;
         }
         else {
            SM2_STATE = SM2_9;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n9:
         if (next == 0) {
            SM2_STATE = SM2_n0;
            // score = 0;
         }
         else {
            SM2_STATE = SM2_n9;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      case SM2_2:
         if (score == 0) {
            SM2_STATE = SM2_0;
            // score = 0;
         }
         else if (score == 3) {
            SM2_STATE = SM2_3;
            // score++;
         }
         else {
            SM2_STATE = SM2_2;
         }
         if (next == 0)
         {
          SM2_STATE = SM2_n0;
         }
         else if (next == 1)
         {
          SM2_STATE = SM2_n1;
         }
         else if (next == 2)
         {
          SM2_STATE = SM2_n2;
         }
         else if (next == 3)
         {
          SM2_STATE = SM2_n3;
         }
         else if (next == 4)
         {
          SM2_STATE = SM2_n4;
         }
         else if (next == 5)
         {
          SM2_STATE = SM2_n5;
         }
         else if (next == 6)
         {
          SM2_STATE = SM2_n6;
         }
         else if (next == 7)
         {
          SM2_STATE = SM2_n7;
         }
         else if (next == 8)
         {
          SM2_STATE = SM2_n8;
         }
         else if (next == 9)
         {
          SM2_STATE = SM2_n9;
         }
         break;
      case SM2_n2:
         if (next == 0) {
            SM2_STATE = SM2_n0;
            // score = 0;
         }
         else if (next == 3) {
            SM2_STATE = SM2_n3;
            // score++;
         }
         else {
            SM2_STATE = SM2_n2;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         if (score == 0)
         {
          SM2_STATE = SM2_0;
         }
         else if (score == 1)
         {
          SM2_STATE = SM2_1;
         }
         else if (score == 2)
         {
          SM2_STATE = SM2_2;
         }
         else if (score == 3)
         {
          SM2_STATE = SM2_3;
         }
         else if (score == 4)
         {
          SM2_STATE = SM2_4;
         }
         else if (score == 5)
         {
          SM2_STATE = SM2_5;
         }
         else if (score == 6)
         {
          SM2_STATE = SM2_6;
         }
         else if (score == 7)
         {
          SM2_STATE = SM2_7;
         }
         else if (score == 8)
         {
          SM2_STATE = SM2_8;
         }
         else if (score == 9)
         {
          SM2_STATE = SM2_9;
         }
         break;
      default:
         SM2_STATE = SM2_0;
         break;
   }
   switch (SM2_STATE) { 
      case SM2_SMStart:
         break;
      case SM2_0:
        digitalWrite(12, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
        digitalWrite(19, HIGH);
        digitalWrite(9, LOW);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n0:
        digitalWrite(11, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
        digitalWrite(19, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_1:
        digitalWrite(12, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
        digitalWrite(19, LOW);
        digitalWrite(9, LOW);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n1:
        digitalWrite(11, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
        digitalWrite(19, LOW);
        digitalWrite(9, LOW);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_3:
        digitalWrite(12, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(19, LOW);
        digitalWrite(9, HIGH);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n3:
        digitalWrite(11, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(19, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_4:
        digitalWrite(12, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n4:
        digitalWrite(11, LOW);
        digitalWrite(14, LOW);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_5:
        digitalWrite(12, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n5:
        digitalWrite(11, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, LOW);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_6:
        digitalWrite(12, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n6:
        digitalWrite(11, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, LOW);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_7:
        digitalWrite(12, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
        digitalWrite(19, LOW);
        digitalWrite(9, LOW);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n7:
        digitalWrite(11, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
        digitalWrite(19, LOW);
        digitalWrite(9, LOW);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_8:
        digitalWrite(12, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n8:
        digitalWrite(11, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_9:
        digitalWrite(12, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n9:
        digitalWrite(11, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(18, LOW);
        digitalWrite(19, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        
         break;
      case SM2_2:
        digitalWrite(12, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
        digitalWrite(19, LOW);
        digitalWrite(9, HIGH);
        
        digitalWrite(11, HIGH);
         break;
      case SM2_n2:
        digitalWrite(11, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(15, HIGH);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        digitalWrite(18, HIGH);
        digitalWrite(19, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        
         break;
   }
}




void setup()
{
  // leds
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  // button 
  pinMode(13, INPUT);

  // num display
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  
  TimerSet(10);  //this value (500) is the period in ms
  TimerOn();
  Serial.begin(9600);
}

void loop() {
  Tick_Flash();
  Tick_Score();

  while (!TimerFlag) {}
  TimerFlag = 0;

}

