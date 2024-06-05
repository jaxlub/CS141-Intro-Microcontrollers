int rpin = 8; // Digital read pin
int led = 4;
int oldsw_state=0; // current switch state
int newsw_state; // old switch state
int led_state=0; //is the LED on or off

void setup() {
pinMode(rpin, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);

}

void loop() {
  newsw_state = digitalRead(rpin);
  delay(100);
  if(newsw_state == 1 && oldsw_state == 0){
    if(led_state == 0){
      digitalWrite(led, HIGH);
      led_state = 1;
    } else {
      digitalWrite(led,LOW);
      led_state = 0; 
    }
  }
  oldsw_state = newsw_state;
  delay(100);
  
}
