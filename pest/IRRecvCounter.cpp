
#include "IRRecvCounter.h"


 float dataMap(int nValue, float fInMin, float fInMax, float fOutMin, float fOutMax)
{

	if(fInMax == fInMin)
		return 0.0;
    float fParam = (fOutMax - fOutMin) / (fInMax - fInMin);
    return fParam * nValue + (fOutMin - fParam *  fInMin);
}


CIRRecvCounter::CIRRecvCounter(int nPinNum, int nPinType)
{
	m_ulCount = 0;
	m_bIsLToH = false;
	m_nPinNum = nPinNum;
	m_nPinPrevStatus = HIGH;
    m_nPinType = nPinType;
    if(nPinType == DEF_TYPE_DIGITAL)
        pinMode(nPinNum, INPUT);
	
}

CIRRecvCounter::~CIRRecvCounter()
{
	
}


void CIRRecvCounter::resetCount()
{
	m_ulCount = 0;
}
	
long CIRRecvCounter::getCount()
{
	
 
	return m_ulCount;
}
	
	
void CIRRecvCounter::IRRecvCount(int nCycleTime)
{
    delay(nCycleTime);
	int nPinCurStatus = GetPinStatus(); 
	
	if(m_nPinPrevStatus != nPinCurStatus)
	{
		m_nPinPrevStatus = nPinCurStatus;
        m_nPinPrevStatus == LOW ? m_bIsLToH = false : m_bIsLToH = true;
	}
	else
	{
		return;
	}
		
	if(m_bIsLToH)
    {
		m_ulCount++;
    }
}     
int CIRRecvCounter::GetPinStatus()
{
    int nPinStatus = HIGH;
    if(m_nPinType == DEF_TYPE_ANALOG)
    {
        //switch Analog vol to digital H/L
        int nVal = analogRead(m_nPinNum);
        float fVal = dataMap(nVal, 0, 1023, DEF_ANALOG_VOL_MIN, DEF_ANALOG_VOL_MAX);//[0~1023] map to [0, 5]
		
        if(fVal >= DEF_DIGITAL_VOL_H)
            nPinStatus = HIGH;
        else if(fVal <= DEF_DIGITAL_VOL_L)
            nPinStatus = LOW;

    }
    else
    {
       nPinStatus = digitalRead(m_nPinNum); 
    }
    return nPinStatus;
}
 
