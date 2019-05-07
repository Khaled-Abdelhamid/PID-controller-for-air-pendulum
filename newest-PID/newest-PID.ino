#include <PID_v1.h>
#include<Servo.h>           //Include The servo library for the functions used
Servo esc;  //Declare the ESC as a Servo Object


// the PID factors (our state of the art)
double Kp= 6;
double Ki= 10;
double Kd=0.03;

/*
double Kp= 16.5;
double Ki=.0;
double Kd=0;
/*
/*
// the PID factors
double Kp= 15.60977;
double Ki= 48.2337;
double Kd= 0;
*/
double error = 1;
double memory_error= 0;

double int_error=0;
double diff_error=0;

double controller=0;//controller signal

double Ts=.01;
double goal=15;
double output;


unsigned long T1;
unsigned long T2;

double init_angle=0;
double angle=0;

PID myPID(&angle, &output, &goal, Kp, Ki, Kd, DIRECT);

void setup() {
  // put your setup code here, to run once:

esc.attach(9);           //Attach the ESC to Digital Pin 10
Serial.begin(9600);      //Begin Reading/Open Serial Monitor
init_angle=analogRead(A1);           //the reading of the potentiometer on the bodey
/*
esc.write(180);                          //calibrate the ESC
delay(2);
esc.write(00);
*/
myPID.SetOutputLimits(1000,2000);
myPID.SetMode(AUTOMATIC);

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
  
T1 = micros();//
    /*
    current_angle=analogRead(A1)- init_angle;    
    current_angle=map(current_angle,0,1203,0,40);
    */
    
     //Serial.print("angle read:");
     angle=(init_angle-analogRead(A1));                      //Value of input is analog input on pin A1 (on the bodey)
     angle=map(angle,0.0,164.0,0.0,37.476);
     Serial.print(angle);     
     Serial.print(" , ");
     
     myPID.Compute();
  
     /*
      error= goal - angle;
      int_error += error*Ts ;
      diff_error= (error-memory_error)/Ts;
      memory_error=diff_error;
      
      controller = error*KP + KI*int_error +  diff_error*KD;
      */
      //Serial.print("controller signal:");      //Serial print the original input value
      Serial.print(output);
      //Serial.print(" | ");
      
     Serial.print("\n");
    
    esc.writeMicroseconds(output);                          //The state of ESC will be the same as the state/position of Joystick
  
    T2=micros();
    Ts=(T2-T1)/1000000.0;

}
