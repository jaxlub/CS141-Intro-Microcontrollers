int Rpin=7; // Red LED
int Gpin=6; // Yellow LED
double V; // read value
double W; // write value

void setup() {
pinMode(Rpin, OUTPUT); // initializae
pinMode(Gpin, OUTPUT); 
pinMode(A0, INPUT);
Serial.begin(9600); 

}
void loop() {
  Serial.println("How bright do you want the LED (0-255)?");
  while (Serial.available() == 0){}
  V = Serial.parseInt(); // read int into V 
  if (V > 255){
    Serial.println("Error: Too High");
    V = 255;
  }
  if (V < 0){
    Serial.println("Error: too Low");
    V = 0;
  }
  // V = analogRead(A0); // read in from POT
  W = V*255/1023;
  analogWrite(Gpin, W);
  /*
  if (W > 200){
    digitalWrite(Rpin, HIGH);
    analogWrite(Gpin,0);
    delay(200);
    digitalWrite(Rpin, LOW);
  }
  */
  /*
  while (W > 200){
    analogWrite(Gpin, 0);
    digitalWrite(Rpin, HIGH);
    V = analogRead(A0);
    W = V*255/1023;
    delay(200);
  }
  digitalWrite(Rpin, LOW);
  */
}
