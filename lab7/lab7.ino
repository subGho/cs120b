const int trigPin = 2;
const int echoPin = 3;
long distance, duration;
int mapDistance;


const int enable = 5;
const int input1 = 6;
const int input2 = 7;

int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);



    //---set pin direction
  pinMode(enable,OUTPUT);
  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  mapDistance = map(distance, 2, 30, 1, 20);
  Serial.print("Distance:  ");
  Serial.println(mapDistance); 
  // Serial.println(distance); 

  if (mapDistance >= 3 && mapDistance <= 15)
  {
    Serial.println("***ON***");
    digitalWrite(input1,HIGH); //one way
    digitalWrite(input2,LOW);
    analogWrite(enable,500); //enable on
  }
  else
  {
    Serial.println("***OFF***");
    digitalWrite(input1,LOW); //one way
    digitalWrite(input2,LOW);
    analogWrite(enable,0); //enable on
  }


}





   
