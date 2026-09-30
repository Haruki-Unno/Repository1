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
int ledState = LOW;
int ledcolor = 0;
bool ButtonPressed = false;
String currentcolor = "led";

unsigned long previousMillis = 0;
const long interval = 1000;


// the setup routine runs once when you press reset:
void setup() {
  // make the pushbutton's pin an input:
  pinMode(Rpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(buttonPin, INPUT);
  // initialize serial communication at 9600 bits per second:
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
  }

  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
  }
  if(ledState == LOW){
    ledState = HIGH;
  }

  else{
    ledState =LOW;
  }

  if(ledcolor == 0){
    digitalWrite(Rpin, HIGH);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, HIGH);
  }

  else if(ledcolor == 1){
    currentcolor = "Red";
    if(ledState == LOW){
      digitalWrite(Rpin, LOW);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, HIGH);
    }
    else{
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, HIGH);
    }
  }

  else if(ledcolor == 2){
    currentcolor = "Green";
    if(ledState == LOW){
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, LOW);
      digitalWrite(Gpin, HIGH);
    }
    else{
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, HIGH);
    }
  }

  else if(ledcolor == 3){
    currentcolor = "Blue";
    if(ledState == LOW){
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, LOW);
    }
    else{
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, HIGH);
    }
  }

   else if(ledcolor == 4){
    currentcolor = "Yellow";
    if(ledState == LOW){
      digitalWrite(Rpin, LOW);
      digitalWrite(Bpin, LOW);
      digitalWrite(Gpin, HIGH);
    }
    else{
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, HIGH);
    }
  }

  else if(ledcolor == 5){
    currentcolor = "Cyan";
    if(ledState == LOW){
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, LOW);
      digitalWrite(Gpin, LOW);
    }
    else{
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, HIGH);
    }
  }

  else if(ledcolor == 6){
    currentcolor = "Purple";
    if(ledState == LOW){
      digitalWrite(Rpin, LOW);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, LOW);
    }
    else{
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, HIGH);
    }
  }

  else if(ledcolor == 7){
    currentcolor = "White";
    if(ledState == LOW){
      digitalWrite(Rpin, LOW);
      digitalWrite(Bpin, LOW);
      digitalWrite(Gpin, LOW);
    }
    else{
      digitalWrite(Rpin, HIGH);
      digitalWrite(Bpin, HIGH);
      digitalWrite(Gpin, HIGH);
    }
  }

  else if(ledcolor == 8){
    ledcolor = 0;
  }

  //Serial.println(buttonState);
  //delay(1);  // delay in between reads for stability
}
