#include <Servo.h>

Servo left;
Servo right;

int counter;
int leftpos;
int hold = 350;
int leftHigh = 83;
int leftLow = 97;
int rightpos;
int rightHigh = 97;
int rightLow = 83;
int rightStep = 1;
int leftStep = 1;
int center = 90;
int incomingByte;

int trig1 = 3; // front
int trig2 = 4;
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

 // left.write(center);
  //right.write(center);
  pinMode(LED, OUTPUT);
  pinMode(trig1, INPUT);
  pinMode(trig2, INPUT);
  pinMode(trig3, INPUT);

  left.write(90);
  right.write(90);
  
}

void loop()
{
 trigValue1 = digitalRead(trig1);
 trigValue2 = digitalRead(trig2);
 trigValue3 = digitalRead(trig3);

 
 if(trigValue1 == HIGH){
   Serial.write(1);
 }
 
 if(trigValue2 == HIGH){
   Serial.write(2);
 }
 
 if(trigValue3 == HIGH){
   Serial.write(3);
 }
 
 digitalWrite(LED, HIGH);


 if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
  
  if(incomingByte == 'A'){
    left.write(leftHigh);
    right.write(rightLow);
  }
  
  if(incomingByte == 'B'){
  left.write(center);
  right.write(center);
  }
  
  if(incomingByte == 'C'){
  left.write(leftLow);
  right.write(rightHigh);
  }
  
  if(incomingByte == 'D'){
  right.write(rightLow);
  left.write(leftLow);
  }
  
  if(incomingByte == 'E'){
  right.write(rightHigh);
  left.write(leftHigh);
  }
  
  if(incomingByte == 'F'){
  right.write(rightHigh);
  }
  
 } // end serialavailable
}//end loop



  void forward(){
  
    delay(hold);
    left.write(leftHigh);
    right.write(rightLow);
    delay(hold);
    left.write(leftLow);
    right.write(rightHigh);
   
  }
  
void turnLeft(){
  
  delay(hold);  
  left.write(leftHigh);
  right.write(rightLow);
  delay(hold);
  left.write(center);
  right.write(center);
  
}

void turnRight(){
  
  delay(hold);
  left.write(leftLow);
  right.write(rightHigh);
  delay(hold);
  left.write(center);
  right.write(center);
}

void halt(){
  
 left.write(center);
 right.write(center);
 digitalWrite(LED, LOW); 
 
}



