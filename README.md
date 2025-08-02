# Echo-Home
This project demonstrates a voice-activated appliance control system where users can set LEDs of various colors and a fan on or off using voice commands. This system processes the received voice inputs to carry out commands quickly, so it's possible to use the name of any required color, like "green" or "red," to turn the respective LED on or off, and even the power state for controlling the fan. Such a configuration helps make smart home automation more intuitive and accessible in an era when user-friendly voice technology is only going to become even more popular.

The main aim of the project is to design a voice command recognition and execution system that is reliable, efficient, and accurate, capable of controlling appliances without any direct physical intervention. This project combines the architecture of a microcontroller with voice recognition and IoT communication to provide more reliable operation and tests the performance of the voice recognition system under various conditions, like different noise levels and voice variations.

### Hardware Components
* Arduino Uno: Acting as the central processing unit, the Arduino Uno receives commands from the Bluetooth module, interprets them, and then activates the appropriate outputs to control the LEDs or motor.
* HC-05 Bluetooth Module: This Bluetooth module facilitates wireless communication between the Arduino and the user’s smartphone, which is configured to send voice commands. The HC-05 supports a range of up to 10 meters, making it suitable for short-distance, handsfree control.
* 1-Channel Relay Module: The relay serves as a switch, allowing the Arduino to control the DC motor's power. When a relevant command is detected, the Arduino activates the relay, turning the motor on or off based on the user’s input.
* LED Lights of Different Colors: Multiple LEDs, each representing a different color, are connected to the Arduino. Each LED is mapped to a specific command, enabling the user to control individual LEDs by specifying their color in voice commands.
* DC Motor with fan: Representing an appliance like a fan, the DC motor is controlled through the relay module. Voice commands prompt the Arduino to activate the relay, turning the motor on or off in response.
* Battery: A battery powers the entire system, providing energy to the Arduino, LEDs, relay, and motor. This battery-powered setup makes the system portable and ideal for deployment in
areas without constant access to power.
* Breadboard and Jumper Wires: These components are essential for prototyping, enabling connections between the microcontroller, LEDs, relay, and Bluetooth module.

### Software Components
* Arduino IDE: Arduino Integrated Development Environment is a software used for developing, compiling, and uploading the code into the Arduino Uno microcontroller. In this project, some main features of the Arduino IDE are utilized.
* Mobile App for Voice Command Input: A smartphone app is a Bluetooth voice command tool, allowing customers to converse with the system in the most intuitive way. The smartphone app provides voice-to-text conversion as well as transferring data, which are fundamental functionalities of the system.
