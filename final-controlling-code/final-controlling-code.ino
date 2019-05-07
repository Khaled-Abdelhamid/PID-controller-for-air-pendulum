/*
  ESC Calibrate
ESC data pin attached to Digital Pin 10 on the arduino.
A potentiometer/a Joystick input attached to Analog Pin A0 on the Arduino.

Compile and upload the code.Then hold the joystick/potentiometer at its max position and connect the external power source to the ESC.
You will hear a few beeps then put the potentiometer/joystick in its lowest position.This will set the endpoints on the ESC.

  This example code is in the public domain.

  modified 20 March 2017
  by Hrithik Bansal
  www.hrithikbansal.com
 */


#include<Servo.h>           //Include The servo library for the functions used

Servo esc;                  //Declare the ESC as a Servo Object
int input;

float angle;
float initangle;

void setup() 
{
esc.attach(9);           //Attach the ESC to Digital Pin 10
 Serial.begin(9600);      //Begin Reading/Open Serial Monitor
initangle=analogRead(A1);                      //Value of input is analog input on pin A1

/*
esc.write(180);                          //The state of ESC will be the same as the state/position of Joystick   
delay(2);
esc.write(00);    
*/
}

void loop() 
{ 
  input=analogRead(A0);                      //Value of input is analog input on pin A0 (the controlling potentiometer)
  
//Serial.print("Original Input Value:");      //Serial print the original input value
//Serial.print(input);
//Serial.print(" | ");
input=map(analogRead(A0), 0, 1023, 1000, 2000); //Map the input values from the joystick on analog pin 0 to  correspond to max and min values for the servo output: 180 and 0
 //Serial.print("Mapped Input Value:");
 Serial.print(input);                      //Serial print the mapped input value
 Serial.print(",");
 //Serial.print(" | ");
 //Serial.print("angle read:");
 angle=(initangle-analogRead(A1));                      //Value of input is analog input on pin A1 (on the bodey)
 angle=map(angle,0,164,0,37.476);
 Serial.print(angle); 
 //Serial.print(analogRead(A0));     
 Serial.print("\n");                          //Delay determines your resolution/smoothness and responsiveness of Motor to the movement of Potwntiometer/Joystick.
esc.writeMicroseconds(input);                          //The state of ESC will be the same as the state/position of Joystick

}
