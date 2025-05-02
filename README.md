How the Bot Works

RGB Sensor: The bot sequentially shines each of the three RGB LEDs onto a colored surface. The photocell detects the reflected light intensity for each color. When the color is similar to the light produced from the RGB LED the colored surface will absorb most of the light and return a smaller reading. The bot uses this theory to determine the color of the card and acts accordingly.

Color Response:

Red card → Reverse

Green card → Forward

Blue card → Turn Right

Yellow card → Turn left

Purple card → Stop

#When the bot does not detect a color, it stops. This is mainly just a precaution to make the mechanism safer. This can be changed b adjusting the max value in the code as readings will be different depending on lighting enviornment.

Ultrasonic Sensor: The HC-SR04 module checks for obstacles in the bot's path. If an object is too close, the bot stops to prevent collisions.

Non-Continuous Servos: The bot utilizes non-continuous servos to move efficiently and can be mounted onto a chassis.

Getting Started

Build the circuit (refer to Wiring diagram in /docs folder).

Upload the Arduino code from /src/RGB_Sensor_Code.ino.

Place colored cards in the robot's path.

Power on the bot using a battery box or plugged in power

A demo video is available in the /docs folder for viewing 

Note: This bot is for educational and viewing purposes only; however, if you would like to make iterations or fork designs from the bot, feel free to.
