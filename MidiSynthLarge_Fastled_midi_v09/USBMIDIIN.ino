void usb_midi_in_setup() {
  myusb.begin();

  midi1.setHandleNoteOn(usbmidi_in_myNoteOn);
  midi1.setHandleNoteOff(usbmidi_in_myNoteOff);
  midi1.setHandleAfterTouchPoly(usbmidi_in_myAfterTouchPoly);
  midi1.setHandleControlChange(usbmidi_in_myControlChange);
  midi1.setHandleProgramChange(usbmidi_in_myProgramChange);
  midi1.setHandleAfterTouchChannel(usbmidi_in_myAfterTouchChannel);
  midi1.setHandlePitchChange(usbmidi_in_myPitchChange);
  // Only one of these System Exclusive handlers will actually be
  // used.  See the comments below for the difference between them.
  midi1.setHandleSystemExclusive(usbmidi_in_mySystemExclusiveChunk);
  midi1.setHandleSystemExclusive(usbmidi_in_mySystemExclusive);
  midi1.setHandleTimeCodeQuarterFrame(usbmidi_in_myTimeCodeQuarterFrame);
  midi1.setHandleSongPosition(usbmidi_in_mySongPosition);
  midi1.setHandleSongSelect(usbmidi_in_mySongSelect);
  midi1.setHandleTuneRequest(usbmidi_in_myTuneRequest);
  midi1.setHandleClock(usbmidi_in_myClock);
  midi1.setHandleStart(usbmidi_in_myStart);
  midi1.setHandleContinue(usbmidi_in_myContinue);
  midi1.setHandleStop(usbmidi_in_myStop);
  midi1.setHandleActiveSensing(usbmidi_in_myActiveSensing);
  midi1.setHandleSystemReset(usbmidi_in_mySystemReset);
  // This generic System Real Time handler is only used if the
  // more specific ones are not set.
  midi1.setHandleRealTimeSystem(usbmidi_in_myRealTimeSystem);
}

void usb_midi_in_loop(){
   myusb.Task();
  midi1.read();
}

/* Receive Incoming USB Host MIDI using functions.  As usbMIDI
   reads incoming messages, handler functions are run.
   See the InputRead example for the non-function alterative.

   This very long example demonstrates all possible handler
   functions.  Most applications need only some of these.
   This example is meant to allow easy copy-and-paste of the
   desired functions.

   Use the Arduino Serial Monitor to view the messages
   as Teensy receives them by USB MIDI

   You must select MIDI from the "Tools > USB Type" menu

   This example code is in the public domain.
*/


void usbmidi_in_myNoteOn(byte channel, byte note, byte velocity) {
  // When a USB device with multiple virtual cables is used,
  // midi1.getCable() can be used to read which of the virtual
  // MIDI cables received this message.
//  Serial.print("Note On, ch=");
//  Serial.print(channel, DEC);
//  Serial.print(", note=");
//  Serial.print(note, DEC);
//  Serial.print(", velocity=");
//  Serial.println(velocity, DEC);
//  keyboardNoteOnOff(channel,note,velocity,true);
  OnNoteOn(channel,note,velocity);
}

void usbmidi_in_myNoteOff(byte channel, byte note, byte velocity) {
//  Serial.print("Note Off, ch=");
//  Serial.print(channel, DEC);
//  Serial.print(", note=");
//  Serial.print(note, DEC);
//  Serial.print(", velocity=");
//  Serial.println(velocity, DEC);
//  keyboardNoteOnOff(channel,note,velocity,false);
    OnNoteOff(channel,note,velocity);

}

void usbmidi_in_myAfterTouchPoly(byte channel, byte note, byte velocity) {
//  Serial.print("AfterTouch Change, ch=");
//  Serial.print(channel, DEC);
//  Serial.print(", note=");
//  Serial.print(note, DEC);
//  Serial.print(", velocity=");
//  Serial.println(velocity, DEC);
}

void usbmidi_in_myControlChange(byte channel, byte control, byte value) {
//  Serial.print("Control Change, ch=");
//  Serial.print(channel, DEC);
//  Serial.print(", control=");
//  Serial.print(control, DEC);
//  Serial.print(", value=");
//  Serial.println(value, DEC);
}

void usbmidi_in_myProgramChange(byte channel, byte program) {
//  Serial.print("Program Change, ch=");
//  Serial.print(channel, DEC);
//  Serial.print(", program=");
//  Serial.println(program, DEC);
}

void usbmidi_in_myAfterTouchChannel(byte channel, byte pressure) {
//  Serial.print("After Touch, ch=");
//  Serial.print(channel, DEC);
//  Serial.print(", pressure=");
//  Serial.println(pressure, DEC);
}

void usbmidi_in_myPitchChange(byte channel, int pitch) {
//  Serial.print("Pitch Change, ch=");
//  Serial.print(channel, DEC);
//  Serial.print(", pitch=");
//  Serial.println(pitch, DEC);
}


// This 3-input System Exclusive function is more complex, but allows you to
// process very large messages which do not fully fit within the midi1's
// internal buffer.  Large messages are given to you in chunks, with the
// 3rd parameter to tell you which is the last chunk.  This function is
// a Teensy extension, not available in the Arduino MIDI library.
//
void usbmidi_in_mySystemExclusiveChunk(const byte *data, uint16_t length, bool last) {
//  Serial.print("SysEx Message: ");
//  printBytes(data, length);
//  if (last) {
//    Serial.println(" (end)");
//  } else {
//    Serial.println(" (to be continued)");
//  }
}

// This simpler 2-input System Exclusive function can only receive messages
// up to the size of the internal buffer.  Larger messages are truncated, with
// no way to receive the data which did not fit in the buffer.  If both types
// of SysEx functions are set, the 3-input version will be called by midi1.
//
void usbmidi_in_mySystemExclusive(byte *data, unsigned int length) {
//  Serial.print("SysEx Message: ");
//  printBytes(data, length);
//  Serial.println();
}

void usbmidi_in_myTimeCodeQuarterFrame(byte data) {
//  static char SMPTE[8]={'0','0','0','0','0','0','0','0'};
//  static byte fps=0;
//  byte index = data >> 4;
//  byte number = data & 15;
//  if (index == 7) {
//    fps = (number >> 1) & 3;
//    number = number & 1;
//  }
//  if (index < 8 || number < 10) {
//    SMPTE[index] = number + '0';
//    Serial.print("TimeCode: ");  // perhaps only print when index == 7
//    Serial.print(SMPTE[7]);
//    Serial.print(SMPTE[6]);
//    Serial.print(':');
//    Serial.print(SMPTE[5]);
//    Serial.print(SMPTE[4]);
//    Serial.print(':');
//    Serial.print(SMPTE[3]);
//    Serial.print(SMPTE[2]);
//    Serial.print('.');
//    Serial.print(SMPTE[1]);  // perhaps add 2 to compensate for MIDI latency?
//    Serial.print(SMPTE[0]);
//    switch (fps) {
//      case 0: Serial.println(" 24 fps"); break;
//      case 1: Serial.println(" 25 fps"); break;
//      case 2: Serial.println(" 29.97 fps"); break;
//      case 3: Serial.println(" 30 fps"); break;
//    }
//  } else {
//    Serial.print("TimeCode: invalid data = ");
//    Serial.println(data, HEX);
//  }
}

void usbmidi_in_mySongPosition(uint16_t beats) {
//  Serial.print("Song Position, beat=");
//  Serial.println(beats);
}

void usbmidi_in_mySongSelect(byte songNumber) {
//  Serial.print("Song Select, song=");
//  Serial.println(songNumber, DEC);
}

void usbmidi_in_myTuneRequest() {
//  Serial.println("Tune Request");
}

void usbmidi_in_myClock() {
//  Serial.println("Clock");
}

void usbmidi_in_myStart() {
//  Serial.println("Start");
}

void usbmidi_in_myContinue() {
//  Serial.println("Continue");
}

void usbmidi_in_myStop() {
//  Serial.println("Stop");
}

void usbmidi_in_myActiveSensing() {
//  Serial.println("Actvice Sensing");
}

void usbmidi_in_mySystemReset() {
//  Serial.println("System Reset");
}

void usbmidi_in_myRealTimeSystem(uint8_t realtimebyte) {
//  Serial.print("Real Time Message, code=");
//  Serial.println(realtimebyte, HEX);
}


//
//void usbmidi_in_printBytes(const byte *data, unsigned int size) {
//  while (size > 0) {
//    byte b = *data++;
//    if (b < 16) Serial.print('0');
//    Serial.print(b, HEX);
//    if (size > 1) Serial.print(' ');
//    size = size - 1;
//  }
//}
