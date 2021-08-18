# Arduino-Controlled-Spotify

This project is simply made to demonstrate the functionality of the Arduino Uno with the Python language. The project controls the Spotify app using just 3 buttons that are wired to the Arduino Uno Rev3. The Arduino communicates a few keywords (i.e. pause, forward, and back) to the Python script through the COM3 port and uses PyAutoGui's functions to pause/play track, play the previous track, and play the next track. It also has a 1602 LCD hooked up to the Arduino board to let the user know about the pause, forward, and back commands.

# Main Hardware Requirements:
Along with the main components listed below, a solderless breadboard, jumper wires, and male/female jumper wires are required.
![Arduino-Spotify-Project Hardware Requirements](https://user-images.githubusercontent.com/81925146/129283181-aa8ddbe9-8979-4b79-9e00-d070d46cac18.png)

# Important Documentations:

- **PyAutoGUI's Documentation:** I used this documentation to become familiar with the functions that the PyAutoGUI module has to offer. The PyAutoGUI module plays a crucial role in my Python script because after the signal is sent from the Arduino to the Python script, we use the functions from the PyAutoGUI module to automate interactions with the Spotify app based on the type of signal. To view the PyAutoGUI module's documentation click [PyAutoGUI documentation](https://pyautogui.readthedocs.io/en/latest/#).

- **pySerial's Documentation:** I used this documentation to find out how I can receive access to the serial port. The pySerial module plays a very important role in my Python script because it does the central function of receiving the signal from the buttons wired to the Arduino Uno. For this project, the communication is done through the COM3 port. To view the pySerial module's documentation click [pySerial documentation](https://pyserial.readthedocs.io/en/latest/index.html).

- **SwSpotify's Documentation:** I used this documentation to learn more about the functions that the SwSpotify module has to offer. This module is an add-on to my project because it gets the song and artist of the currently playing music from the Spotify application without using the actual API. After getting the current tune from the module's functions, the data is communicated to the Arduino Uno through the COM3 port and outputted through the 1602 LCD. To view the SwSpotify module's documentation click [SwSpotify documentation](https://pypi.org/project/SwSpotify/).

# Circuit Model/Description:

Below is a circuit diagram that shows all the connections for the project. It might be hard to see what the connections are, which is why I will write the main connections below. If you are familiar with the Arduino platform, you can head over to my [Arduino script](https://github.com/akkik04/Arduino-Controlled-Spotify/blob/main/Arduino-Controlled-Spotify/SpotifyController.ino) and view a few important connections listed through code.

### LCD Connections:
- VSS pin to GND or '-' row of breadboard.
- VDD pin to 5V or '+' row of breadboard.
- V0 pin to GND or '-' row of breadboard.
- RS pin to Digital Pin #13.
- RW pin to GND or '-' row of breadboard.
- E pin to Digital Pin #8.
- D4 pin to Digital Pin #9.
- D5 pin to Digital Pin #10.
- D6 pin to Digital Pin #11.
- D7 pin to Digital Pin #12.
- A pin to 5V or '+' row of breadboard.
- K pin to GND or '-' row of breadboard.

### General Connections:

- The general connections are simple connections to the '+' and '-' rows of the breadboard, button connections with resistors attached, and the main Arduino connection to your laptop. If you want to become familiarized with the general connections of an Arduino Uno R3 board, I recommend viewing this [Arduino tutorial](https://www.arduino.cc/en/Tutorial/HomePage).
![Arduino-Spotify-Project Circuit (5)](https://user-images.githubusercontent.com/81925146/129281072-5a3cbdbd-0472-4abd-b743-5753c15f4fde.png)

# Project Visuals:

Below is a picture of the circuit. The picture shows the display of the buttons and the entire hardware. To view the latest video of the project in action. Click [Watch Visual](https://github.com/akkik04/Arduino-Controlled-Spotify/blob/main/Project-Visuals/Updated-Visuals/ArduinoSpotifyVidUpdated.MOV).
![Arduino-Spotify-Project Hardware Requirements (2)](https://user-images.githubusercontent.com/81925146/129284092-69f1b06a-196a-4407-88b2-3cb3424de110.png)
