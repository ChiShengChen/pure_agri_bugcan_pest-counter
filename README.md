# pure_agri_bugcan_pest-counter

## pure bugcan
with 3 sets of ir sensors   
  
    
Wiring:
  
red<--->5V  
black<--->GND   
ELSE:   
signalpins<--->digital pin  
  
## With RS485   
Arduino_Nano(slave) TO MAX485_modbus_module_1:  
    
|Arduino_Nano(slave) |MAX485_modbus_module_1|
| ---------- | -----------|
| pin_TX1(TX) | pin_DI   |
| pinRX0(RX)     | 表格单元   |

MAX485_modbus_module_1、MAX485_modbus_module_2 connection:   
    
|MAX485_modbus_module_1|MAX485_modbus_module_2|
|-----------| -----------|
|A  | A |
|B  | B |   


MAX485_modbus_module_2 TO Arduino_UNO(master):    
    
|MAX485_modbus_module_2|Arduino_UNO(master)|
|-----------| -----------|
|表格单元   | 表格单元   |
|表格单元   | 表格单元   |
