#include <PID_v1.h>
#include<Servo.h>           //Include The servo library for the functions used
Servo esc;  //Declare the ESC as a Servo Object


// the PID factors
double Kp= 12;
double Ki= 11;
double Kd=0;
// the reading below are the ones obained from previous attempts
/*
double Kp= 16.5;
double Ki=5;
double Kd=0;

double Kp= 15.60977;
double Ki= 48.2337;
double Kd= 0;
*/

double error = 1;             //the signla rerror variable
double memory_error= 0;       // the error of the previous iteration

float int_error=0;    //integral error
float diff_error=0;   //differential error

float controller=0;   //controller signal


double Ts=.01;
double goal=15;
double output;


unsigned long T1;
unsigned long T2;

double init_angle=0;
double angle=0;

PID myPID(&angle, &output, &goal, Kp, Ki, Kd, DIRECT);//intialize PID instance

void setup() {
  

esc.attach(9);                       //Attach the ESC to Digital Pin 10
Serial.begin(9600);                  //Begin Reading/Open Serial Monitor
init_angle=analogRead(A1);           //the reading of the potentiometer on the bodey

myPID.SetOutputLimits(1000,2000);    //set the esc input and output limits
myPID.SetMode(AUTOMATIC);            //turn PID on by closing the loop ,as it gets the errror by subtracting the input and output 

   esc.writeMicroseconds(1000);
   Serial.print("angle read:");
   angle=(init_angle-analogRead(A1));                      //Value of input is analog input on pin A1 (on the bodey)
   angle=map(angle,0.0,164.0,0.0,37.476);
   Serial.print(angle);     
   Serial.print(" | ");  
   delay(2000);


}

void loop() {
   
  //PID digital PID
  

     Serial.print("angle read:");
     angle=(init_angle-analogRead(A1));                      //Value of input is analog input on pin A1 (on the bodey)
     angle=map(angle,0.0,164.0,0.0,37.476);
     Serial.print(angle);     
     Serial.print(" | ");
     
     myPID.Compute();

    Serial.print("controller signal:");      //Serial print the original input value
    Serial.print(output);
    Serial.print(" | ");
      
    Serial.print("\n");
    
    esc.writeMicroseconds(output);                          //The state of ESC will be the same as the state/position of Joystick
  
   
}
