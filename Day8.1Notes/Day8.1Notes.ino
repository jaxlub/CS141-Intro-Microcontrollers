// button notes
int rpin = 11;
int x;
void setup() {
  pinMode(rpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  x = digitalRead(rpin);
  Serial.println(x);

}
