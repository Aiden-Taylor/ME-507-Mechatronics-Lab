
#include "Prox_Sensor.h"

const uint8_t VCNL4040_ADDR = 0x60;

//Used to select between upper and lower byte of command register
#define LOWER true
#define UPPER false

//VCNL4040 Command Codes
#define VCNL4040_ALS_CONF 0x00
#define VCNL4040_ALS_THDH 0x01
#define VCNL4040_ALS_THDL 0x02
#define VCNL4040_PS_CONF1 0x03 //Lower
#define VCNL4040_PS_CONF2 0x03 //Upper
#define VCNL4040_PS_CONF3 0x04 //Lower
#define VCNL4040_PS_MS 0x04 //Upper
#define VCNL4040_PS_CANC 0x05
#define VCNL4040_PS_THDL 0x06
#define VCNL4040_PS_THDH 0x07
#define VCNL4040_PS_DATA 0x08
#define VCNL4040_ALS_DATA 0x09
#define VCNL4040_WHITE_DATA 0x0A
#define VCNL4040_INT_FLAG 0x0B //Upper
#define VCNL4040_ID 0x0C



// Code for Functions

//Set the duty cycle of the IR LED. The higher the duty
//ratio, the faster the response time achieved with higher power
//consumption. For example, PS_Duty = 1/320, peak IRED current = 100 mA,
//averaged current consumption is 100 mA/320 = 0.3125 mA.

void VCNL4040::setIRDutyCycle(uint16_t dutyValue)
{
  if(dutyValue > 320 - 1) dutyValue = VCNL4040_PS_DUTY_320;
  else if(dutyValue > 160 - 1) dutyValue = VCNL4040_PS_DUTY_160;
  else if(dutyValue > 80 - 1) dutyValue = VCNL4040_PS_DUTY_80;
  else dutyValue = VCNL4040_PS_DUTY_40;

  bitMask(VCNL4040_PS_CONF1, LOWER, VCNL4040_PS_DUTY_MASK, dutyValue);
}
