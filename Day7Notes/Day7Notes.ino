// Photoresistor w/ 220 Ohm Resistor
int PR;
int PRpin=A0;
int Ypin = 6;
float write_val;
void setup() {
  pinMode(PRpin,INPUT);
  Serial.begin(9600);
  pinMode(Ypin, OUTPUT);
}

void loop() {
  PR = analogRead(PRpin);
  // map the PR value from 20 to 120 to 1023 to 0 as we want light to
  // turn on as it gets darker
  if (PR < 20) {
    PR = 20;
  }
  if (PR > 115){
    PR = 115;
  }
  write_val = map(PR, 20, 115, 1023, 0);
  Serial.println(PR);
  analogWrite(Ypin,write_val);
}
