/*
 * ControlParams.h
 *
 *  Created on: Jul 1, 2014
 *      Author: B46561
 */

#ifndef CONTROLPARAMS_H_
#define CONTROLPARAMS_H_


typedef struct
{
	Frac16 TargetSpeed;
	Frac16 SpeedFdb;
	Frac16 SpeedRef;
}BLDCControl ;

extern BLDCControl BLDC;

void ControlParams_Init(void);

#endif /* CONTROLPARAMS_H_ */
