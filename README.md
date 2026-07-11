#Human Following Robot using Arduino

An Arduino-based Human Following Robot designed to autonomously track and follow a human using IR sensors and an HC-SR04 ultrasonic sensor. The robot adjusts its movement by turning left or right based on the detected direction of the target while maintaining a safe distance using distance measurement.

#Features

- Human following using dual IR sensors
- Distance measurement using HC-SR04 ultrasonic sensor
- Automatic forward and backward movement
- Left and right directional tracking
- DC motor control using the L293D motor driver
- Simple and modular Arduino code
- Low-cost and easy-to-build robotic platform

#Hardware Used

 Arduino Uno * 1 
 L293D Motor Driver * 1 
 HC-SR04 Ultrasonic Sensor * 1 
 IR Sensors * 2 
 DC BO Motors * 4
 Robot Chassis * 1 
 Wheels * 4
 Battery Pack * 1 
 Jumper wires

 #Working Principle

The robot continuously reads data from two IR sensors and one HC-SR04 ultrasonic sensor.

- If the left IR sensor detects the target, the robot turns left.
- If the right IR sensor detects the target, the robot turns right.
- If neither IR sensor detects the target:
  - If the measured distance is greater than 20 cm, the robot moves forward.
  - If the measured distance is less than or equal to 20 cm, the robot moves backward.

This simple control algorithm enables the robot to continuously track and follow a person while maintaining an approximate distance.
