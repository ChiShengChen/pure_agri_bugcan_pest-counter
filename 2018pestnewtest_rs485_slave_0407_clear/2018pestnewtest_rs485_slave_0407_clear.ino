//ir沒遮斷 == HIGH
//for arduino nano
#include <SoftwareSerial.h> 
#define Pin12LED 12 

SoftwareSerial Slave(0, 1);  
char val; 
int DE_RE=3;

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
Serial.begin(38400);   
//Serial.println("SerialRemote");  // Can be ignored     
pinMode(Pin12LED, OUTPUT);    
Serial.println("Slave is ready!");
Slave.begin(38400); 
pinMode(DE_RE,OUTPUT);   
digitalWrite(DE_RE,LOW);
  
pinMode(bcc1, INPUT_PULLUP);
pinMode(bcc2, INPUT_PULLUP);
pinMode(bcc3, INPUT_PULLUP);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);

}

void loop() {
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
digitalWrite(Pin12LED, HIGH);  // Show activity
digitalWrite(Pin12LED, LOW);  // Show activity    
delay(10);
digitalWrite(DE_RE,HIGH); 
val = pestsum;
Slave.write(val);

 
//digitalWrite(DE_RE,LOW);
/*while(Slave.available()) {
  val = Slave.read();
  Serial.write(val);
} */

/*Serial.print("ch1:");
Serial.println(ch1);
Serial.print("ch2:");
Serial.println(ch2);
Serial.print("ch3:");
Serial.println(ch3);
Serial.print("pestsum:");*/
Serial.println(pestsum);
//Serial.println("-------------------------");
delay(t);
}
