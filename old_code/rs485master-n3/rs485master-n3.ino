#include <SoftwareSerial.h>

#define SSerialRX 0  //Serial Receive pin
#define SSerialTX 1  //Serial Transmit pin

#define SSerialTxControl 3   //RS485 Direction control

#define RS485Transmit HIGH
#define RS485Receive LOW

#define Pin12LED 12


SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX


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

    byteSend = 56;
    digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit   
    RS485Serial.write(byteSend);          // Send byte to Remote Arduino
    digitalWrite(Pin12LED, LOW);  // Show activity    
    delay(10);
    digitalWrite(SSerialTxControl, RS485Receive);  // Disable RS485 Transmit  
    
  if (RS485Serial.available())  //Look for data from other Arduino
   {
    digitalWrite(Pin12LED, HIGH);  // Show activity
    Serial.print("byteSend:");
    Serial.print(byteSend);
    Serial.println();
    delay(10);
    digitalWrite(Pin12LED, LOW);  // Show activity   
   }  

}
