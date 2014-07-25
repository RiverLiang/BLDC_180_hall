/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cap0.h
**     Project     : ProcessorExpert
**     Processor   : MC56F84789VLL
**     Component   : Capture
**     Version     : Component 02.223, Driver 02.05, CPU db: 3.50.001
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-07-09, 14:05, # CodeGen: 74
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Driver      :
**         It is recommended to use method GetCaptureValue in event OnCapture.
**         Content of the capture register is protected from update only
**         to end of event Cap0_OnCapture.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TMRA0
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
**              Capture                : TMRA_0_CAPT [E142]
**              Counter                : TMRA_0_CNTR [E145]
**              Mode                   : TMRA_0_CTRL [E146]
**              Run                    : TMRA_0_CTRL [E146]
**              Prescaler              : TMRA_0_CTRL [E146]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       11            |  GPIOC3/TA0/CMPA_O/RXD0/CLKIN1
**             ----------------------------------------------------
**
**         Port name                   : GPIOC_Low
**         Bit number (in port)        : 3
**         Bit mask of the port        : 0008
**
**         Signal edge/level           : both
**         Priority                    : 1
**         Pull option                 : up
**
**     Contents    :
**         Reset           - byte Cap0_Reset(void);
**         GetCaptureValue - byte Cap0_GetCaptureValue(Cap0_TCapturedValue *Value);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Cap0.h
** @version 02.05
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup Cap0_module Cap0 module documentation
**  @{
*/         

#ifndef __Cap0
#define __Cap0

/* MODULE Cap0. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#ifndef __BWUserType_Cap0_TCapturedValue
#define __BWUserType_Cap0_TCapturedValue
  typedef word Cap0_TCapturedValue;    /* Captured value, unsigned integer value. Bit-width of the type depends on the width of selected timer. */
#endif

#define Cap0_PRESCALER_VALUE 0x80UL    /* Initial prescaler value of the timer. It is available only if the bean is enabled in high speed mode. */
#define Cap0_PRESCALER_VALUE_HIGH 0x80UL /* Prescaler value of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */
#define Cap0_COUNTER_INPUT_CLOCK_HZ_HIGH 0x000BEBC2UL /* Counter input clock value in high speed mode [Hz] (integer number). It is available only if the bean is enabled in high speed mode. */
#define Cap0_COUNTER_INPUT_CLOCK_HZ 0x000BEBC2UL /* Initial counter input clock value [Hz] (integer number). It is available only if the bean is enabled in high speed mode. */
/* Deprecated constants */
#define Cap0_CFhigh        0x000BEBC2UL /* Frequency of counting in high speed CPU mode */

byte Cap0_Reset(void);
/*
** ===================================================================
**     Method      :  Cap0_Reset (component Capture)
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

byte Cap0_GetCaptureValue(Cap0_TCapturedValue *Value);
/*
** ===================================================================
**     Method      :  Cap0_GetCaptureValue (component Capture)
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

void Cap0_Init(void);
/*
** ===================================================================
**     Method      :  Cap0_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void Cap0_Interrupt(void);
/*
** ===================================================================
**     Method      :  Cap0_Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the beans event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Cap0. */

#endif /* ifndef __Cap0 */
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