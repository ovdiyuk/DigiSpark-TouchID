#include "DigiKeyboard.h"

byte buttonPresses = 0;                // how many times the button has been pressed 
byte lastPressCount = 0;               // to keep track of last press count

void setup() {
  pinMode(0, INPUT);

  // Makes OS identify this device as keyboard
  DigiKeyboard.sendKeyStroke(0);
}

void loop()
{
  if (digitalRead(0) == HIGH)  // check if button was pressed
  {
    buttonPresses++;                  // increment buttonPresses count
    delay(230);                       // debounce switch
  }
  
    if (lastPressCount == buttonPresses)              // only do output if the count has changed
    {
        switch (buttonPresses) {
          case 1:
            insertPassword();
            buttonPresses = 0;
            break;
          case 2:
            DigiKeyboard.sendKeyStroke(KEY_ENTER);
            DigiKeyboard.delay(500);
            insertPassword();
            buttonPresses = 0;
            break;
          case 3:
            // statements
            DigiKeyboard.sendKeyStroke(0);
            buttonPresses = 0;
            break;
          default: 
            buttonPresses= 0;
          break;
        }
    }
    lastPressCount = buttonPresses; 
}

// Digispark as physical password token
void insertPassword()
{
  //DigiKeyboard.println("\n");
  //delay(500);
  DigiKeyboard.println("your password");
}
