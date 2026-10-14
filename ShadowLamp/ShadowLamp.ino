// declaration
const int button = 2; // check this line if correct
// if using analog pin, be careful to use correct pin. 
const int RedPin = 9;
const int BluePin = 10;
const int GreenPin = 11;

int buttonState = 0; // 
int ledcolor = 0; // the color change depending on this number
bool buttonPressed = false; // this stands for if button is pressed
String currentcolor = "led";

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  Serial.begin(9600);
  // use clear container for frame.
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button); // return type: int
  Serial.print("color: ");
  Serial.println(currentcolor);
  // button is pressed
  if(buttonState == HIGH && !buttonPressed){
    ledcolor++;
    buttonPressed = true;
  }
  // button is released
  if(buttonState == LOW && buttonPressed){
    buttonPressed = false;
  }
  // use analogWrite to make pink light
  switch (ledcolor) {
    case 0:
      currentcolor = "NONE";
      analogWrite(RedPin, 255);
      analogWrite(BluePin, 255);
      analogWrite(GreenPin, 255);
      break;
    case 1:
      currentcolor = "PINK";
      analogWrite(RedPin, 0);
      analogWrite(BluePin, 72);
      analogWrite(GreenPin, 148);
      break;
    case 2:
      currentcolor = "GREEN";
      analogWrite(RedPin, 255);
      analogWrite(BluePin, 255);
      analogWrite(GreenPin, 150);
      break;
    case 3:
      currentcolor = "RED";
      analogWrite(RedPin, 46);
      analogWrite(BluePin, 255);
      analogWrite(GreenPin, 255);
      break;
    case 4:
      currentcolor = "YELLOW";
      analogWrite(RedPin, 0);
      analogWrite(BluePin, 255);
      analogWrite(GreenPin, 0);
      break;
    case 5:
      currentcolor = "WHITE";
      analogWrite(RedPin, 0);
      analogWrite(BluePin, 0);
      analogWrite(GreenPin, 0);
      break;
    case 6:
      ledcolor = 0;
      break;
  }
}
