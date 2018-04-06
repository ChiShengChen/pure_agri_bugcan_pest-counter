# pure_agri_bugcan_pest-counter

## pure bugcan
with 3 sets of ir sensors   
  
    
Wiring:
  
red<--->5V  
black<--->GND   
ELSE:   
signalpins<--->digital pin  
  
## With RS485 
  
Arduino Nano(slave)-----MAX485 modbus module1-----MAX485 modbus module2-----Arduino UNO(master)    
pinTX1(TX)    
pinRX0(RX)    
