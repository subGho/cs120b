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
  for (unsigned int i = 0; i < 4; i++)
  {
    digitalWrite(B[i], LOW);
    if (GetBit(a,i) ) 
    {
      digitalWrite(B[i], HIGH);
    }
  } 
}


void loop()
{
  Serial.print("What is the temperature in Fahrenheit? (32-59)\n");
  while(Serial.available() == 0){}
  a = Serial.parseInt();
  Serial.println(a);
  a = (a-0x20)*5/9;
  Serial.println(a);
  writeToB(a); //This will display the value of a in binary on the LEDs
  
  delay(200);
}
