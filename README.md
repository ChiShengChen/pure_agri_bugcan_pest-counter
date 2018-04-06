# pure_agri_bugcan_pest-counter

## pure bugcan
with 3 sets of ir sensors   
  
    
Wiring:
  
red<--->5V  
black<--->GND   
ELSE:   
signalpins<--->digital pin  
  
## With RS485 
  
Arduino_Nano(slave)-----MAX485_modbus_module_1--A<->A|B<->B--MAX485_modbus_module_2-----Arduino_UNO(master)    
pin_TX1(TX)<------------>pin_DI   
pinRX0(RX)    
