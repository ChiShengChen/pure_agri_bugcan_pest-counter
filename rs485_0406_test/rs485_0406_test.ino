/*      Master      */
//forked from
//https://www.arduino.cn/thread-47862-1-1.html
//for nano
#include <SoftwareSerial.h>
SoftwareSerial Master(0, 1); 
char val; 
int DE_RE=3;
 
void setup() {
  Serial.begin(38400);   
  Serial.println("Master is ready!");
  Master.begin(38400);
  pinMode(DE_RE,OUTPUT);  
  digitalWrite(DE_RE,LOW); 
}
 
void loop() { 
  while (Serial.available()) {
    digitalWrite(DE_RE,HIGH);
    val = Serial.read();
    Master.write(val);
  }
  
  digitalWrite(DE_RE,LOW);
  while(Master.available()) {
    val = Master.read();
    Serial.write(val);
  }
}
