#include <DMXSerial.h>
#include <MIDIUSB.h>

void setup() {
  // put your setup code here, to run once:
  DMXSerial.init(DMXReceiver);
  //Serial.begin(115200);
}
byte oldvalue[128];
void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(DMXSerial.read(1));
  for (byte i = 0; i < 128; i++) {
    byte value = int(DMXSerial.read(i+1)/2);
    if (value != oldvalue[i]) {
      oldvalue[i] = value;
      noteOn(0, i, value);
      MidiUSB.flush();
    }
 
  }
}


void noteOn(byte channel, byte pitch, byte velocity) {


  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};


  MidiUSB.sendMIDI(noteOn);

}


void noteOff(byte channel, byte pitch, byte velocity) {


  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};


  MidiUSB.sendMIDI(noteOff);

}