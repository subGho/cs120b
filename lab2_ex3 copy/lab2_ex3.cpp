// C++ code
//
const int B[] = {2, 3, 4, 5};
int a = 0x00;
int a0, a1, a2, a3;

unsigned char GetBit(unsigned char x, unsigned char k) {
   return ((x & (0x01 << k)) != 0);
}

void setup()
{
  pinMode(B[0], OUTPUT);
  pinMode(B[1], OUTPUT);
  pinMode(B[2], OUTPUT);
  pinMode(B[3], OUTPUT);
  Serial.begin(9600);
}

void resetB()
{
  digitalWrite(B[3],LOW);
  digitalWrite(B[2],LOW);
  digitalWrite(B[1],LOW);
  digitalWrite(B[0],LOW);
}

void writeToB(unsigned char temp)
{
  if (temp == 1)
  {
    digitalWrite(B[0],LOW);
    digitalWrite(B[1],LOW);
    digitalWrite(B[2],LOW);
    digitalWrite(B[3],HIGH);
  }
  else if (temp == 2)
  {
    digitalWrite(B[0],LOW);
    digitalWrite(B[1],LOW);
    digitalWrite(B[2],HIGH);
    digitalWrite(B[3],HIGH);
  }
  else if (temp == 3)
  {
    digitalWrite(B[0],LOW);
    digitalWrite(B[1],HIGH);
    digitalWrite(B[2],HIGH);
    digitalWrite(B[3],HIGH);
  }
  else if (temp == 4)
  {
    digitalWrite(B[0],HIGH);
    digitalWrite(B[1],HIGH);
    digitalWrite(B[2],HIGH);
    digitalWrite(B[3],HIGH);
  }
  else if (temp == 0)
  {
    digitalWrite(B[0],LOW);
    digitalWrite(B[1],LOW);
    digitalWrite(B[2],LOW);
    digitalWrite(B[3],LOW);
  }
    
}


void loop()
{
  a = analogRead(A0);
  // Serial.println(a);
  a = map(a, 1023, 100, 0, 4);
  // Serial.println(a);
  writeToB(a); //This will display the value of a in binary on the LEDs
  delay(200);
  }
