#include "IRRecvCounter.h"

//蟲罐
int g_nD4Pin = 4;
int g_nD5Pin = 5;
int g_nD8Pin = 8;
int g_nD9Pin = 9;
int g_nD10Pin = 10;
int g_nD11Pin = 11;
int g_nD12Pin = 12;
int g_nD13Pin = 13;
int g_nA3Pin = A3;
int g_nA4Pin = A4;
int g_nA5Pin = A5;

int timemeow = 100;

CIRRecvCounter g_IRRecvD4(g_nD4Pin, DEF_TYPE_DIGITAL);
CIRRecvCounter g_IRRecvD5(g_nD5Pin, DEF_TYPE_DIGITAL);
CIRRecvCounter g_IRRecvD8(g_nD8Pin, DEF_TYPE_DIGITAL);
CIRRecvCounter g_IRRecvD9(g_nD9Pin, DEF_TYPE_DIGITAL);
CIRRecvCounter g_IRRecvD10(g_nD10Pin, DEF_TYPE_DIGITAL);
CIRRecvCounter g_IRRecvD11(g_nD11Pin, DEF_TYPE_DIGITAL);
CIRRecvCounter g_IRRecvD12(g_nD12Pin, DEF_TYPE_DIGITAL);
CIRRecvCounter g_IRRecvD13(g_nD13Pin, DEF_TYPE_DIGITAL);
CIRRecvCounter g_IRRecvA3(g_nA3Pin, DEF_TYPE_ANALOG);
CIRRecvCounter g_IRRecvA4(g_nA4Pin, DEF_TYPE_ANALOG);
CIRRecvCounter g_IRRecvA5(g_nA5Pin, DEF_TYPE_ANALOG);
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //捕蟲罐1
     g_IRRecvD8.IRRecvCount(timemeow);
     long Count1 = g_IRRecvD8. getCount();

     g_IRRecvD9.IRRecvCount(timemeow);
     long Count2 = g_IRRecvD9. getCount();

     g_IRRecvD10.IRRecvCount(timemeow);
     long Count3 = g_IRRecvD10. getCount();

      //捕蟲罐2
     g_IRRecvA3.IRRecvCount(timemeow);
     long Count4 = g_IRRecvA3. getCount();

     g_IRRecvA4.IRRecvCount(timemeow);
     long Count5 = g_IRRecvA4. getCount();

     g_IRRecvA5.IRRecvCount(timemeow);
     long Count6 = g_IRRecvA5. getCount();

      //捕蟲罐3
     g_IRRecvD11.IRRecvCount(timemeow);
     long Count7 = g_IRRecvD11. getCount();

     g_IRRecvD12.IRRecvCount(timemeow);
     long Count8 = g_IRRecvD12. getCount();

     g_IRRecvD13.IRRecvCount(timemeow);
     long Count9 = g_IRRecvD13. getCount();

     //捕蟲罐4
     g_IRRecvD4.IRRecvCount(timemeow);
     long Count10 = g_IRRecvD4. getCount();

     g_IRRecvD5.IRRecvCount(timemeow);
     long Count11 = g_IRRecvD5. getCount();


       //蟲罐    
    Serial.println("--------Can_1---------"); 
    Serial.println(Count1);
    Serial.println(Count2);
    Serial.println(Count3);
    Serial.println("--------Can_2---------"); 
    Serial.println(Count4);
    Serial.println(Count5);
    Serial.println(Count6);
    Serial.println("--------Can_3---------"); 
    Serial.println(Count7);
    Serial.println(Count8);
    Serial.println(Count9);
    Serial.println("--------Can_4---------"); 
    Serial.println(Count10);
    Serial.println(Count11);
    Serial.println("-----------------------------------------");
}
