const int buttonPin = 2;
const int RLedPin = 9;
const int GLedPin = 10;
const int BLedPin = 11;

int buttonState = 0;
bool buttonPressed = false;

unsigned long pressingTime = 0;
const int longPressInterval = 1200;

int lightNum = 0;
int RLightColor = 0;
int GLightColor = 0;
int BLightColor = 0;
int RCurrentColor = 0;
int GCurrentColor = 0;
int BCurrentColor = 0;

// blink
int currentMode = 0;
unsigned long blinkTimer = 0;
const int blinkInterval = 500;
bool blinkOn = true;

// fade
const int fadeAmount = 2;
int fadeDirection = 1;

// rainbow
int rainbowPhase = 0;
int rainbowValue = 0;
unsigned long RpreviousMillis = 0;
const int rainbowInterval = 3;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RLedPin, OUTPUT);
  pinMode(GLedPin, OUTPUT);
  pinMode(BLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  checkButton();
  updateLEDColor();
  setRGBLEDColor(RCurrentColor, GCurrentColor, BCurrentColor);
}

void setRGBLEDColor(int r, int g, int b){
  analogWrite(RLedPin, r);
  analogWrite(GLedPin, g);
  analogWrite(BLedPin, b);
}

void checkButton(){
  buttonState = digitalRead(buttonPin);
  //Serial.println(buttonState);

  if(buttonState == LOW && !buttonPressed){
    pressingTime = millis();
    buttonPressed = true;
  }
  if(buttonState == HIGH && buttonPressed){
    unsigned long currentTime = millis();

    Serial.print("Time = ");
    Serial.println(currentTime - pressingTime);
    if(currentTime - pressingTime < longPressInterval){
      Serial.println("Short Press");
      changeLEDColor();
    }
    else{
      Serial.println("Long Press");
      changeMode();
    }
    buttonPressed = false;
  }
}

void changeLEDColor(){
  lightNum = lightNum + 1;
  if(lightNum >= 5)
      lightNum = 0;
  if(lightNum == 0){
    RLightColor = 0;
    GLightColor = 0;
    BLightColor = 0;
  }
  if(lightNum == 1){
    RLightColor = 0;
    GLightColor = 255;
    BLightColor = 255;
  }
  if(lightNum == 2){
    RLightColor = 255;
    GLightColor = 0;
    BLightColor = 255;
  }
  if(lightNum == 3){
    RLightColor = 255;
    GLightColor = 255;
    BLightColor = 0;
  }
  if(lightNum == 4){
    RLightColor = 0;
    GLightColor = 0;
    BLightColor = 255;
  }
  RCurrentColor = RLightColor;
  GCurrentColor = GLightColor;
  BCurrentColor = BLightColor;
}

void changeMode(){
  currentMode = currentMode + 1;

  if(currentMode >= 4){
    currentMode = 0;
  }

  if(currentMode == 1){
    blinkTimer = 0;
    blinkOn = true;
  }
}

void updateLEDColor(){
  if(currentMode == 0){
    // Constant Light Mode
    RCurrentColor = RLightColor;
    GCurrentColor = GLightColor;
    BCurrentColor = BLightColor;
  }

  else if(currentMode == 1){
    unsigned long currentTime = millis();

    if(currentTime - blinkTimer > blinkInterval){
      blinkOn = !blinkOn;
      blinkTimer = currentTime;
    }

    if(blinkOn){
      RCurrentColor = RLightColor;
      GCurrentColor = GLightColor;
      BCurrentColor = BLightColor;
    }
    else{
      RCurrentColor = 255;
      GCurrentColor = 255;
      BCurrentColor = 255;
    }
  }

  else if(currentMode == 2){
    bool negativeDir = false;

    //Breathing Light Mode
    //If the light value is 0, then we would need to modify it progressively.
    //Otherwise, just make it 255 will be fine

    if(RLightColor == 0){
      RCurrentColor = RCurrentColor + fadeDirection * fadeAmount;

      if((RCurrentColor > (255 - RLightColor)) || (RCurrentColor < 0)){
        negativeDir = true;
      }

      //make sure the color is within 0 ~ 255
      if(RCurrentColor < 0) RCurrentColor = 0;
      if(RCurrentColor > 255) RCurrentColor = 255;
    }

    if(GLightColor == 0){
      GCurrentColor = GCurrentColor + fadeDirection * fadeAmount;

      if((GCurrentColor > (255 - GLightColor)) || (GCurrentColor < 0)){
        negativeDir = true;
      }

      //make sure the color is within 0 ~ 255
      if(GCurrentColor < 0) GCurrentColor = 0;
      if(GCurrentColor > 255) GCurrentColor = 255;
    }

    if(BLightColor == 0){
      BCurrentColor = BCurrentColor + fadeDirection * fadeAmount;

      if((BCurrentColor > (255 - BLightColor)) || (BCurrentColor < 0)){
        negativeDir = true;
      }

      //make sure the color is within 0 ~ 255
      if(BCurrentColor < 0) BCurrentColor = 0;
      if(BCurrentColor > 255) BCurrentColor = 255;
    }

    if(negativeDir)
      fadeDirection = -fadeDirection;

    delay(10);
  }
  else if(currentMode == 3){
    unsigned long RcurrentMillis = millis();
    if(RcurrentMillis - RpreviousMillis >= rainbowInterval){
      RpreviousMillis = RcurrentMillis;
      rainbowValue++;
      if(rainbowValue >= 255){
        rainbowValue = 0;
        rainbowPhase++;
        if(rainbowPhase > 5){
          rainbowPhase = 0;
        }
      }
      if(rainbowPhase == 0){
        RCurrentColor = 255;
        GCurrentColor = rainbowValue;
        BCurrentColor = 0;
      }

      else if(rainbowPhase == 1){
        RCurrentColor = 255 - rainbowValue;
        GCurrentColor = 255;
        BCurrentColor = 0;
      }

      else if(rainbowPhase == 2){
        RCurrentColor = 0;
        GCurrentColor = 255;
        BCurrentColor = rainbowValue;
      }

      else if(rainbowPhase == 3){
        RCurrentColor = 0;
        GCurrentColor = 255 - rainbowValue;
        BCurrentColor = 255;
      }

      else if(rainbowPhase == 4){
        RCurrentColor = rainbowValue;
        GCurrentColor = 0;
        BCurrentColor = 255;
      }

      else if(rainbowPhase == 5){
        RCurrentColor = 255;
        GCurrentColor = 0;
        BCurrentColor = 255 - rainbowValue;
      }
    }
  }
  
}