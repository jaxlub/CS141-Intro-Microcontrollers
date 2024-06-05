#include "pitches.h"//this will access the library we created above
int j; //this will be a counter variable
int noteDuration;//we will use this to calculate a note length
int noteTime=1000;//we can change the overall speed of the tune by adjusting this.
//using 1000 would give a whole note that lasts 1 second or 1000ms
int length_; // number of notes in song - user entered value
int i; // counter in for loop
int temp_note; // temporary variable to store user entered note in before adding to array
int temp_dur; // temporary variable to store user entered note duratopm in before adding to array

void setup() {
  Serial.begin(9600);
  Serial.println("Enter # of notes in your tune?"); // message for user
  while (Serial.available() <1 ){} // Wait for user to enter something
  length_= Serial.parseInt(); // read int into Notes Array
  int note[length_]; // initialize array for notes
  int melody[length_]; // initialze array for durations
  for(i = 0; i < length_;i = i +1){ // loop through all notes and ask for note val and duration val
     Serial.print("Enter note for ");
     Serial.println(i);
     while (Serial.available() <1){} // Wait for user to enter something
     temp_note = Serial.parseInt(); // get value
     melody[i] = temp_note; // add to array
     
     Serial.print("Enter note length for "); // ex if user enters 2 then it is a half note
     Serial.println(i);
     while (Serial.available() < 1){} // Wait for user to enter something
     temp_dur = Serial.parseInt(); // get value
     note[i] = temp_dur; // add to array
  }

  
  for (i = 0; i < length_; i++) { // loop through every note aka lenght_
    // to calculate the note duration, take noteTime which is set to one second (1000ms)
    // and divide by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //We can make the tune tempo faster by using a smaller time than 1s
    // or slower by using a larger number
    noteDuration = noteTime / note[i];
    tone(8, melody[i], noteDuration);//tone is a new Arduino command, pin 8 is our buzzer
    //You can change the overall pitch of the tone by multiplying or dividing melody[j] by a
    //number.
    // We need to pause between notes or it sounds weird
    // In the example below we multiply the note duration by 1.3
    int pause = noteDuration * 1.30;
    delay(pause);
    // stop the tone playing:
    noTone(8);
  }


}

void loop() {
}
