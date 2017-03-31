#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 7, 6, 5, 4);

int backLight = 13;                                 // pin 13 will control the backlight
int led = 9;
float tire_diameter = 26.2;                         // Wheel dimaeter in inches
int tire_circumference;                             //
float distance = 0.0;                               //
int revolutions = 0;                                // 
float miles_in_inches = 63360;                      //
unsigned long last_interval = 0;                    //
float k_ipm_2_mph;                                  //
float mph = 0.0;                                    //
unsigned long last_fall = 0;                        //
int hall_state = 1;                                 //




void updateSpeedAndDistance()                                       //
{
  distance = tire_circumference * revolutions;
  distance /= miles_in_inches;
  float ipm = tire_circumference / (float)last_interval;
  mph = ipm * k_ipm_2_mph;
}


void setup()
{
  pinMode(led, OUTPUT);
 
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);                    // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);                                  // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                                      // start with a blank screen
  lcd.setCursor(0,0);                               // set cursor to column 0, row 0 (the first row)
  lcd.print("Lets get Started");                    // Sets Start Message on First Line
  lcd.setCursor(7,1);                               // set cursor to column 7, row 1
  lcd.print("Go!");                                 // Sets Start Message on Second Line
  delay(2000);
  lcd.clear(); 
  k_ipm_2_mph = 3600000 / miles_in_inches;
  tire_circumference = tire_diameter*3.14159;
}

 void loop()                                                  // Continuously loops over following code to update the variables "mph" and "distance" 
 {
   int hall_val = digitalRead(2);
   if (hall_state != hall_val && hall_val == LOW) 
   {
    revolutions++;
    last_interval = millis()-last_fall;
    last_fall = millis();
  }
  hall_state = hall_val;
  updateSpeedAndDistance();                                   // Calls "updateSpeedAndDistance" function here

  lcd.setCursor(0, 0);                                        // Sets Cursor to first row first column
  lcd.print("Mph:");                                          // Prints "Mph" on screen
  lcd.print(mph);                                             // Prints value for Mph on screen
  lcd.setCursor(0, 1);                                        // Sets Cursor to first row second column
  lcd.print("Miles:");                                        // Prints "Miles" on screen
  lcd.print(distance);                                        // Prints value for distance on screen
 }

