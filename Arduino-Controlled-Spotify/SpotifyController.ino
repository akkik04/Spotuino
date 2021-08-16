// including the LCD's library to use its functions.
#include <LiquidCrystal.h>

/*
 * ARDUINO/C++ SCRIPT FOR THE ARDUINO CONTROLLED SPOTIFY PROJECT.
 * AKSHITH KANDIVANAM
 */

 
// declaring the LCD pins.
LiquidCrystal lcd(13, 8, 9, 10, 11, 12);

// creating a variable to store the song name that is sent from the python script through the COM3 port.
String readSong = " ";

// declaring variables to tie the left (previous song), centre (pause song), and right (next song) buttons to their respective pins.
const int leftB = 2;
const int centreB = 7;
const int rightB = 4;

// declaring variables to store the current state of each button, the state is either HIGH OR LOW.
int currentLeftState = 0;
int currentCentreState = 0;
int currentRightState = 0;

// declaring a variable to store the previous state of the centre button, once again, the state is either HIGH OR LOW.
int prevCentreState = 0;


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

  // changing the serial's timing to wait for stream data to 0.
  Serial.setTimeout(0);
}

// MAIN-LOOP.
void loop() {

  // updating the created variable to read the song from the python script with the info from the serial port.
  readSong = Serial.readString();

  // code to print the song name to the user through the 1602 LCD.
  lcd.setCursor(0, 1);
  lcd.print(readSong);
  delay(1100);
  

  // code to read the state of each button, which tells the program if the button is pressed.
  currentLeftState = digitalRead(leftB);
  currentCentreState = digitalRead(centreB);
  currentRightState = digitalRead(rightB);


  // creating an if-statement to check if the centre button is pressed. 
  // checking that the current state is not equal to the previous state of each button, while making sure that the button's current state is LOW.
  if((currentCentreState != prevCentreState)&&(currentCentreState == LOW)){

    // communicating the keyword 'stop' through the serial monitor, which will be read through the associated python script through COM3 and activate the specific PyAutoGui's functions to act on the Spotify.
    Serial.println("stop");

    // code to print 'Paused' if the song is paused through the 1602 LCD.
    lcd.setCursor(0,0);
    lcd.print("Paused");
    delay(250);
    
  }
  
  else if(currentRightState == HIGH){

    // communicating the keyword 'next' through the serial monitor, which will be read through the associated python script through COM3 and activate the specific PyAutoGui's functions to act on the Spotify.
    Serial.println("next");

    // code to print 'Playing Next:' if the song is forwarded through the 1602 LCD.
    lcd.setCursor(0, 0);
    lcd.print("Playing Next:");
    delay(250);

  }
  
  else if(currentLeftState == HIGH){

    // communicating the keyword 'back' through the serial monitor, which will be read through the associated python script through COM3 and activate the specific PyAutoGui's functions to act on the Spotify. 
    Serial.println("back");

    // code to print the 'Playing Previous:' if the song is backwarded through the 1602 LCD.
    lcd.setCursor(0, 0);
    lcd.print("Playing Previous:");
    delay(250);

  }

  // code to tie the previous state of the centre button to its current state after each iteration of the main-loop.
  prevCentreState = currentCentreState;

  lcd.clear();
  
}
