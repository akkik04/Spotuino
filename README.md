# Arduino-Controlled-Spotify

This project controls the Spotify app using just 3 buttons that are wired to the Arduino Uno Rev3. The Arduino communicates a few keywords (i.e. pause, forward, and back) to the Python script through the COM3 port and uses PyAutoGui's functions to pause/play track, play the previous track, and play the next track. It also has a 1602 LCD hooked up to the Arduino board to let the user know about the pause, forward, and back commands.
