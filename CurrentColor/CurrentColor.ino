/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/DigitalReadSerial/
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int buttonPin = 2;
int Rpin = 5;
int Bpin = 4;
int Gpin = 3;

int buttonState = 0;
int ledcolor = 0;
bool ButtonPressed = false;
String currentcolor = "led";

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  // make the pushbutton's pin an input:
  pinMode(Rpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  buttonState = digitalRead(buttonPin);
  // print out the state of the button:
  Serial.print("Current Color: ");
  Serial.println(currentcolor);

  if(buttonState == HIGH && !ButtonPressed){
    ledcolor += 1;
    ButtonPressed = true;
    //delay(100);
  }

  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }

  if(ledcolor == 0){
    currentcolor = "LED off";
    digitalWrite(Rpin, HIGH);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, HIGH);
  }

  else if(ledcolor == 1){
    currentcolor = "Red";
    digitalWrite(Rpin, LOW);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, HIGH);
  }

  else if(ledcolor == 2){
    currentcolor = "Green";
    digitalWrite(Rpin, HIGH);
    digitalWrite(Bpin, LOW);
    digitalWrite(Gpin, HIGH);
  }

  else if(ledcolor == 3){
    currentcolor = "Blue";
    digitalWrite(Rpin, HIGH);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, LOW);
  }

   else if(ledcolor == 4){
    currentcolor = "Yellow";
    digitalWrite(Rpin, LOW);
    digitalWrite(Bpin, LOW);
    digitalWrite(Gpin, HIGH);
  }

  else if(ledcolor == 5){
    currentcolor = "Cyan";
    digitalWrite(Rpin, HIGH);
    digitalWrite(Bpin, LOW);
    digitalWrite(Gpin, LOW);
  }

  else if(ledcolor == 6){
    currentcolor = "Purple";
    digitalWrite(Rpin, LOW);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, LOW);
  }

  else if(ledcolor == 7){
    currentcolor = "White";
    digitalWrite(Rpin, LOW);
    digitalWrite(Bpin, LOW);
    digitalWrite(Gpin, LOW);    
  }

  else if(ledcolor == 8){
    ledcolor = 0;
  }

  //Serial.println(buttonState);
  //delay(1);  // delay in between reads for stability
}
