/*
 * WAVGAT rotary encoder demo
 */

#define KEY 2 // KEY pin
#define S2 3  // S2 pin
#define S1 4  // S1 pin
#define CCW 0b010010  // knob turn CCW pattern
#define CW 0b100001   // knob turn CW pattern
#define DEF 0b11  // default / base value of encoder signal

byte prevPattern = 0; // previous signal pattern
byte pattern = 0;     // actual signal pattern
bool keyPushed = false;     // button push status

void setup() {
  pinMode(KEY, INPUT);
  pinMode(S2, INPUT);
  pinMode(S1, INPUT);  
  Serial.begin(9600);
}

void loop() {
  readEncoder();  
}

/*
 * read encoder and button status
 */
void readEncoder() {
  byte aktS1 = digitalRead(S1);
  byte aktS2 = digitalRead(S2);
  byte aktKey = ! digitalRead(KEY);

  if (keyPushed != aktKey) {
    keyPushed = aktKey;
    Serial.println( keyPushed ? "Key push" : "Key release");
  }

  byte aktPattern = (aktS1 << 1) | aktS2;
  if (aktPattern != prevPattern) {
    prevPattern = aktPattern;
    if ( aktPattern != DEF ) {
      pattern = (pattern << 2) | aktPattern;
    } else {
      if (pattern == CW ) {
        Serial.println( "Turn right" );
      } else if (pattern == CCW ) {
        Serial.println( "Turn left" );        
      }
      pattern = 0;       
    }
  }
}
