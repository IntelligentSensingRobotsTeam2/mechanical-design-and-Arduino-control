#include <Servo.h>

Servo myservo;

String state = "CLOSE";
int pos = 0;
int a = 35;
int best = 35;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  //Serial.println("Angle: "+angle);
  roll(a);
  //Serial.println("Done");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(Serial.available()){
    String s = Serial.readString();
    //Serial.print("Data recived: ");
    //Serial.println(s);
    if(s.substring(0,1).toInt() == 0){
      state = "CLOSE";
    }else{
      if(s.substring(0,1).toInt() == 1){
        state = "OPEN";
      }
    }
    a = s.substring(1).toInt();
    //Serial.println(a);
    //Serial.print("Data recived: ");
    //Serial.print(a);
    //Serial.println(s.substring(0,1).toInt());
    
      
  }

  if(state == "CLOSE"){
    digitalWrite(13,LOW);    
  }else{
    if(state == "OPEN"){
    digitalWrite(13,HIGH);
    }
  }

  if(a > 45){
    a = 45;
    //Serial.println(a);
  }
  roll(a);
  //Serial.print("State:");
  //Serial.println(state);
  //delay(1000);
  
}


void roll(int t){
  if(t > pos){
    while(t > pos){
      pos = pos + 1;
      myservo.write(pos);
     // Serial.print("Pos: ");
      //Serial.println(pos);
      //Serial.print("Target: ");
      //Serial.println(t);
      //Serial.print("State: ");
      //Serial.println(state);
      delay(2); 
    }
  }else{
    while(t < pos){
      pos = pos - 1;
      myservo.write(pos);
      //Serial.print("Pos: ");
      //Serial.println(pos);
      //Serial.print("Target: ");
      //Serial.println(t);
      //Serial.print("State: ");
      //Serial.println(state);
      delay(2); 
    }
  }
  
}

