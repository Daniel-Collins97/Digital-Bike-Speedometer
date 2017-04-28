# **_Project Proposal for semester 2_**
## **Title:** Bike Speedometer

**Description:** For my Digital Bike Speedometer, i have a Hall Effect Sensor connected to an LCD screen. The Hall Effect sensor should be connected to a static position on a bike near the wheel. Then, a Magnet should be attached to the wheel. When the magnet passes the Sensor, a value of High is received by the Arduino. The Code then uses the wheels diameter and the amount of revolutions to determine the speed and distance travelled of the bike. Then, it will print these values to the LCD screen.

![Image of project](InkedIMG_20170428_095430_LI.jpg)

**Equipment needed:**
* Arduino
* Hall Effect Sensor
* Magnet
* LCD screen (16x2)
* Power Source (7V-12V battery)
* Battery Connector
* 2 way switch
* Breadboard
* Wires
* Function for calculating Speed and Distance (code)

**Other Practical Skills needed:** Programming, Soldering, Web Development, Wiring, Digital Electronics, Math.

This is the code that updates the Speed and Distance variables for my project;

```C
void updateSpeedAndDistance()
{
  distance = tire_circumference * revolutions;
  distance /= miles_in_inches;
  float ipm = tire_circumference / (float)last_interval;
  mph = ipm * k_ipm_2_mph;
}
```
This is the code that prints the values to the LCD Screen;
```C
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
 lcd.print(mph);                                       // Prints value for Mph on screen
 lcd.setCursor(0, 1);                                        // Sets Cursor to first row second column
 lcd.print("Miles:");                                        // Prints "Miles" on screen
 lcd.print(distance);                                        // Prints value for distance on screen
}
```

Daniel Collins 20076240
