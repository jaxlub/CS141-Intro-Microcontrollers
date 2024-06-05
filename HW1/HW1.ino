int Rled = 7;
int Yled = 8;
int Gled = 9;
int wait = 500;
int j;

void setup() {
  pinMode(Rled, OUTPUT); // Pin 7 is connected to Red
  pinMode(Yled, OUTPUT); // Pin 8 is connected to Yellow
  pinMode(Gled,OUTPUT); // Pin 9 is connected to Green
  
}

void loop() {
  // Turn on red light for 200 ms
  digitalWrite(Rled,HIGH);
  delay(wait);
  // Turn off red light
  digitalWrite(Rled,LOW);
  delay(wait);

  // Turn on yellow light for 200 ms
  digitalWrite(Yled,HIGH);
  delay(wait);
  // Turn off yellow light
  digitalWrite(Yled,LOW);
  delay(wait);

  // Turn on green light for 200 ms
  digitalWrite(Gled,HIGH);
  delay(wait);
  // Turn off green light
  digitalWrite(Gled,LOW);
  delay(wait);


  for(j=1;j<=4;j=j+1){
   // Turn all 3 lights on for 300 ms
  digitalWrite(Rled,HIGH);
  digitalWrite(Yled,HIGH);
  digitalWrite(Gled,HIGH);
  delay(wait);

  // Turn off all 3 lights for 300 ms
  digitalWrite(Rled,LOW);
  digitalWrite(Yled,LOW);
  digitalWrite(Gled,LOW);
  delay(300);
  }

  // Lights are turned off and then delayed for 3 s before beginning pattern.
  delay(3000);
}
