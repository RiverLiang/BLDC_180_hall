/*
 * SystemParams.h
 *
 *  Created on: Jul 1, 2014
 *      Author: B46561
 */

#ifndef SYSTEMPARAMS_H_
#define SYSTEMPARAMS_H_

#define Sys_Stop                    0
#define Sys_Stop_to_Run             1
#define Sys_Run                     2
#define Sys_Error                   3
extern UWord16 SystemMode;

#define MaxSpeed                    5000
#define BusClk                   100000000
#define QT_PRESCLR                  128
#define PERIOD_TO_SPEED					  (BusClk/MaxSpeed/QT_PRESCLR * 60/(2 * Motor.PolePair))


#endif /* SYSTEMPARAMS_H_ */
