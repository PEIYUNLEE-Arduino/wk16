#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_E5,NOTE_E5,NOTE_E5,NOTE_C5,NOTE_E5,  NOTE_G5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations=150;

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 6; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    //int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDurations);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDurations * 1.30;
    if (thisNote==2||thisNote==4){
       delay(pauseBetweenNotes);
       delay(pauseBetweenNotes);
    }
    else if(thisNote==5){
       delay(pauseBetweenNotes*20);
    }
    else delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
