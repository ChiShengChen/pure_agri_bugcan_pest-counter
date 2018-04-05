//ir沒遮斷 == HIGH
//for arduino nano
#include <SoftwareSerial.h> 
#define SSerialRX 0
#define SSerialTX 1
#define SSerialTxControl 3   //RS485 Direction control 
#define RS485Transmit HIGH 
#define RS485Receive LOW 
#define Pin12LED 12 
SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX 
int byteReceived;
int byteSend; 

int bcc1 = 4;
int bcc2 = 5;
int bcc3 = 6;
int LED1 = 8;
int LED2 = 9;
int LED3 = 10;
int ch1, ch2, ch3 = 0;
unsigned int t = 500;
unsigned int pestsum = 0;

void setup() {
Serial.begin(9600);   
//Serial.println("SerialRemote");  // Can be ignored     
pinMode(Pin12LED, OUTPUT);    
pinMode(SSerialTxControl, OUTPUT);      
digitalWrite(SSerialTxControl, RS485Receive);  // Init Transceiver     
// Start the software serial port, to another device   
RS485Serial.begin(4800);   // set the data rate 
  
pinMode(bcc1, INPUT_PULLUP);
pinMode(bcc2, INPUT_PULLUP);
pinMode(bcc3, INPUT_PULLUP);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int mode1, mode2, mode3  ;

if (digitalRead(bcc1) == HIGH)
{
  mode1 = 1;
  digitalWrite(LED1, HIGH);
}
else
{
  mode1 = 0;
  digitalWrite(LED1, LOW);
  ch1++;
  delay(t);
}

if (digitalRead(bcc2) == HIGH)
{
  mode2 = 1;
  digitalWrite(LED2, HIGH);
}
else
{
  mode2 = 0;
  digitalWrite(LED2, LOW);
  ch2++;
  delay(t);
}

if (digitalRead(bcc3) == HIGH)
{
  mode3 = 1;
  digitalWrite(LED3, HIGH);
}
else
{
  mode3 = 0;
  digitalWrite(LED3, LOW);
  ch3++;
  delay(t);
}

pestsum = ch1+ch2+ch3;

//Copy input data to output    

//digitalWrite(Pin12LED, HIGH);  // Show activity

byteSend = pestsum;

digitalWrite(Pin12LED, HIGH);  // Show activity
digitalWrite(SSerialTxControl, RS485Transmit);  // Enable RS485 Transmit   
RS485Serial.write(byteSend);          // Send byte to Remote Arduino
digitalWrite(Pin12LED, LOW);  // Show activity    
delay(10);
digitalWrite(SSerialTxControl, RS485Receive);  // Disable RS485 Transmit  

Serial.print("byteSend:");
Serial.println(byteSend);

if (RS485Serial.available())    
{     
Serial.println("RS485Serial.available!");
digitalWrite(Pin12LED, HIGH);  // Show activity
Serial.print("byteSend:");
Serial.print(byteSend);
Serial.println();
delay(10);
digitalWrite(Pin12LED, LOW);  // Show activity           
}

/*Serial.print("ch1:");
Serial.println(ch1);
Serial.print("ch2:");
Serial.println(ch2);
Serial.print("ch3:");
Serial.println(ch3);
Serial.print("pestsum:");
Serial.println(pestsum);
Serial.println("-------------------------");*/

//Serial.print("byteSend:");
//Serial.println(byteSend);
//delay(t);
}
