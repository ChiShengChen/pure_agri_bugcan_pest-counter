 
#ifndef __IR_RECV_COUNTER__
#define __IR_RECV_COUNTER__

#define DEF_TYPE_ANALOG          0   //for analog pin 
#define DEF_TYPE_DIGITAL         1   //for digital pin

#define DEF_ANALOG_VOL_MIN		 0   
#define DEF_ANALOG_VOL_MAX		 5

#define DEF_DIGITAL_VOL_H		 3
#define DEF_DIGITAL_VOL_L        2
#include "arduino.h"
float dataMap(int nValue, float fInMin, float fInMax, float fOutMin, float fOutMax);
class CIRRecvCounter
{
private:
	unsigned long m_ulCount;
	bool m_bIsLToH;
	int m_nPinPrevStatus;
	int m_nPinNum;
    int m_nPinType;
	
	
public:
 
	/*
        nPinNum: GPIO Pin number
        nPinType : GPIO Type, analog = 0, digital = 1
    */
    CIRRecvCounter(int nPinNum, int nPinType = DEF_TYPE_DIGITAL);
	~CIRRecvCounter();
	
	void resetCount();
	
	long getCount();
	
	void IRRecvCount(int nCycleTime);

    int GetPinStatus();
	
};

#endif 

 
