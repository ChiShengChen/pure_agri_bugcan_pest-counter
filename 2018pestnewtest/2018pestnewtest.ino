int bcc1 = 4;
int bcc2 = 5;
int bcc3 = 7;
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int ch1, ch2, ch3 = 0;
unsigned int t = 500;

void setup() {
pinMode(bcc1, INPUT_PULLUP);
pinMode(bcc2, INPUT_PULLUP);
pinMode(bcc3, INPUT_PULLUP);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
Serial.begin(9600);
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
}

Serial.print("ch1:");
Serial.println(ch1);
Serial.print("ch2:");
Serial.println(ch2);
Serial.print("ch3:");
Serial.println(ch3);
Serial.println("-------------------------");
delay(t);
}
