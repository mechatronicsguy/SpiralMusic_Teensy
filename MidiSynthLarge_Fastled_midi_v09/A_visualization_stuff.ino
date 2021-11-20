

void viz_setup() {
  for (int i = 0; i < 256 ; i++) {
    note_status[i] = -1;
  }

  led_setup();

  Serial.println("Booted.");
}

void viz_loop() {
  midi_display();
}

void midi_display() {
  display_update();
}


void vizNoteOn(byte channel, byte note, byte velocity) {
  if (channel == 10) {
    return;
  }
    note_status[note ] = channel;
    note_seal[note ] = true;
}

void vizNoteOff(byte channel, byte note, byte velocity) {
    note_status[note ] = -1;
}

void vizAllNotesOff() {
  for (int i = 0 ; i < 256; i++) {
    note_status[i ] = 0;
    note_seal[i ] = false;
  }
}
