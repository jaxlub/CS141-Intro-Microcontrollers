int Gled=9;
int j;
void setup() {
pinMode(Gled, OUTPUT);
}

void loop() {
  analogWrite(Gled, 125);
}
