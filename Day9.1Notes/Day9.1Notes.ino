// little buggy :)

int rpin = 8;
int led = 5;
int sw;
int bright_val = 1;
int buzzer = 4;

int rpin2 = 2;
int sw2;

void setup() {
  pinMode(rpin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(rpin2, INPUT);
  Serial.begin(9600);
}

void loop() {
   sw = digitalRead(rpin);
   sw2 = digitalRead(rpin2);
   delay(50);
   if (sw == 1 || sw2 == 1){
      if(bright_val >= 255){
        digitalWrite(buzzer, HIGH);
        delay(100);
        bright_val = 255;
        digitalWrite(buzzer,LOW);
      }
      if(bright_val < 0){
        digitalWrite(buzzer, HIGH);
        delay(100);
        bright_val = 0;
        digitalWrite(buzzer,LOW);
      }
      if (sw == 1){
        bright_val = bright_val + 10;
        analogWrite(led, bright_val);
        sw == 0;
      }
      if (sw2 == 1){
        bright_val = bright_val - 10;
        analogWrite(led, bright_val);
        sw2 == 0;
      }  
   }
   delay(50);
}
