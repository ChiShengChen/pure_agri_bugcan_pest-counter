# pure_agri_bugcan_pest-counter

## pure bugcan
with 3 sets of ir sensors   
  
    
Wiring:

|Arduino_Nano(slave) |IR_Bugcan|
| ---------- | -----------|
| red | 5V   |
|black   | GND   |
| signalpins | digital pins  |    
  

  
## With RS485   
Arduino_Nano(slave) TO MAX485_modbus_module_1:  
    
|Arduino_Nano(slave) |MAX485_modbus_module_1|
| ---------- | -----------|
| pin_TX1(TX) | pin_DI   |
| pin_RX0(RX)   | pin_RO  |
| pin_D3 | pin_DE、pin_RE |

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
