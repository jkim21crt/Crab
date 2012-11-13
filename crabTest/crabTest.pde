import processing.serial.*;
import cc.arduino.*;

Serial myPort;
int counter;
int incomingByte;

void setup(){
 size(100,100);
  println(Serial.list());
  
   myPort = new Serial(this, Serial.list()[0], 9600);
             myPort.bufferUntil('\n');



}

void draw(){


    if(keyPressed){
     
    if(key == 'z'){
        myPort.write('A');
        counter = 0;
         
    }
    
    if(key == 'x'){
     myPort.write('B');
     counter = 0;
    }
    
    if(key == 'c'){
     myPort.write('C');
     counter = 0;
    }
    
    if(key == 'b'){
     myPort.write('D');
     counter = 0;
    }
    
    if(key == 'n'){
     myPort.write('E');
     counter = 0;
    }
    
  
    }// key press

 
  
}     // draw


void serialEvent (Serial myPort){
  
              int inByte = myPort.read();
   println(inByte); 
  
               
}



               
    
