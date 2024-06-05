int buzz = 10; // Pin for buzzer
int i;
void setup() {
  pinMode(buzz, OUTPUT); // initialize buzzer
}

void loop() {
  /*
   * F = period/second
   * F = 784 Hz
   * Then in one second we have 784 periods but we want .8 seconds
   * so we want 627 total cycles (784 *.8)
   * Then we want to calculate how long to delay for:
   * .8 second / 627 loops/ 2 (for delay on/off) * 1 million microseconds
   * = 638 microseconds
   */
  for(i= 0; i < 627; i = i+1){ // loop 627 times for total of 800 ms
    delayMicroseconds(638); 
    analogWrite(buzz,255); // buzzer on for 638 microsecond
    delayMicroseconds(638);
    analogWrite(buzz,0); // buzzer off for 638 microseconds
  }
  
  /*
   * F = period/second
   * F = 587 Hz
   * Then in one second we have 587 periods but we want .8 seconds
   * so we want 470 total cycles (587 *.8)
   * Then we want to calculate how long to delay for:
   * .8 second / 470 loops/ 2 (for delay on/off) * 1 million microseconds
   * = 851 microseconds
   */
  for(i= 0; i < 470; i = i+1){ // loop 470 time for totalof 800 ms
    delayMicroseconds(851); 
    analogWrite(buzz,255); // buzzer on for 851 microseconds
    delayMicroseconds(851); 
    analogWrite(buzz,0); // buzzer off for 851 microseconds
  }
  
  /*
   * F = period/second
   * F = 392 Hz
   * Then in one second we have 587 periods but we want .8 seconds
   * so we want 314 total cycles (392 *.8)
   * Then we want to calculate how long to delay for:
   * .8 second / 314 loops/ 2 (for delay on/off) * 1 million microseconds
   * = 1274 microseconds
   */
  for(i= 0; i < 314; i = i+1){ // loop 314 time for total of 800 ms
    delayMicroseconds(1274);
    analogWrite(buzz,255); // buzzer on for 1274 microseconds
    delayMicroseconds(1274);
    analogWrite(buzz,0); // buzzer off for 1274 microseconds
  }
    /*
   * F = period/second
   * F = 784 Hz
   * Then in one second we have 784 periods but we want .8 seconds
   * so we want 627 total cycles (784 *.8)
   * Then we want to calculate how long to delay for:
   * .8 second / 627 loops/ 2 (for delay on/off) * 1 million microseconds
   * = 638 microseconds
   */
  for(i= 0; i < 627; i = i+1){ // loop 627 times for total of 800 ms
    delayMicroseconds(638); 
    analogWrite(buzz,255); // buzzer on for 638 microsecond
    delayMicroseconds(638);
    analogWrite(buzz,0); // buzzer off for 638 microseconds
  }



 // Repeat sequence of 3 notes again
  /*
   * F = period/second
   * F = 587 Hz
   * Then in one second we have 587 periods but we want .8 seconds
   * so we want 470 total cycles (587 *.8)
   * Then we want to calculate how long to delay for:
   * .8 second / 470 loops/ 2 (for delay on/off) * 1 million microseconds
   * = 851 microseconds
   */
  for(i= 0; i < 470; i = i+1){ // loop 470 time for totalof 800 ms
    delayMicroseconds(851); 
    analogWrite(buzz,255); // buzzer on for 851 microseconds
    delayMicroseconds(851); 
    analogWrite(buzz,0); // buzzer off for 851 microseconds
  }
  
  /*
   * F = period/second
   * F = 392 Hz
   * Then in one second we have 587 periods but we want .8 seconds
   * so we want 314 total cycles (392 *.8)
   * Then we want to calculate how long to delay for:
   * .8 second / 314 loops/ 2 (for delay on/off) * 1 million microseconds
   * = 1274 microseconds
   */
  for(i= 0; i < 314; i = i+1){ // loop 314 time for total of 800 ms
    delayMicroseconds(1274);
    analogWrite(buzz,255); // buzzer on for 1274 microseconds
    delayMicroseconds(1274);
    analogWrite(buzz,0); // buzzer off for 1274 microseconds
  }
  
  delay(1000); // delay for 1 second
}
