# PYTHON SCRIPT FOR THE ARDUINO CONTROLLED SPOTIFY PROJECT.
# AKSHITH KANDIVANAM.

# importing the required modules.
# 1. PyAutoGUI module is mandatory as we will use its functions for the automation process.
# 2. Time module is mandatory because we can use its functions to create effects and suspend execution of a thread for 'x' seconds.
# 3. Serial module is the whole base for this project. Since we need to communicate through the serial port, this module grants access for that purpose.
# 4. SwSpotify module is necessary for the add-on of song-detection. The song is detected through this module's functions and is sent to the Arduino for display through a 1602 LCD.
import pyautogui, time, serial
from SwSpotify import spotify

# creating a variable to open the port at 'COM3' for the communication process at 9600 baud.
# the functions for 'serial.Serial' is: __init__(port, baudrate)
arduino_uno = serial.Serial('com3', 9600)

# creating a variable to store the old song that was playing. This variable is crucial for song detection.
old_song = " "

# created a function to store all the code for analyzing the button signal sent to the python script through the COM3 port.
def analyze_signal():

    # creating a string variable called 'signal' to receive the communication from the ArduinoUno at COM3. 
    signal = str(arduino_uno.readline())

    '''
    The program will print the signals after the press of each button that is wired to the ArduinoUno.
    1. a keyword 'stop' can be printed, indicating to pause the music.
    2. a keyword 'back' can be printed, indicating to play the previous song after going back to the original.
    3. a keyword 'next' can be printed, indicating to play the next song that is after the current one playing.
    '''
    # printing the signal to the user via terminal.
    print(signal)

    # creating an if-statement to check for the keywords being in the signal sent from the Arduino.
    if 'stop' in signal:

        # code to stop the music if the keyword 'stop' is detected through the outputted signal.
        # using the PyAutoGui module's keyboard function called 'typewrite' to activate the space bar to stop the music in a time interval of 0.2 seconds.
        pyautogui.typewrite(['space'], 0.2)

        # time delay.
        time.sleep(0.2)

    elif 'back' in signal:

        # code to play the previous song if the keyword 'back' is detected through the outputted signal.
        # using the PyAutoGui module's keyboard function called 'hotkey' to activate the 'ctrl + left' input to play the previous song.
        pyautogui.hotkey('ctrl', 'left')

        # time delay.
        time.sleep(0.2)

    elif 'next' in signal:  

        # code to play the next song if the keyword 'next' is detected through the outputted signal.
        # using the same PyAutoGui 'hotkey' function as before to activate the 'ctrl + right' input to play the upcoming/next song.
        pyautogui.hotkey('ctrl', 'right')

        # time delay.
        time.sleep(0.2)

# created a function to store all the code for sending the song name back to the Arduino Uno for display through the LCD. 
def get_song(old_song):

    # creating a variable to continuously update the current song that is playing. This variable is crucial for song detection.
    current_song = spotify.song()

    # creating a nested if-statement to send the arduino the song name if the previous song and the current song are different.
    if current_song != old_song:

        # using the pySerial's 'write()' function to write the song name with encoding to the arduino through the COM3 port.
        arduino_uno.write(spotify.song().encode())

    # code to tie/update the old song to the current song.
    song_old = current_song

# creating a while-loop.
while True:

    # calling the function to analyze the button signal from the Arduino.
    analyze_signal()

    # calling the function to get the song name from the SwSpotify module and send it to the Arudino for display.
    get_song(old_song)
