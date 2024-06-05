/*
 * This code uses joystick with a servo motor and 2 leds. 
 * Any y joystick movement moves servo motor while x joystick movement causes impacts led brightness.
 * Pushing the switch causes alternate led brightness.
 */

int VRx = A0;
int VRy = A1;
int swtch = 9;
int readX;
int readY;
int readS;
int ledG = 3;
int ledR = 6;
int ledbright;

#include <Servo.h>
Servo spinner;
int servopin = 5;
int servoAng; // value to write to servo 0 to 180.

void setup() {
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(servopin,OUTPUT);
  spinner.attach(servopin);
  pinMode(swtch, INPUT);

  pinMode(ledR, OUTPUT);
  pinMode(ledG,OUTPUT);
}

void loop() {
    digitalWrite(swtch,HIGH);
    readX = analogRead(VRx);
    readY = analogRead(VRy);
    readS = digitalRead(swtch);
    ledbright = map(readX,0,1023,0,255);
    if( readS == 0){
      analogWrite(ledG,ledbright);
      analogWrite(ledR,0);
    } else {
      analogWrite(ledR, ledbright);
      analogWrite(ledG,0);

    }
    servoAng = map(readY,0,1023,0,180);
    spinner.write(servoAng);
    Serial.println(readS);
}
