/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

int Rpin = 3;         // the PWM pin the LED is attached to
int Bpin = 4;
int Gpin = 5;
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by
int ledcolor = 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(Rpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if(ledcolor == 0){
    analogWrite(Rpin, brightness);
    analogWrite(Bpin, 255);
    analogWrite(Gpin, 255);
  }

  if(ledcolor == 1){
    analogWrite(Rpin, 255);
    analogWrite(Bpin, brightness);
    analogWrite(Gpin, 255);
  }

  if(ledcolor == 2){
    analogWrite(Rpin, 255);
    analogWrite(Bpin, 255);
    analogWrite(Gpin, brightness);
  }
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    if(brightness >= 255){
      ledcolor+=1;
      if(ledcolor == 2){
        ledcolor = 0;
      }
    }
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
