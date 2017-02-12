/*
Connect the HC-05 module and communicate using the serial monitor

The HC-05 defaults to commincation mode when first powered on.
Needs to be placed in to AT mode
After a factory reset the default baud rate for communication mode is 38400

Bluetooth communication between two arduino.

Pins
BT VCC to Arduino 5V out.
BT GND to GND
BT RX to Arduino pin 3 (through a voltage divider)
BT TX to Arduino pin 2 (no need voltage divider)
Developer: Yucel Kilic (yucelkilic@myrafproject.org)
This code is open to all public use under GPLv3: https://www.gnu.org/licenses/gpl-3.0.en.html.
Reference: http://www.martyncurrey.com/connecting-2-arduinos-by-bluetooth-using-a-hc-05-and-a-hc-06-pair-bind-and-link/
*/

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);
// Connect the HC-05 TX to Arduino pin 2 RX.
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
const int LEDopenPin = 13;    // Green LED
const int LEDclosePin = 12;   // Red LED

char c = ' ';
String content = "";

void setup()
{
    // start th serial communication with the host computer
    Serial.begin(9600);
    Serial.println("MS uzerinde HC-05 hazir.");

    // start communication with the HC-05 using 9600
    BTSerial.begin(9600);
    Serial.println("BTSerial baud rate: 9600.");
    digitalWrite(LEDclosePin, LOW);
    digitalWrite(LEDopenPin, LOW);
}

void loop()
{

     // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTSerial.available())
    {
        content = BTSerial.readStringUntil('\n');
        content.trim();
        if(content.equalsIgnoreCase("MS: Kapak acildi!") || content.equalsIgnoreCase("MS: Kapak acik!") || content.equalsIgnoreCase("MS: Kapak zaten acik!")){
          digitalWrite(LEDclosePin, LOW);
          digitalWrite(LEDopenPin, HIGH);
          }
        else if(content.equalsIgnoreCase("MS: Kapak kapandi!") || content.equalsIgnoreCase("MS: Kapak kapali!") || content.equalsIgnoreCase("MS: Kapak zaten kapali!")){
          digitalWrite(LEDclosePin, HIGH);
          digitalWrite(LEDopenPin, LOW);
          }
        Serial.println(content);
    }

    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();

        // mirror the commands back to the serial monitor
        // makes it easy to follow the commands
        Serial.write(c);
        BTSerial.write(c);
    }

}
