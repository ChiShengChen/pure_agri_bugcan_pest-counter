/* YourDuino SoftwareSerialExample1
 *  http://boywhy.blogspot.tw/2017/03/arduinors485.html
   - Connect to another Arduino running "YD_SoftwareSerialExampleRS485_1Remote"
   - Connect this unit Pins 10, 11, Gnd
   - Pin 3 used for RS485 direction control
   - To other unit Pins 11,10, Gnd  (Cross over)
   - Open Serial Monitor, type in top window. 
   - Should see same characters echoed back from remote Arduino

   Questions: terry@yourduino.com 
*/

/*-----( Import needed libraries )-----*/
#include <SoftwareSerial.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define SSerialRX 0  //Serial Receive pin
#define SSerialTX 1  //Serial Transmit pin

#define SSerialTxControl 3   //RS485 Direction control

#define RS485Transmit HIGH
#define RS485Receive LOW

#define Pin12LED 12

/*-----( Declare objects )-----*/
SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX

/*-----( Declare Variables )-----*/
int byteReceived;
int byteSend;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  // Start the built-in serial port, probably to Serial Monitor
  Serial.begin(9600);
  Serial.println("YourDuino.com SoftwareSerial remote loop example");
  Serial.println("Use Serial Monitor, type in upper window, ENTER");
  
  pinMode(Pin12LED, OUTPUT);   
  pinMode(SSerialTxControl, OUTPUT);    
  
  digitalWrite(SSerialTxControl, RS485Receive);  // Init Transceiver   
  
  // Start the software serial port, to another device
  RS485Serial.begin(4800);   // set the data rate 

}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  digitalWrite(Pin12LED, HIGH);  // Show activity
/*  if (Serial.available())
  {
    byteSend = Serial.read();
    digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit   
    RS485Serial.write(byteSend);          // Send byte to Remote Arduino
    digitalWrite(Pin12LED, LOW);  // Show activity    
    delay(10);
    digitalWrite(SSerialTxControl, RS485Receive);  // Disable RS485 Transmit       
   
  }*/
    byteSend = 56;
    digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit   
    RS485Serial.write(byteSend);          // Send byte to Remote Arduino
    digitalWrite(Pin12LED, LOW);  // Show activity    
    delay(10);
    digitalWrite(SSerialTxControl, RS485Receive);  // Disable RS485 Transmit  
    
  if (RS485Serial.available())  //Look for data from other Arduino
   {
    digitalWrite(Pin12LED, HIGH);  // Show activity
//    byteReceived = RS485Serial.read();    // Read received byte
  /*  if (byteReceived!=0 && byteReceived!=10 && byteReceived!=13)
     {
          Serial.print("receive:");        // Show on Serial Monitor
        Serial.write(byteReceived);
        Serial.println();
     }*/
  //  Serial.print("receive:"); // Show on Serial Monitor
    Serial.print("byteSend:");
    Serial.print(byteSend);
 // Serial.write(byteReceived);
    Serial.println();
    
    delay(10);
    digitalWrite(Pin12LED, LOW);  // Show activity   
   }  

}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

//NONE
//*********( THE END )***********
