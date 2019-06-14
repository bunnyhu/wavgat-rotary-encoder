/*
 * WAVGAT rotary encoder joystick button
 */
#include <Joystick.h>     // https://github.com/MHeironimus/ArduinoJoystickLibrary

#define KEY 2 // KEY pin
#define S2 3  // S2 pin
#define S1 4  // S1 pin

#define CCW 0b010010  // knob turn CCW pattern
#define CW 0b100001   // knob turn CW pattern
#define DEF 0b11  // default / base value of encoder signal
#define ENC_BTN_JOY 0
#define ENC_CCW_JOY 1
#define ENC_CW_JOY 2

byte prevPattern = 0; // previous signal pattern
byte pattern = 0;     // actual signal pattern
bool keyPushed = false;     // button push status

Joystick_ Joystick(0x03, JOYSTICK_TYPE_JOYSTICK, 3, 0, false, false, false, false, false, false, false, false, false, false, false);

void setup() {
  pinMode(KEY, INPUT);
  pinMode(S2, INPUT);
  pinMode(S1, INPUT);  
  Serial.begin(9600);
  Joystick.begin();
}

void loop() {
  readEncoder();   
}

/*
 * press, wait and release the button
 */
void pushJoyButton( int buttonId ) {
  Joystick.pressButton( buttonId );
  delay(100);
  Joystick.releaseButton( buttonId );  
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
    if ( keyPushed ) {
      Joystick.pressButton( ENC_BTN_JOY );
    } else {
      Joystick.releaseButton( ENC_BTN_JOY );
    }
  }

  byte aktPattern = (aktS1 << 1) | aktS2;
  if (aktPattern != prevPattern) {
    prevPattern = aktPattern;
    if ( aktPattern != DEF ) {
      pattern = (pattern << 2) | aktPattern;
    } else {
      if (pattern == CW ) {
        Serial.println( "Turn right" );
        pushJoyButton(ENC_CW_JOY);
      } else if (pattern == CCW ) {
        Serial.println( "Turn left" );        
        pushJoyButton(ENC_CCW_JOY);
      }
      pattern = 0;       
    }
  }
}
