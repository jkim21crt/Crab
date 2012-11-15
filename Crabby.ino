#include <Servo.h>

Servo left;
Servo right;

int counter;
int ground = 0;
int hold = 120;
int lHigh =100;
int lLow = 60;
int rLow = 80;
int rHigh = 120;
int rightpos;
int center = 90;
int incomingByte;

int trig1 = 4; // front
int trig2 = 2;
int trig3 = 5;


int LED = 3;

int trigValue1;
int trigValue2;
int trigValue3;


void setup()
{
 
  Serial.begin(9600);
  left.attach(6);
  right.attach(7);

  pinMode(LED, OUTPUT);
  pinMode(trig1, INPUT);
  pinMode(trig2, INPUT);
  pinMode(trig3, INPUT);

  left.write(lLow);
  right.write(rHigh);
  
}

void loop()
{

 trigValue1 = digitalRead(trig1);
 trigValue2 = digitalRead(trig2);
 trigValue3 = digitalRead(trig3);

 
if(trigValue1 == HIGH && trigValue2 == LOW && trigValue3 == LOW){
  ground =1;
 
}
else if(trigValue2 == HIGH && trigValue3 == LOW)
{
 ground = 2; 
}

else if(trigValue2 ==LOW && trigValue3 == HIGH)
{
 ground = 3; 
}

else { ground = 0;}
 

 
 if(ground==1)
 {
   forward(); 
 }
 
 if(ground==2)
 {

   for(int i = 0; i<30; i++)
   {
   turnLeft();
   }
 
 }
 if(ground==3)
 {

     for(int a = 0; a<30; a++)
   {
   turnRight();
   }
 }
 
 digitalWrite(LED, HIGH);

}//end loop



  void forward(){
  
    delay(hold);
    left.write(lLow);
    right.write(rHigh);
    delay(hold);
    left.write(lHigh);
    right.write(rLow);
   
  }
  
void turnLeft(){
  
  delay(hold);  
  left.write(lLow);
  right.write(center);
  delay(hold);
  left.write(lHigh);
  right.write(center);
  
}

void turnRight(){
  
  delay(hold);
  right.write(rHigh);
  left.write(center);
  delay(hold);
  left.write(center);
  right.write(rLow);
}





