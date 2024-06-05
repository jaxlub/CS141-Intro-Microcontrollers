void setup() {
  pinMode(7, OUTPUT); // Pin 7 is connected to Red
  pinMode(8, OUTPUT); // Pin 8 is connected to Yellow
  pinMode(9,OUTPUT); // Pin 9 is connected to Green
  
}

void loop() {
  // Turn on red light for 200 ms
  digitalWrite(7,HIGH);
  delay(200);
  // Turn off red light
  digitalWrite(7,LOW);

  // Turn on yellow light for 200 ms
  digitalWrite(8,HIGH);
  delay(200);
  // Turn off yellow light
  digitalWrite(8,LOW);
  delay(200);

  // Turn on green light for 200 ms
  digitalWrite(9,HIGH);
  delay(200);
  // Turn off green light
  digitalWrite(9,LOW);
  delay(200);

  // Turn all 3 lights on for 300 ms
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(300);

  // Turn off all 3 lights for 300 ms
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(300);
  // repeat on/off twice more
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(300);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(300);  
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  delay(300);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  // Lights are turned off and then delayed for 3 s before beginning pattern.
  delay(3000);
}
