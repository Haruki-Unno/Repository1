const int Rpin = 3;
const int Bpin = 4;
const int Gpin = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Rpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue < 256){
    digitalWrite(Rpin, LOW);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, HIGH);
  }
  else if(sensorValue < 512){
    digitalWrite(Rpin, HIGH);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, LOW);
  }
  else if(sensorValue < 768){
    digitalWrite(Rpin, HIGH);
    digitalWrite(Bpin, LOW);
    digitalWrite(Gpin, HIGH);
  }
  else{
    digitalWrite(Rpin, LOW);
    digitalWrite(Bpin, LOW);
    digitalWrite(Gpin, LOW);
  }
  delay(1);
}