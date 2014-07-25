/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : E7.c
**     Project     : ProcessorExpert
**     Processor   : MC56F84789VLL
**     Component   : BitIO
**     Version     : Component 02.086, Driver 01.20, CPU db: 3.50.001
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-07-15, 16:45, # CodeGen: 86
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
**                       85            |  GPIOE7/PWMA_3A/XB_IN5/PWMB_2A
**             ----------------------------------------------------
**
**         Port name                   : GPIOE_Low
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : 0080
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : up
**
**         Port data register          : GPIOE_DR  [E241]
**         Port control register       : GPIOE_DDR [E242]
**         Port function register      : GPIOE_PER [E243]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool E7_GetVal(void);
**         PutVal - void E7_PutVal(bool Val);
**         ClrVal - void E7_ClrVal(void);
**         SetVal - void E7_SetVal(void);
**         NegVal - void E7_NegVal(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file E7.c
** @version 01.20
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup E7_module E7 module documentation
**  @{
*/         

/* MODULE E7. */

#include "E7.h"
/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"


/*
** ===================================================================
**     Method      :  E7_GetVal (component BitIO)
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
bool E7_GetVal(void)

**  This method is implemented as a macro. See E7.h file.  **

*/

/*
** ===================================================================
**     Method      :  E7_PutVal (component BitIO)
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
void E7_PutVal(bool Val)
{
  if (Val) {                           /* Is it one to be written? */
    setRegBits(GPIOE_DR,E7_PIN_MASK);  /* Set bit on port */
  }
  else {                               /* Is it zero to be written? */
    clrRegBits(GPIOE_DR,E7_PIN_MASK);  /* Clear bit on port */
  }
}

/*
** ===================================================================
**     Method      :  E7_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void E7_SetVal(void)

**  This method is implemented as a macro. See E7.h file.  **
*/

/*
** ===================================================================
**     Method      :  E7_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void E7_ClrVal(void)

**  This method is implemented as a macro. See E7.h file.  **
*/

/*
** ===================================================================
**     Method      :  E7_NegVal (component BitIO)
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void E7_NegVal(void)

**  This method is implemented as a macro. See E7.h file.  **
*/

/* END E7. */

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