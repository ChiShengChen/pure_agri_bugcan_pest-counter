# pure_agri_bugcan_pest-counter

## pure bugcan
Each with 3 sets of ir sensors.   
  
    
### Wiring:   
In general:   

|IR_Bugcan|Arduino|
| ---------- | -----------|
| red | 5V   |
|black   | GND   |
|else signalwires | digital pins  |    

in the RS485 code:    
    
|IR_Bugcan|Arduino_Nano|
| ---------- | -----------|
| red | 5V   |
|black   | GND   |
|blue(channel 1) | pin_D4  | 
|white(channel 2) | pin_D5  | 
|yellow(channel 3) | pin_D6  |     

LEDs for debugging:   
    
|LED|Arduino|
|------------|----------------|
|LEDs| D7、D8、D9|

  
## With RS485   
### Wiring:       
    
IR_Bugcan TO  Arduino_Nano(slave):  
    
|IR_Bugcan|Arduino_Nano|
| ---------- | -----------|
| red | 5V   |
|black   | GND   |
|blue(channel 1) | pin_D4  | 
|white(channel 2) | pin_D5  | 
|yellow(channel 3) | pin_D6  |     

LEDs for debugging:   
    
|LED|Arduino|
|------------|----------------|
|LEDs for bugcan debugging| D7(ch1)、D8(ch2)、D9(ch3)|
|LED for RS485 debugging| D12|   

Arduino_Nano(slave) TO MAX485_modbus_module_1:  
    
|Arduino_Nano(slave) |MAX485_modbus_module_1|
| ---------- | -----------|
| pin_TX1(TX) | pin_DI   |
| pin_RX0(RX)   | pin_RO  |
| pin_D3 | pin_DE、pin_RE |
|5V|VCC|
|GND|GND|

MAX485_modbus_module_1、MAX485_modbus_module_2 connection:   
    
|MAX485_modbus_module_1|MAX485_modbus_module_2|
|-----------| -----------|
|A  | A |
|B  | B |   


MAX485_modbus_module_2 TO Arduino_UNO(master):    
    
|MAX485_modbus_module_2|Arduino_UNO(master)|
|-----------| -----------|
|pin_DI   | pin_11   |
|pin_RO   | pin_10   |
|pin_DE、pin_RE| pin_3|
|VCC|5V|
|GND|GND|

