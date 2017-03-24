#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 7, 6, 5, 4);

int backLight = 13;                                 // pin 13 will control the backlight
int buttonState = 0;
int led = 9;

void setup()
{
  pinMode(led, OUTPUT);
  buttonState = digitalRead(9);
  
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);                    // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);                                  // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                                      // start with a blank screen
  lcd.setCursor(0,0);                               // set cursor to column 0, row 0 (the first row)
  lcd.print("Lets get Started");                    // change text to whatever you like. keep it clean!
  lcd.setCursor(7,1);                               // set cursor to column 7, row 1
  lcd.print("Go!");
}
 void loop()
 {
 }

