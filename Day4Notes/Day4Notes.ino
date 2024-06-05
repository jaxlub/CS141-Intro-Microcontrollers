// Voltage Divider
int pin = 3;
int readpin = A0;
double V;
void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(readpin, INPUT);

}

void loop() {
  analogWrite(pin,250);
   V = analogRead(A0); // reads value 0 to 1023 not an actual voltage
  Serial.println("Voltage " + String(V *  5 / 1023)); // calculate voltage of 5V * 
  delay(1000);

}
