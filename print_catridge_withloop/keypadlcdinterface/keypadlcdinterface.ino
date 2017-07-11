/* @file CustomKeypad.pde
|| @version 1.0
|| @author Siva ganesh.V
|| @contact sivaganeshvbe@gmail.com
||
|| @description
|| | Demonstrates changing the keypad key values.
|| 
*/
#include <Keypad.h>
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8,9,10,11,12,13);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'R','7','4','1'},
  {'0','8','5','2'},
  {'A','9','6','3'},
  {'E','D','U','L'}
};

byte rowPins[ROWS] = {22, 24, 26, 28}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {30, 32, 34, 36}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
int counter=0;
char printout[17]={'U','S','E','B','Y',':'};
void setup()
{
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.print("BHAVANI DIGITALS");
  delay(5000);
  lcd.clear();
  lcd.print("ENTER THE DATE");
  lcd.setCursor(0,1);
  lcd.print("USEBY:");
  lcd.blink();
  counter=6;
}       
        

void loop()
{
  while(counter<29)
  {
    char key = customKeypad.getKey();
    if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case 'R':
      {
        lcd.clear();
        lcd.print("ENTER THE DATE");
        lcd.setCursor(0,1);
        lcd.print("USEBY:");
        lcd.blink();
        counter=6;
      }
      case 'L':
      {
        if (counter>6)
        {
        lcd.setCursor((counter-1),1);
        lcd.print(" ");
        lcd.setCursor((counter-1),1);
        counter=counter-1;
        }
        break;
      }
      case '7':
        {
        lcd.print("7");
        printout[counter]='7';
        counter=counter+1;
        break;
        }
      case '4':
        {
        lcd.print("4");
        printout[counter]='4';
        counter=counter+1;
        break;
        }
      case '1':
        {
        lcd.print("1");
        printout[counter]='1';
        counter=counter+1;
        break;
        }
      case '0':
        {
        lcd.print("0");
        printout[counter]='0';
        counter=counter+1;
        break;
        }
      case '8':
        {
        lcd.print("8");
        printout[counter]='8';
        counter=counter+1;
        break;
        }
      case '5':
        {
        lcd.print("5");
        printout[counter]='5';
        counter=counter+1;
        break;
        }
      case '2':
        {
        lcd.print("2");
        printout[counter]='2';
        counter=counter+1;
        break;
        }
      case 'A':
        {
        lcd.print("/");
        printout[counter]='/';
        counter=counter+1;
        break;
        }
      case '9':
       {
        lcd.print("9");
        printout[counter]='9';
        counter=counter+1;
        break;
        }
      case '6':
        {
        lcd.print("6");
        printout[counter]='7';
        counter=counter+1;
        break;
        }
      case '3':
        {
        lcd.print("3");
        printout[counter]='3';
        counter=counter+1;
        break;
        }
     // case 'D':  
         // {
         // lcd.clear();
         // for(int i=0;i<counter;i++)
          //lcd.print(printout[i]);
         // break;
         // }
    
      default:
        Serial.println(key);
    }//switch
   }//if
  }//while
 }


