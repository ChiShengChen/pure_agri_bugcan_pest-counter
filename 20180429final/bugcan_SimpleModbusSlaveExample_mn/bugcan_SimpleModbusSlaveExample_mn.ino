#include <SimpleModbusSlave.h>

#define  ledPin  13 // onboard led 
#define  buttonPin  7 // push button

/* This example code has 9 holding registers. 6 analogue inputs, 1 button, 1 digital output
   and 1 register to indicate errors encountered since started.
   Function 5 (write single coil) is not implemented so I'm using a whole register
   and function 16 to set the onboard Led on the Atmega328P.
   
   The modbus_update() method updates the holdingRegs register array and checks communication.
   Note:  
   The Arduino serial ring buffer is 128 bytes or 64 registers.
   Most of the time you will connect the arduino to a master via serial
   using a MAX485 or similar.
 
   In a function 3 request the master will attempt to read from your
   slave and since 5 bytes is already used for ID, FUNCTION, NO OF BYTES
   and two BYTES CRC the master can only request 122 bytes or 61 registers.
 
   In a function 16 request the master will attempt to write to your 
   slave and since a 9 bytes is already used for ID, FUNCTION, ADDRESS, 
   NO OF REGISTERS, NO OF BYTES and two BYTES CRC the master can only write
   118 bytes or 59 registers.
 
   Using the FTDI USB to Serial converter the maximum bytes you can send is limited 
   to its internal buffer which is 60 bytes or 30 unsigned int registers. 
 
   Thus:
 
   In a function 3 request the master will attempt to read from your
   slave and since 5 bytes is already used for ID, FUNCTION, NO OF BYTES
   and two BYTES CRC the master can only request 54 bytes or 27 registers.
 
   In a function 16 request the master will attempt to write to your 
   slave and since a 9 bytes is already used for ID, FUNCTION, ADDRESS, 
   NO OF REGISTERS, NO OF BYTES and two BYTES CRC the master can only write
   50 bytes or 25 registers.
 
   Since it is assumed that you will mostly use the Arduino to connect to a 
   master without using a USB to Serial converter the internal buffer is set
   the same as the Arduino Serial ring buffer which is 128 bytes.
*/
 

// Using the enum instruction allows for an easy method for adding and 
// removing registers. Doing it this way saves you #defining the size 
// of your slaves register array each time you want to add more registers
// and at a glimpse informs you of your slaves register layout.

//////////////// registers of your slave ///////////////////
enum //列舉
{     
  // just add or remove registers and your good to go...
  // The first register starts at address 0
  ADC0,     //0   
  ADC1,     //1   
  ADC2,     //2
  ADC3,     //3
  ADC4,     //4
  ADC5,     //5
  LED_STATE,  //6
  BUTTON_STATE,    //7
  TOTAL_ERRORS,    //8
  // leave this one
  TOTAL_REGS_SIZE   //9
  // total number of registers for function 3 and 16 share the same register array
};

unsigned int holdingRegs[TOTAL_REGS_SIZE]; // function 3 and 16 register array
////////////////////////////////////////////////////////////
/////////////////蟲罐////////////////////
//ir沒遮斷 == HIGH
int bcc1 = 4;
int bcc2 = 5;
int bcc3 = 7;
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int ch1, ch2, ch3, pestNum = 0;
unsigned int t = 1000;

void setup()
{
  /* parameters(long baudrate, 
                unsigned char ID, 
                unsigned char transmit enable pin, 
                unsigned int holding registers size,
                unsigned char low latency)
                
     The transmit enable pin is used in half duplex communication to activate a MAX485 or similar
     to deactivate this mode use any value < 2 because 0 & 1 is reserved for Rx & Tx.
     Low latency delays makes the implementation non-standard
     but practically it works with all major modbus master implementations.
  */
  
  modbus_configure(115200, 3, 3, TOTAL_REGS_SIZE, 0);
  //modbus_configure(long baud, unsigned char _slaveID, unsigned char _TxEnablePin, unsigned int _holdingRegsSize, unsigned char _lowLatency)
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

//////////////蟲罐/////////////////////////
 pinMode(bcc1, INPUT_PULLUP);
 pinMode(bcc2, INPUT_PULLUP);
 pinMode(bcc3, INPUT_PULLUP);
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 Serial.begin(9600);
}

void loop()
{
  ////////////蟲罐//////////////////////////
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

  pestNum = ch1 + ch2 + ch3;
    
  Serial.print("ch1:");
  Serial.println(ch1);
  Serial.print("ch2:");
  Serial.println(ch2);
  Serial.print("ch3:");
  Serial.println(ch3);
  Serial.println("-------------------------");
  delay(t);
  
  ////////////////////////////////////////////////////////////
  // modbus_update() is the only method used in loop(). It returns the total error
  // count since the slave started. You don't have to use it but it's useful
  // for fault finding by the modbus master.
  holdingRegs[TOTAL_ERRORS] = modbus_update(holdingRegs);

  holdingRegs[3] = pestNum;
/*  for (byte i = 0; i < 6; i++)
  {
    holdingRegs[i] = analogRead(i);
    delayMicroseconds(50);	     
  }*/




  ////////////////////resetLED-BUTTON////////////////////////////
  byte buttonState = digitalRead(buttonPin); // read button states
  
  // assign the buttonState value to the holding register
  holdingRegs[BUTTON_STATE] = buttonState; 
  
  // read the LED_STATE register value and set the onboard LED high or low with function 16
  byte ledState = holdingRegs[LED_STATE]; 
  
  if (ledState) // set led		  
    digitalWrite(ledPin, HIGH);
  if (ledState == 0 || buttonState) // reset led
  {
    digitalWrite(ledPin, LOW);
    holdingRegs[LED_STATE] = 0;
  }
}
