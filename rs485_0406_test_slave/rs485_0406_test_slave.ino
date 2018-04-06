/*      Slave     */
//forked from
//https://www.arduino.cn/thread-47862-1-1.html
#include <SoftwareSerial.h>
SoftwareSerial Slave(10, 11);  
char val; 
int DE_RE=3;
 
void setup() {
  Serial.begin(38400);   
  Serial.println("Slave is ready!");
  Slave.begin(38400); 
  pinMode(DE_RE,OUTPUT);   
  digitalWrite(DE_RE,LOW);
}
 
void loop() {
  while (Serial.available()) {
    digitalWrite(DE_RE,HIGH); 
    val = Serial.read();
    Slave.write(val);
  } 
 
  digitalWrite(DE_RE,LOW);
  while(Slave.available()) {
    val = Slave.read();
    Serial.write(val);
  } 
}
