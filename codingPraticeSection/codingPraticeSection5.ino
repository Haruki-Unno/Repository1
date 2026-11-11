// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 3;

int buttonState = 0;  // variable for reading the pushbutton status
bool buttonPressed = false;
int ledcolor = 0;

unsigned long previousMillis = 0;
unsigned long interval = 1000;
int ledState = LOW;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && !buttonPressed) {
    ledcolor++;
    buttonPressed = true;
  } 
  else if(buttonState == LOW && buttonPressed){
    buttonPressed = false;
  }

  unsigned long currentMillis = millis();
  if(ledcolor > 0 && currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    if(ledState == LOW){
      ledState = HIGH;
    }
    else{
      ledState = LOW;
    }
  }

  if(ledcolor == 0){
    if(ledState == LOW){
      digitalWrite(ledPin, LOW);
    }
    else{
      digitalWrite(ledPin, LOW);
    }

  }
  else if(ledcolor == 1){
    interval = 1000;
    if(ledState == LOW){
      digitalWrite(ledPin, LOW);
    }
    else{
      digitalWrite(ledPin, HIGH);
    }
  }
  else if(ledcolor == 2){
    interval = 500;
    if(ledState == LOW){
      digitalWrite(ledPin, LOW);
    }
    else{
      digitalWrite(ledPin, HIGH);
    }
  }
  else if(ledcolor == 3){
    interval =250;
    if(ledState == HIGH){
      digitalWrite(ledPin, LOW);
    }
    else{
      digitalWrite(ledPin, HIGH);
    }
  }
  else if(ledcolor == 4){
    ledcolor = 0;
  }

  Serial.print("color: ");
  Serial.println(ledcolor);
}
