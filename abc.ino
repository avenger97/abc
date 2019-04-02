#include <Servo.h>
int led=3;
int pot1;
int pot2;
Servo s1;


void setup()
{
  s1.attach(9);
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(led,OUTPUT);
  
}

void loop()
{
 // s1.write(90);

  int pot1=analogRead(A0);
  int pot2=analogRead(A1);
  int angle_s=map(pot1,0,1023,360,0);
  int speed=map(pot2,0,1023,0,320);
  int angle_w=0;
  if(speed>160)
  { 
  	digitalWrite(led,HIGH);
    	if(angle_s>180)
        {
          	angle_w=90+(angle_s-180)/20;
        }
      	else
        {
        	angle_w=90-(180-angle_s)/20;
        }
  		s1.write(angle_w);
  	
  }
  else
  {
  	digitalWrite(led,LOW);
        	if(angle_s>180)
        {
          	angle_w=90+(angle_s-180)/16;
        }
      	else
        {
        	angle_w=90-(180-angle_s)/16;
        }
  		s1.write(angle_w);

    
  }
  if(angle_w > 33.75 || angle_w < -33.5)
  {
  angle_w=33.75;
  }
  
  
  Serial.print("Steering angle=");
  Serial.print(angle_s-180);
  Serial.print(" || Wheel angle=");
  Serial.print(90-angle_w);
  Serial.print(" || Speed=");
  Serial.println(speed);
  Serial.println("Hello");
 
    
}
