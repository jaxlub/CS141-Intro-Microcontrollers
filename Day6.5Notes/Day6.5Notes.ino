/*
  Passive Buzzer Song
  Plays a longer melody using a passive buzzer.
*/

#define BUZZER_PIN  11 // Define the pin number for the buzzer

void setup() {
  pinMode(BUZZER_PIN, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  // Play the melody
  playMelody();
}

void playMelody() {
  // Define the notes and their durations (in milliseconds)
  int melody[] = {262, 294, 330, 349, 392, 440, 494, 523, // C4, D4, E4, F4, G4, A4, B4, C5
                  587, 659, 698, 784, 880, 988, 1047,    // D5, E5, F5, G5, A5, B5, C6
                  1175, 1319, 1397, 1568, 1760, 1976, 2093}; // D6, E6, F6, G6, A6, B6, C7
  int noteDuration = 200; // Duration of each note
  
  // Play each note in the melody
  for (int i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
    tone(BUZZER_PIN, melody[i]); // Play the current note
    delay(noteDuration); // Wait for the note duration
    noTone(BUZZER_PIN); // Stop the note
    delay(50); // Add a short pause between notes
  }
  delay(1000); // Add a longer pause between repetitions of the melody
}
