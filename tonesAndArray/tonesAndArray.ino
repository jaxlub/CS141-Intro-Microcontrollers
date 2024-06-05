//* Plays a melody – speaker is on digital pin 8 */
#include "pitches.h"//this will access the library we created above
int j; //this will be a counter variable
int noteDuration;//we will use this to calculate a note length
int noteTime=1000;//we can change the overall speed of the tune by adjusting this.
//using 1000 would give a whole note that lasts 1 second or 1000ms
// Below we declare the array melody[] which will hold the notes in our tune. .
int melody[] = {
NOTE_D3, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_G3, NOTE_FS3,
NOTE_D3, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_A3, NOTE_G3,
NOTE_D3, NOTE_D3, NOTE_D4, NOTE_B3, NOTE_G3, NOTE_FS3, NOTE_E3,
NOTE_C4, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_A3, NOTE_G3
};
// A musical rest would be a 0, where no note would play.
// note durations: Each note has a duration as described in the table above.
//below we declare a new array that will hold the length of time each note plays.
int noteDurations[] = {
8, 8,4,4,4,2,
8, 8,4,4,4,2,
8, 8,4, 4,4,4,4,
8, 8,4,4,4,2
};
void setup() {
// iterate over the notes of the melody In our tune we have 25 notes, each with a
//duration. We iterate from 0 to 24 to hold our 25 notes.
for (j = 0; j < 25; j++) {
// to calculate the note duration, take noteTime which is set to one second (1000ms)
// and divide by the note type.
//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//We can make the tune tempo faster by using a smaller time than 1s
// or slower by using a larger number
noteDuration = noteTime / noteDurations[j];
tone(8, melody[j], noteDuration);//tone is a new Arduino command
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
// no need to repeat the melody.
}
