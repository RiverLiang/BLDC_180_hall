/*
 * MotorParams.h
 *
 *  Created on: Jul 1, 2014
 *      Author: B46561
 */

#ifndef MOTORPARAMS_H_
#define MOTORPARAMS_H_

typedef struct
{
	UWord16 RatedSpeed ;
	UWord16 RatedVoltage;
	UWord16 RatedCurrent;
	UWord16 PolePair;
	UWord16 DirectionFlag;//0:foreward   1:reversal
}MotorPara ;
extern MotorPara Motor;

extern UWord16 HallState;
extern UWord16 HallFlag;
void MotorParams_Init(void);
void CheckHallState(UWord16 dir);

extern MC33927_LATCH_T      	DriverSR0;
extern MC33927_MODE_T       	DriverSR1;
extern MC33927_LATCH_T      	DriverSR2;
extern byte			     	    DriverSR3;
extern MC33927_LATCH_T      	DriverClearFlags;
extern MC33927_MODE_COMMAND_T	DriverModeCommands;
void Driver_Init(void);
#define DriverEnable                F0_SetVal()
#define DriverDisable               F0_ClrVal()

#endif /* MOTORPARAMS_H_ */
