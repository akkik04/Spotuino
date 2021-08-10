# PYTHON SCRIPT FOR THE ARDUINO CONTROLLED SPOTIFY PROJECT.
# AKSHITH KANDIVANAM.

# importing the required modules.
# 1. PyAutoGUI module is mandatory as we will use its functions for the automation process.
# 2. Time module is mandatory because we can use its functions to create effects and suspend execution of a thread for 'x' seconds.
# 3. Serial module is the whole base for this project. Since we need to communicate through the serial port, this module grants access for that purpose.
import pyautogui, time, serial

# creating a variable to open the port at 'COM3' for the communication process at 9600 baud.
# the functions for 'serial.Serial' is: __init__(port, baudrate)
arduino_uno = serial.Serial('com3', 9600)

# code to use the time.sleep() function to suspend the execution for 1.75 seconds.
time.sleep(1.75)

# creating a while-loop.
while True:

    # creating a string variable called 'signal' to receive the communication from the ArduinoUno at COM3. 
    signal = str(arduino_uno.readline()).split()

    '''

    The program will print the signals after the press of each button that is wired to the ArduinoUno.
    1. a keyword 'stop' can be printed, indicating to pause the music.
    2. a keyword 'back' can be printed, indicating to play the previous song after going back to the original.
    3. a keyword 'next' can be printed, indicating to play the next song that is after the current one playing.

    '''
    # printing the signal to the user via terminal.
    print(signal)

    # creating a for-loop to iterate for the given signal by the buttons connected through the ArduinoUno.
    for i in signal:

        # creating a nested if-statement to check for the keywords being in the signal.
        if 'stop' in i:

            # code to stop the music if the keyword 'stop' is detected through the outputted signal.
            # using the PyAutoGui module's keyboard function called 'typewrite' to activate the space bar to stop the music in a time interval of 0.2 seconds.
            pyautogui.typewrite(['space'], 0.2)

        elif 'back' in i:

            # code to play the previous song if the keyword 'back' is detected through the outputted signal.
            # using the PyAutoGui module's keyboard function called 'hotkey' to activate the 'ctrl + left' input to play the previous song.
            pyautogui.hotkey('ctrl', 'left')

        elif 'next' in i:  

            # code to play the next song if the keyword 'next' is detected through the outputted signal.
            # using the same PyAutoGui 'hotkey' function as before to activate the 'ctrl + right' input to play the upcoming/next song.
            pyautogui.hotkey('ctrl', 'right')    
