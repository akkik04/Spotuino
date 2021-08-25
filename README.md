# Spotuino (Controlling Spotify with Arduino)

- This project is simply made to demonstrate the functionality of the Arduino Uno with the Python language. The project controls the Spotify app using an IR remote and receiver. The Arduino communicates keywords (e.g. pause, forward, and back) based on the IR receiver back to the Python script through the COM3 port, which activates the PyAutoGui's functions. A 1602 LCD is used to display the song's status to the user.

- The name of this project is 'Spotuino'. It is a combination of Spotify & Arduino.

# Main Hardware Requirements:
Along with the main components listed below, a solderless breadboard, jumper wires, and male/female jumper wires are required.
![Arduino Spotify Hardware Requirements](https://user-images.githubusercontent.com/81925146/130687263-7e03b568-043c-48af-99ae-c72797164afc.png)

# Important Documentations:
## Python Documentations:
- **PyAutoGUI's Documentation:** I used this documentation to become familiar with the functions that the PyAutoGUI module has to offer. The PyAutoGUI module plays a crucial role in my Python script because after the signal is sent from the Arduino to the Python script, we use the functions from the PyAutoGUI module to automate interactions with the Spotify app based on the type of signal. To view the PyAutoGUI module's documentation click [PyAutoGUI documentation](https://pyautogui.readthedocs.io/en/latest/#).

- **pySerial's Documentation:** I used this documentation to find out how I can receive access to the serial port. The pySerial module plays a very important role in my Python script because it does the central function of receiving the signal from the buttons wired to the Arduino Uno. For this project, the communication is done through the COM3 port. To view the pySerial module's documentation click [pySerial documentation](https://pyserial.readthedocs.io/en/latest/index.html).

- **SwSpotify's Documentation:** I used this documentation to learn more about the functions that the SwSpotify module has to offer. This module is an add-on to my project because it gets the song and artist of the currently playing music from the Spotify application without using the actual API. After getting the current tune from the module's functions, the data is communicated to the Arduino Uno through the COM3 port and outputted through the 1602 LCD. To view the SwSpotify module's documentation click [SwSpotify documentation](https://pypi.org/project/SwSpotify/).

## Arduino Documentations:
- **Liquid Crystal Display's Documentation:** I used this documentation to learn how to use the functions that the 1602 LCD has to offer. The LCD plays an important role in my project because it performs the task of displaying the song name and the functions that are taking place (e.g. forwarding, pausing, and backwarding). To view the Liquid Crystal Display library's documentation click [Liquid Crystal Display documentation](https://www.arduino.cc/en/Reference/LiquidCrystal).

- **IR Remote Documentation:** I used this documentation to familiarize myself with the uses of the IR receiver and transmitter. The IR functionality plays a very important role in my project because the transmitter (remote) conveys a signal to the receiver, which gets passed on to the Python script to activate the appropriate function on the Spotify app. To view the IR Remote library's documentation click [IR Remote Documentation](https://github.com/Arduino-IRremote/Arduino-IRremote).

# Circuit Model/Description:

Below is a circuit diagram that shows all the connections for the project. It might be hard to see what the connections are, which is why I will write the main connections below. If you are familiar with the Arduino platform, you can head over to my [Arduino script](https://github.com/akkik04/Arduino-Controlled-Spotify/blob/main/Arduino-Controlled-Spotify/SpotifyController.ino) and view a few important connections listed through code.

### LCD Connections:
- `VSS pin to GND or '-' row of breadboard.`
- `VDD pin to 5V or '+' row of breadboard.`
- `V0 pin to GND or '-' row of breadboard.`
- `RS pin to Digital Pin #13.`
- `RW pin to GND or '-' row of breadboard.`
- `E pin to Digital Pin #8.`
- `D4 pin to Digital Pin #9.`
- `D5 pin to Digital Pin #10.`
- `D6 pin to Digital Pin #11.`
- `D7 pin to Digital Pin #12.`
- `A pin to 5V or '+' row of breadboard.`
- `K pin to GND or '-' row of breadboard.`

### IR Receiver Connections:
- `G pin to GND or '-' row of breadboard.`
- `R pin to 5V or '+' row of breadboard.`
- `Y pin to Digital Pin #7.`

### General Connections:

- The general connections are simple connections to the '+' and '-' rows of the breadboard. If you want to become familiarized with the general connections of an Arduino Uno R3 board, I recommend viewing this [Arduino tutorial](https://www.arduino.cc/en/Tutorial/HomePage).
![Arduino Spotify Circuit Picture](https://user-images.githubusercontent.com/81925146/130706677-0af51318-2e6b-4951-8271-53b583be8b2d.png)


# Project Visuals:

Below is a picture of the circuit. The picture shows the display of the IR receiver that is wired to the Arduino and the IR remote in my hand. A lot of the main hardware is also shown through this picture. To view the latest video of the project in action. Click [Watch Visual](https://github.com/akkik04/Spotuino/blob/main/Project-Visuals/Updated-Visuals/Latest%20Arduino%20Spotify%20Video.MOV).

![Arduino Spotify Picture](https://user-images.githubusercontent.com/81925146/130685849-ff74278f-203d-4485-8f56-47ee03715de7.jpeg)
