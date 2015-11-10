/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  A8;      // the number of the LED pin
const int survoPin = 22;     // the number of the survo
const int potpin = A0;        // the number of the podometer

// variables will change:
int buttonState = 0;
const int startpos = 0;
const int endpos = 180;
int val = 0;
int potval = 0;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(ledPin, OUTPUT);  // initialize the LED pin as an output:
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input:
  pinMode(potpin, INPUT);
  myservo.attach(survoPin);  // attaches the servo on pin 22 to the servo object  
  myservo.write(startpos);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {         
    analogWrite(ledPin, 255);        // turn LED on
    myservo.write(endpos);              // tell servo to go to position in variable 'pos' 
    delay(150);    // waits 15ms for the servo to reach the position 
    //myservo.write(startpos);  
  } 
  else {
    // turn LED off:
    //digitalWrite(ledPin, LOW);                          
    val = analogRead(potpin);
    val = map(val, 0, 1023, 0, 90);
    myservo.write(val);
    delay(15);
    
    //LED fade
    potval = analogRead(potpin);
    brightness = map(potval,0,1023,0,255);
    
    analogWrite(ledPin, brightness);                          
    brightness = brightness +fadeAmount;
    if (brightness ==0 || brightness ==255){
      fadeAmount= -fadeAmount;
    }
    delay(30);

  }
}


