/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : F6.c
**     Project     : ProcessorExpert
**     Processor   : MC56F84789VLL
**     Component   : BitIO
**     Version     : Component 02.086, Driver 01.20, CPU db: 3.50.001
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-07-15, 16:35, # CodeGen: 85
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
**                       94            |  GPIOF6/TB2/PWMA_3X/PWMB_3X/XB_IN2
**             ----------------------------------------------------
**
**         Port name                   : GPIOF_Low
**
**         Bit number (in port)        : 6
**         Bit mask of the port        : 0040
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
**         GetVal - bool F6_GetVal(void);
**         PutVal - void F6_PutVal(bool Val);
**         ClrVal - void F6_ClrVal(void);
**         SetVal - void F6_SetVal(void);
**         NegVal - void F6_NegVal(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file F6.c
** @version 01.20
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup F6_module F6 module documentation
**  @{
*/         

/* MODULE F6. */

#include "F6.h"
/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


/*
** ===================================================================
**     Method      :  F6_GetVal (component BitIO)
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
/*
bool F6_GetVal(void)

**  This method is implemented as a macro. See F6.h file.  **

*/

/*
** ===================================================================
**     Method      :  F6_PutVal (component BitIO)
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
void F6_PutVal(bool Val)
{
  if (Val) {                           /* Is it one to be written? */
    setRegBits(GPIOF_DR,F6_PIN_MASK);  /* Set bit on port */
  }
  else {                               /* Is it zero to be written? */
    clrRegBits(GPIOF_DR,F6_PIN_MASK);  /* Clear bit on port */
  }
}

/*
** ===================================================================
**     Method      :  F6_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void F6_SetVal(void)

**  This method is implemented as a macro. See F6.h file.  **
*/

/*
** ===================================================================
**     Method      :  F6_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void F6_ClrVal(void)

**  This method is implemented as a macro. See F6.h file.  **
*/

/*
** ===================================================================
**     Method      :  F6_NegVal (component BitIO)
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void F6_NegVal(void)

**  This method is implemented as a macro. See F6.h file.  **
*/

/* END F6. */

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
