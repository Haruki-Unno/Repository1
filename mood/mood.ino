// pin
const int buttonPin = 2;
const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;

// mood
int mood = 0;
const int neutralMood = 10;
const int rainbowMood = 20;

// rainbow
int colorNumber = 0;
int colorStep = 0;
unsigned long rainbowTimer = 0;

// settings
int buttonState = 0;
bool ButtonPressed = false;
unsigned long touchedTimer = 0;
unsigned long reducedTimer = 0;
const long untouchInterval = 5000;
unsigned long reducedInterval = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  Serial.begin(9600);

  mood = neutralMood;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mood >= rainbowMood){
    showRainbow();
  }
  else{
    showLEDState(mood);
    colorNumber = 0;
    colorStep = 0;
  }

  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH && !ButtonPressed){
    mood++;
    if(mood > 20) mood = 20;
      touchedTimer = millis();
      ButtonPressed = true;
  }
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }

  unsigned long currentTimer = millis();
  if(currentTimer - touchedTimer > untouchInterval){
    unsigned long vacantTime = currentTimer - touchedTimer;
    if(vacantTime < 15000){
      reducedInterval = 3000;
    }
    else{
      reducedInterval = 1000;
    }
    if(currentTimer - reducedTimer > reducedInterval){
      mood = mood - 1;
      if(mood < 0) mood = 0;
      reducedTimer = currentTimer;
    }
  }
  Serial.print("Mood: ");
  Serial.println(mood);
}

void showLEDState(int state){
  float brightnessInterval = 255/10.0;
  if(state >= neutralMood){
    analogWrite(RledPin, 0);
    analogWrite(GledPin, 255 - brightnessInterval * (state - neutralMood));
    analogWrite(BledPin, brightnessInterval * (state - neutralMood));
  }
  else{
    analogWrite(RledPin, brightnessInterval * (neutralMood - state));
    analogWrite(GledPin, 255 - brightnessInterval * (neutralMood - state));
    analogWrite(BledPin, 0);
  }
}

void showRainbow(){
  if(colorNumber == 0){
    analogWrite(RledPin, 255 - colorStep);
    analogWrite(GledPin, 0);
    analogWrite(BledPin, colorStep);
  }
  else if(colorNumber == 1){
    analogWrite(RledPin, 0);
    analogWrite(GledPin, colorStep);
    analogWrite(BledPin, 255 - colorStep);
  }
  else if(colorNumber == 2){
    analogWrite(RledPin, colorStep);
    analogWrite(GledPin, 255 - colorStep);
    analogWrite(BledPin, 0);
  }

  if(millis() - rainbowTimer > 2){
    colorStep++;
    rainbowTimer = millis();

    if(colorStep > 255){
      colorStep = 0;
      colorNumber++;

      if(colorNumber > 2){
        colorNumber = 0;
      }
    }
  }
}