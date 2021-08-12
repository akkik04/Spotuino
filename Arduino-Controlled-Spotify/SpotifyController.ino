/*
 * ARDUINO/C++ SCRIPT FOR THE ARDUINO CONTROLLED SPOTIFY PROJECT.
 * AKSHITH KANDIVANAM
 */

// including the LCD's library to use its functions.
#include <LiquidCrystal.h>
 
// declaring the LCD pins.
LiquidCrystal lcd(13, 8, 9, 10, 11, 12);
  
// declaring variables to tie the left (previous song), centre (pause song), and right (next song) buttons to their respective pins.
const int leftB = 2;
const int centreB = 7;
const int rightB = 4;

// declaring variables to store the current state of each button, the state is either HIGH OR LOW.
int currentLeftState = 0;
int currentCentreState = 0;
int currentRightState = 0;

// declaring variables to store the previous state of each button, once again, the state is either HIGH OR LOW. 
int prevLeftState = 0;
int prevCentreState = 0;
int prevRightState = 0;

// SETUP.
void setup() {

  // declaring each button as INPUT as it is supposed to tell the spotify app what to do (ex, STOP, NEXT, PREVIOUS).
  pinMode(centreB, INPUT);
  pinMode(leftB, INPUT);
  pinMode(rightB, INPUT);

  // initializing the LCD.
  lcd.begin(16, 2);

  // initializing the serial monitor.
  Serial.begin(9600);
}

// MAIN-LOOP.
void loop() {

  // code to clear the LCD after each iteration of the loop.
  lcd.clear();
  

  // code to read the state of each button, which tells the program if the button is pressed.
  currentLeftState = digitalRead(leftB);
  currentCentreState = digitalRead(centreB);
  currentRightState = digitalRead(rightB);

  // creating an if-statement to check if the centre button is pressed. 
  // checking that the current state is not equal to the previous state of each button, while making sure that the button's current state is LOW.
  if((currentCentreState != prevCentreState)&&(currentCentreState == LOW)){

    // communicating the keyword 'stop' through the serial monitor, which will be read through the associated python script through COM3 and activate the specific PyAutoGui's functions to act on the Spotify.
    Serial.println("stop");

    // code to print that the song stopped to the user.
    lcd.print("Stopped Song");
    delay(250);
    lcd.clear();
    
  }
  
  else if((currentRightState != prevRightState)&&(currentRightState == LOW)){

    // communicating the keyword 'next' through the serial monitor, which will be read through the associated python script through COM3 and activate the specific PyAutoGui's functions to act on the Spotify.
    Serial.println("next");

    // code to print that the next song is playing to the user.
    lcd.print("Next Song");
    delay(250);
    lcd.clear();
  }
  else if((currentLeftState != prevLeftState)&&(currentLeftState == LOW)){

    // communicating the keyword 'back' through the serial monitor, which will be read through the associated python script through COM3 and activate the specific PyAutoGui's functions to act on the Spotify. 
    Serial.println("back");

    // code to print that the previous song is playing to the user.
    lcd.print("Previous Song");
    delay(250);
    lcd.clear();
        
  }

  // code to tie the previous state of each button to its current state after each iteration of the main-loop.
  prevLeftState = currentLeftState;
  prevCentreState = currentCentreState;
  prevRightState = currentRightState;

}
