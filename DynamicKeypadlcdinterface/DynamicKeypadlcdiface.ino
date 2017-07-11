/* @file   DynamicKeypad.pde
|| @version 1.2
|| @author Mark Stanley
|| @contact mstanley@technologist.com
||
||  07/11/12 - Re-modified (from DynamicKeypadJoe2) to use direct-connect kpds
||  02/28/12 - Modified to use I2C i/o G. D. (Joe) Young
||
|| |  Assigning and changing keymaps on the fly
|| |    You will see that the '#' key has been designated to perform two different functions
|| |    depending on how long you hold it down.  If you press the '#' key for less than the
|| |    setHoldTime() then it will print a new line.  However, if you hold if for longer
|| |    than that it will switch back and forth between numbers and letters.  You can see the
|| |    keymap changes in the HOLD event.
|| |
|| |
|| |  In addition...
|| |      You might notice a 
*/
#include <Keypad.h>
#include <ctype.h>
#include <LiquidCrystal.h>
  
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
// Define the keymaps.  The blank spot (lower left) is the space character.
char alphaKeys[ROWS][COLS] = {
  {'R','7','4','1'},
  {'0','8','5','2'},
  {'A','9','6','3'},
  {'E','D','U','L'}
};

char numberKeys[ROWS][COLS] = {
  {'AR','A7','A4','A1'},
  {'A0','A8','A5','A2'},
  {'AA','A9','A6','A3'},
  {'AE','AD','AU','AL'}
};

boolean alpha = false;   // Start with the numeric keypad.

byte rowPins[ROWS] = {22, 24, 26, 28}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {30, 32, 34, 36}; //connect to the column pinouts of the keypad

// Create two new keypads, one is a number pad and the other is a letter pad.
Keypad numpad( makeKeymap(numberKeys), rowPins, colPins, sizeof(rowPins), sizeof(colPins) );
Keypad ltrpad( makeKeymap(alphaKeys), rowPins, colPins, sizeof(rowPins), sizeof(colPins) );
LiquidCrystal lcd(8,9,10,11,12,13);

int input(int ,char);


void setup() {
    Serial.begin(9600);                 // Turns the LED on.
    ltrpad.begin( makeKeymap(alphaKeys) );
    numpad.begin( makeKeymap(numberKeys) );
    lcd.begin(16, 2); 
  lcd.print("BHAVANI DIGITALS");
  delay(1000);
  lcd.clear();
  lcd.print("CHOOSE YOUR MODE");
  lcd.setCursor(0,1);
  lcd.print("MODE:");   
}

char key;

void loop() {
  int counter=0;
  
  
    key = ltrpad.getKey( );
    if (key)
     {
     switch(key)
      {
        case 'D':
        {
        lcd.print("D");
        delay(1000);
        lcd.clear();
        lcd.print("MFD MODE SELECTED");
        delay(1000);
        lcd.clear();
        lcd.print("MFD:");
        lcd.setCursor(0,1);
        lcd.print("EXPD:");
        key = numpad.getKey();
        while(!key)
        delay(50);
       
        
         switch(key)
          {
            case 'A6':
            lcd.print("6");
            break;
            
            case 'A7':
            lcd.print("7");
            break;
            
            case 'A8':
            lcd.print("8");
            break;
            
            default:
            Serial.println(key);
          }
         
        counter = 6;
        //input(counter); 
        break;
        } 
        case 'U':
        {
        lcd.print("U");
        delay(1000);
        lcd.clear();    
        lcd.print("USE BY MODE SELECTED");
        delay(1000);
        lcd.clear();
        lcd.print("USE BY MODE SELECTED");
        lcd.setCursor(0,1);
        lcd.print("USEBY:");
        counter=7;
        break;
        }  
     default: 
       {
       lcd.clear();
       lcd.print("ENTER A VALID KEY");
       delay(1000);
       lcd.clear();
       lcd.print("CHOOSE YOUR MODE");
       lcd.setCursor(0,1);
       lcd.print("MODE:");
       break;
       }
    }
    }
    else
        key = numpad.getKey( );

    }



