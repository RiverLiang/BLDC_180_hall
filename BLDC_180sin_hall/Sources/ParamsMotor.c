/*
 * MotorParams.c
 *
 *  Created on: Jul 1, 2014
 *      Author: B46561
 */

#include "Header_File.h"

MotorPara Motor = {4000,24,3,2,0};

UWord16 HallState = 0;//霍尔状态
UWord16 HallFlag = 0;//霍尔标志，记录上一次进入哪个hall中断
void MotorParams_Init()
{
	 
}

static UWord16 HallStateRaw = 0;
void CheckHallState(UWord16 dir)
{
	HallStateRaw = GPIOC_RAWDATA;
	/* scale to range <0-7> */
  	HallState = ((HallStateRaw&0x0040)>>4)  | // HS_C
  				((HallStateRaw&0x0010)>>3)  | // HS_B
  				((HallStateRaw&0x0008)>>3);   // HS_A
  	
  	/* for Counterclockwise direction negate HS state */
  	if(dir)
  		HallState = (~HallState)&0x7;  	  
}


/* MC33937 driver variables */
MC33927_LATCH_T      	DriverSR0;
MC33927_MODE_T       	DriverSR1;
MC33927_LATCH_T      	DriverSR2;
byte			     	DriverSR3;
MC33927_LATCH_T      	DriverClearFlags;
MC33927_MODE_COMMAND_T	DriverModeCommands;

void Driver_Init()
{
	/* Set to clear all error flags */
	DriverClearFlags.W8 = 0xFF;
  /* Clear all flags in SR0 register*/
	MC33927_ClearFlags(&DriverClearFlags);
  /***** Mode setup *****/
  /* 0: when desaturation or phase error on any MOSFET turns off all MOSFETs; 1: desat faults ignored */
	DriverModeCommands.B.DesatFaultMode = 1; 	
	MC33927_ModeCommand(&DriverModeCommands);
  
  /* Set zero deadtime */
	MC33927_ZeroDeadtime();
  /* Read SR0 register */
	MC33927_GetSR0(&DriverSR0);
  /* set DRV_EN for MC33937*/
//    setReg16Bits(GPIOF_DR,0x1);
}
