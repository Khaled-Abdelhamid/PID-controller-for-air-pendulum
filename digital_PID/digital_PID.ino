#include<Servo.h>           //Include The servo library for the functions used

Servo esc;                  //Declare the ESC as a Servo Object

// the PID factors
float KP= 12;
float KI= 11;
float KD= 0;

float error = 1;        //the signla rerror variable
float memory_error= 0; // the error of the previous iteration

float int_error=0;    //integral error
float diff_error=0;   //differential error

float controller=0;   //controller signal

float Ts=.01;         //the sampling time for each iteration (computed by experiment)
float goal=15;        // the angle we want to reach


//the variables that calculate the Ts
unsigned long T1;    
unsigned long T2;


float init_angle;  //the intial angle (the potentiometer is not se to zero intially)
float angle;       //the angle signal

void setup() {
  

esc.attach(9);                        //Attach the ESC to Digital Pin 9
Serial.begin(9600);                  //Begin Reading/Open Serial Monitor
init_angle=analogRead(A1);           //the reading of the potentiometer on the bodey


/*
esc.write(180);                          //calibrate the ESC
delay(2);
esc.write(00);
*/
}

void loop() {
   
  //PID digital PID
  
T1 = micros();//record intial time
   
     Serial.print("angle read:");
     angle=(init_angle - analogRead(A1));                      //Value of input is analog input on pin A1 (on the bodey)
     angle=map(angle,0.0,164.0,0.0,37.476);                    //the mapping values are measure relative to the dimensions of the bodey and the readings of the sensor
     Serial.print(angle);     
     Serial.print(" | ");

     //the PID equations
      error = goal - angle;
      int_error += error * Ts ;
      diff_error= (error-memory_error)/Ts;
      memory_error=diff_error;
      
      controller = error*KP + KI*int_error +  diff_error*KD;
      
      Serial.print("controller signal:");      //Serial print the original input value
      Serial.print(controller);
      
     Serial.print("\n");
    
    esc.writeMicroseconds(controller);                          //The state of ESC will be the same as the state/position of Joystick
  
    T2=micros();//record final time
    Ts=(T2-T1)/1000000.0;

}
