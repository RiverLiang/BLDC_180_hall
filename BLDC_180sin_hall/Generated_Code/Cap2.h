/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cap2.h
**     Project     : ProcessorExpert
**     Processor   : MC56F84789VLL
**     Component   : Capture
**     Version     : Component 02.223, Driver 02.05, CPU db: 3.50.001
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-07-08, 16:54, # CodeGen: 81
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Driver      :
**         It is recommended to use method GetCaptureValue in event OnCapture.
**         Content of the capture register is protected from update only
**         to end of event Cap2_OnCapture.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TMRA2
**             Counter shared          : No
**
**         High speed mode
**             Prescaler               : divide-by-128
**           Maximal time for capture register
**             Xtal ticks              : 671089
**             microseconds            : 83886
**             milliseconds            : 84
**             seconds (real)          : 0.08388608
**             Hz                      : 12
**           One tick of timer is
**             microseconds            : 1.28
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TMRA_2_CAPT [E162]
**              Counter                : TMRA_2_CNTR [E165]
**              Mode                   : TMRA_2_CTRL [E166]
**              Run                    : TMRA_2_CTRL [E166]
**              Prescaler              : TMRA_2_CTRL [E166]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       49            |  GPIOC6/TA2/XB_IN3/CMP_REF
**             ----------------------------------------------------
**
**         Port name                   : GPIOC_Low
**         Bit number (in port)        : 6
**         Bit mask of the port        : 0040
**
**         Signal edge/level           : both
**         Priority                    : 1
**         Pull option                 : up
**
**     Contents    :
**         Reset           - byte Cap2_Reset(void);
**         GetCaptureValue - byte Cap2_GetCaptureValue(Cap2_TCapturedValue *Value);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Cap2.h
** @version 02.05
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup Cap2_module Cap2 module documentation
**  @{
*/         

#ifndef __Cap2
#define __Cap2

/* MODULE Cap2. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#ifndef __BWUserType_Cap2_TCapturedValue
#define __BWUserType_Cap2_TCapturedValue
  typedef word Cap2_TCapturedValue;    /* Captured value, unsigned integer value. Bit-width of the type depends on the width of selected timer. */
#endif

#define Cap2_PRESCALER_VALUE 0x80UL    /* Initial prescaler value of the timer. It is available only if the bean is enabled in high speed mode. */
#define Cap2_PRESCALER_VALUE_HIGH 0x80UL /* Prescaler value of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */
#define Cap2_COUNTER_INPUT_CLOCK_HZ_HIGH 0x000BEBC2UL /* Counter input clock value in high speed mode [Hz] (integer number). It is available only if the bean is enabled in high speed mode. */
#define Cap2_COUNTER_INPUT_CLOCK_HZ 0x000BEBC2UL /* Initial counter input clock value [Hz] (integer number). It is available only if the bean is enabled in high speed mode. */
/* Deprecated constants */
#define Cap2_CFhigh        0x000BEBC2UL /* Frequency of counting in high speed CPU mode */

byte Cap2_Reset(void);
/*
** ===================================================================
**     Method      :  Cap2_Reset (component Capture)
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte Cap2_GetCaptureValue(Cap2_TCapturedValue *Value);
/*
** ===================================================================
**     Method      :  Cap2_GetCaptureValue (component Capture)
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               1.28 us in high speed mode
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

void Cap2_Init(void);
/*
** ===================================================================
**     Method      :  Cap2_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void Cap2_Interrupt(void);
/*
** ===================================================================
**     Method      :  Cap2_Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the beans event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Cap2. */

#endif /* ifndef __Cap2 */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/