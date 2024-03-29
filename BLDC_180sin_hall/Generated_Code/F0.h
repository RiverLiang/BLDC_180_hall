/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : F0.h
**     Project     : ProcessorExpert
**     Processor   : MC56F84789VLL
**     Component   : BitIO
**     Version     : Component 02.086, Driver 01.20, CPU db: 3.50.001
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-07-16, 16:52, # CodeGen: 111
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       55            |  GPIOF0/XB_IN6/TB2/SCK1
**             ----------------------------------------------------
**
**         Port name                   : GPIOF_Low
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : 0001
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : up
**
**         Port data register          : GPIOF_DR  [E251]
**         Port control register       : GPIOF_DDR [E252]
**         Port function register      : GPIOF_PER [E253]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool F0_GetVal(void);
**         PutVal - void F0_PutVal(bool Val);
**         ClrVal - void F0_ClrVal(void);
**         SetVal - void F0_SetVal(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file F0.h
** @version 01.20
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup F0_module F0 module documentation
**  @{
*/         

#ifndef __F0_H
#define __F0_H

/* MODULE F0. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


#define F0_PIN_MASK             ((byte)0x01) /* Pin mask */


/*
** ===================================================================
**     Method      :  F0_GetVal (component BitIO)
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define F0_GetVal() ((bool)(getRegBits(GPIOF_DR,F0_PIN_MASK)))

/*
** ===================================================================
**     Method      :  F0_PutVal (component BitIO)
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void F0_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  F0_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define F0_ClrVal() (clrRegBits(GPIOF_DR,F0_PIN_MASK))

/*
** ===================================================================
**     Method      :  F0_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define F0_SetVal() (setRegBits(GPIOF_DR,F0_PIN_MASK))


/* END F0. */

#endif /* __F0_H*/
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
