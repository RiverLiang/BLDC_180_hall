/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MC56F84789VLL
**     Version     : Driver 01.16
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-07-01, 10:34, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.16
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "FMSTR1.h"
#include "INT_RX_REG.h"
#include "INT_TX_REG.h"
#include "Cap0.h"
#include "Cap1.h"
#include "Cap2.h"
#include "PWMA.h"
#include "F6.h"
#include "E7.h"
#include "PIT_1ms.h"
#include "QSPI0.h"
#include "F0.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "MC33927.h"

#include "Header_File.h"

void main(void)
{
  /* Write your local variable definition here */
UWord8 a = 0;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();               //just init clock
  /*** End of Processor Expert internal initialization.                    ***/

  
  Driver_Init();

  Peripheral_Init();

  MotorParams_Init();
  
  ControlParams_Init();
  

  
  for(;;) 
  {
	  FMSTR1_Poll();
	 // BLDC.SpeedFdb = div_s(PERIOD_TO_SPEED,DeltaA);
	//  counterA = TMRA_0_CAPT;
	// counterB = TMRA_1_CAPT;
	  switch(SystemMode)
	  {
		  case Sys_Stop:
		  {
			  break;  
		  }
		  case Sys_Stop_to_Run:
		  {
			  break;		  
		  }
		  case Sys_Run:
		  {
		  	  break;		  
		  }
		  case Sys_Error:
		  {
			  break;
		  }
		  default:
			  break;
	  }
  }
}


/* END ProcessorExpert */
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
