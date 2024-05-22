// C++ code
//
const int B[] = {2, 3, 4, 5};
int a = 0x00;
int a0, a1, a2, a3;

void setup()
{
  pinMode(B[0], OUTPUT);
  pinMode(B[1], OUTPUT);
  pinMode(B[2], OUTPUT);
  // pinMode(B[3], OUTPUT);
  Serial.begin(9600);
}

void resetB()
{
  // digitalWrite(B[3],LOW);
  digitalWrite(B[2],LOW);
  digitalWrite(B[1],LOW);
  digitalWrite(B[0],LOW);
}

void writeToB(unsigned char temp)
{
  // Serial.println(temp & );
  if ((temp - 0x41) < 0x00)
  {
    digitalWrite(B[2],HIGH);
    digitalWrite(B[0],LOW);
    digitalWrite(B[1],LOW);
  }
  else if ((temp - 0x5F) > 0x00)
  {
    digitalWrite(B[0],HIGH);
    digitalWrite(B[1],LOW);
    digitalWrite(B[2],LOW);
  }
  else 
  {
    digitalWrite(B[1],HIGH);
    digitalWrite(B[0],LOW);
    digitalWrite(B[2],LOW);
  }
}


void loop()
{
  Serial.print("What is the temperature? \n");
  while(Serial.available() == 0){}
  a = Serial.parseInt();
  Serial.println(a);
  writeToB(a); //This will display the value of a in binary on the LEDs
  
  // delay(200);
}
