# GPS_Based_Smart_Cap_for_Blind_People

Description:
This project is a GPS-based smart cap designed for blind individuals, assisting them in navigating their environment and providing emergency assistance when needed. The smart cap incorporates ultrasonic sensors to detect obstacles and uses vibrating motors to alert the wearer. In addition, a GPS and GSM module is included to send the wearer's current location to a designated contact when a push button is pressed.

Components Used:
-Arduino Uno: Main microcontroller for obstacle detection and alert system.
-Arduino Nano: Secondary microcontroller for GPS and GSM module handling.
-Ultrasonic Sensors: Detect obstacles in front of the wearer.
-Vibrating Motors: Provide haptic feedback for obstacle detection.
-GPS Module: Gets the current location.
-GSM Module: Sends SMS with location data.
-Push Button: Triggers the emergency alert system.

Circuit Connections:

Obstacle_Detection_with_Ultrasonic_Sensors:
-Ultrasonic Sensor 1: Trig (Pin 2), Echo (Pin 3)
-Ultrasonic Sensor 2: Trig (Pin 6), Echo (Pin 7)
-Ultrasonic Sensor 3: Trig (Pin 10), Echo (Pin 11)
-Motor 1: Pin 1
-Motor 2: Pin 8
-Motor 3: Pin 12

GPS_and_GSM_Module_for_Emergency_Alert:
-GSM: RX (Pin 8), TX (Pin 9)
-GPS: RX (Nano TX), TX (Nano RX)
-Push Button: Pin 11 and GND

Upload Code:
-Use Arduino IDE to upload the first code to Arduino Uno.
-Use Arduino IDE to upload the second code to Arduino Nano.

Connect Components according to the circuit diagram. Power Up the system and wear the cap.
The smart cap will provide obstacle detection alerts through vibrations. Pressing the push button will send the current location to the predefined contact number.
