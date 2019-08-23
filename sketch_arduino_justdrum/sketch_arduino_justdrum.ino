#define PIEZOTHRESHOLD 50 // analog threshold for piezo sensing
#define  midichannel 1;

int val;
int ledPin = 13;  
byte status1;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(57600);   // set serial output rate

}

void loop() {
    int val = analogRead(A0);
      if (val >= PIEZOTHRESHOLD) {
        digitalWrite(ledPin, HIGH);
        MIDI_TX(144,50,100);
        delay(10);
        MIDI_TX(144,50,0);
        digitalWrite(ledPin, LOW);
      }       
}

void MIDI_TX(byte MESSAGE, byte PITCH, byte VELOCITY) 
{
  status1 = MESSAGE + midichannel;
  Serial.write(status1);
  Serial.write(PITCH);
  Serial.write(VELOCITY);

}
