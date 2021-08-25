/*
 * ARDUINO/C++ SCRIPT FOR THE ARDUINO CONTROLLED SPOTIFY PROJECT.
 * AKSHITH KANDIVANAM
 */

// including the LCD's library to use its functions.
#include <LiquidCrystal.h>

// including the IR Remote library to use its functions.
#include <IRremote.h>

// declaring the LCD pins.
LiquidCrystal lcd(13, 8, 9, 10, 11, 12);

// declaring the IR receiever pin to 7.
const int recv_pin = 7;

// code to create a receiver object using the 'IRrecv' function.
IRrecv irrecv(recv_pin);

// code to create a results object using the 'decode_results' function.
decode_results results;

// creating a variable to store the key value.
unsigned long key_value = 0;

// creating a variable to store the song name that is sent from the python script through the COM3 port.
String readSong = " ";

// SETUP.
void setup() {

  // code to enable the receiver that we created.
  irrecv.enableIRIn();

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

  // creating an if-statement to decode the signal sent from the transmitter, which is the remote. We store the signal in the 'results' variable.
  if (irrecv.decode(&results)){

    // creating an if-statement to check if the value is equal to a hex value.
    if (results.value == 0XFFFFFFFF)

      // tying the result's value to the key value if the condition is met.
      results.value = key_value;

    // creating a switch to compare the value to multiple cases.
    switch (results.value){

      // CASE: 1. If the value is equal to '0xFFE21D', it represents the pause button.
      case 0xFFE21D:

      // printing the keyword 'stop' to the serial monitor for recognition by the python script.
      Serial.println("stop");
      
      // code to print 'Paused' if the song is paused through the 1602 LCD.
      lcd.setCursor(0,0);
      lcd.print("Paused");
      delay(250);
      break;

      // CASE: 2. If the value is equal to '0xFF22DD', it represents the previous button.
      case 0xFF22DD:

      // printing the keyword 'back' to the serial monitor for recognition by the python script.
      Serial.println("back");
      
      // code to print the 'Playing Previous:' if the song is backwarded through the 1602 LCD.
      lcd.setCursor(0, 0);
      lcd.print("Playing Previous:");
      delay(250);
      break;

      // CASE: 3. If the value is equal to '0xFFC23D', it represents the forward button.
      case 0xFFC23D:

      // printing the keyword 'next' to the serial monitor for recognition by the python script.
      Serial.println("next");
      
      // code to print 'Playing Next:' if the song is forwarded through the 1602 LCD.
      lcd.setCursor(0, 0);
      lcd.print("Playing Next:");
      delay(250);
      break ;

      // CASE: 4. If the value is equal to '0xFF629D', it represents the volume up button.
      case 0xFF629D:

      // printing the keyword 'up' to the serial monitor for recognition by the python script.
      Serial.println("up");

      // code to print 'Volume up' if the volume is brought up through the 1602 LCD.
      lcd.setCursor(0, 0);
      lcd.print("Volume up");
      delay(50);
      break;

      // CASE: 5. If the value is equal to '0xFFA857', it represents the volume down button.
      case 0xFFA857:

      // printing the keyword 'down' to the serial monitor for recognition by the python script.
      Serial.println("down");

      // code to print 'Volume down' if the volume is brought up through the 1602 LCD.
      lcd.setCursor(0, 0);
      lcd.print("Volume down");
      delay(50);
      break;
    }

    // code to store the value as the key value after the switch.
    key_value = results.value;

    // code to allow the receiver resume for the next data sent through the transmitter.
    irrecv.resume();
  }
  
  // creating a for-loop to add the scrolling effect.
  for (int counter = 0; counter < 16; counter++) {
    
    // scrolling one position to the right.
    lcd.scrollDisplayRight();

    // adding a delay to create an effect.
    delay(150);
  }

  // clearing the lcd after each iteration of the main-loop.
  lcd.clear();
  
}
