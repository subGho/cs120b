#include "Timer.h"

int mapDist = 0;
int mapOut = 0;


const int trigPin = 2;
const int echoPin = 3;
long distance, duration;
const int enable = 5;
const int input1 = 6;
const int input2 = 7;



enum SM1_STATES {SM1_SMStart, SM1_outRange, SM1_inRange} SM1_STATE;
void Tick_UltraSonicRead() 
{
  switch (SM1_STATE) 
  {
    case SM1_SMStart:
      // Serial.println("enter caseStart");
      // Serial.print("caseStart Distance:  ");
      // Serial.println(mapDist);  
      if (mapDist < 3 || mapDist > 20)
      {
        // Serial.println("enter first if smStart");
        SM1_STATE = SM1_outRange;
        // Serial.println("exit first if smStart");
      }
      else if (!(mapDist < 3 || mapDist > 20))
      {
        SM1_STATE = SM1_inRange;
      }
      break;
    case SM1_outRange:
      // Serial.println("enter caseOutRange"); 
      // Serial.print("outRange Distance:  ");
      // Serial.println(mapDist); 
      if (mapDist < 3 || mapDist > 20)
      {
        SM1_STATE = SM1_outRange;
      }
      else if (!(mapDist < 3 || mapDist > 20))
      {
        SM1_STATE = SM1_inRange;
      }
      break;
    case SM1_inRange:
      // Serial.println("enter caseInRange"); 
      // Serial.print("inRange Distance:  ");
      // Serial.println(mapDist);  
      if (!(mapDist < 3 || mapDist > 20))
      {
        SM1_STATE = SM1_outRange;
      }
      else if (mapDist < 3 || mapDist > 20)
      {
        SM1_STATE = SM1_inRange;
      }
      break;
    default:
      SM1_STATE = SM1_outRange;
      break;
  }
  switch (SM1_STATE)
  {
    case SM1_SMStart:
      break;
    case SM1_outRange:
      break;
    case SM1_inRange:
      Serial.print("mapDist:  ");
      Serial.println(mapDist);
      mapOut = map(mapDist,1,20,255,200);
      // Serial.print("mapOut:  ");
      // Serial.println(mapOut);
      break;
  }
}

enum SM2_STATES {SM2_SMStart, SM2_off, SM2_on} SM2_STATE;
void Tick_FanSpeed() 
{
  switch (SM2_STATE) 
  {
    case SM2_SMStart:
      SM2_STATE = SM2_off;
      break;
    case SM2_off:
      if (mapDist < 3 || mapDist > 20)
      {
        SM2_STATE = SM2_off;
      }
      else if (!(mapDist < 3 || mapDist > 20))
      {
        SM2_STATE = SM2_on;
      }
      break;
    case SM2_on:
      if (!(mapDist < 3 || mapDist > 20))
      {
        SM2_STATE = SM2_off;
      }
      else if (mapDist < 3 || mapDist > 20)
      {
        SM2_STATE = SM2_on;
      }
      break;
    default:
      SM2_STATE = SM2_off;
      break;
  }
  switch (SM2_STATE)
  {
    case SM2_SMStart:
      break;
    case SM2_off:
      digitalWrite(input1, LOW);
      digitalWrite(input2, LOW);
      analogWrite(enable, mapOut);
      break;
    case SM2_on:
      digitalWrite(input1, HIGH);
      digitalWrite(input2, LOW);
      analogWrite(enable, mapOut);
      break;
  }
}




void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);




    //---set pin direction
  pinMode(enable,OUTPUT);
  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  Serial.begin(9600);

  TimerSet(10);  //this value (500) is the period in ms
  TimerOn();
}

void loop() {

  digitalWrite(trigPin, LOW);

  digitalWrite(trigPin, HIGH);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  mapDist = map(distance, 2, 30, 1, 20);

  Tick_UltraSonicRead();
  Tick_FanSpeed();
  while (!TimerFlag) {}
  TimerFlag = 0;


}
