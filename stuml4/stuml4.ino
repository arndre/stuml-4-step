
int min = 34;   //midi note
int max = 84;   //midi note

void setup() {
   Serial.begin(31250);
}

void loop() {
  PlayA0();
  PlayA1();
  PlayA2();
  PlayA3();
} 



void PlayA0() {
  int a0 = analogRead(A0);
  a0 = map(a0, 0, 1023, min, max);
  playNote(a0,0x45);
}

void PlayA1() { 
  int a1 = analogRead(A1);
  a1 = map(a1, 0, 1023, min, max);
  playNote(a1,0x45);
}

void PlayA2() {
  int a2 = analogRead(A2);
  a2 = map(a2, 0, 1023, min, max);
  playNote(a2,0x45);
}

void PlayA3() {
   int a3 = analogRead(A3);
  a3 = map(a3, 0, 1023, min, max);
  playNote(a3,0x45);
}

void playNote(int pitch, int velocity) {

  int duration = analogRead(A4);
  duration = map(duration, 0, 1023, 500, 10);

  if(pitch > 34) {
      sendCmd(0x9F, pitch, 0x45);
      delay(duration);
      sendCmd(0x9F, pitch, 0x00);
  } 
  else {
    delay(duration);
  }
  
}

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void sendCmd(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

