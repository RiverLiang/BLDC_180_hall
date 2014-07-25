/* ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MC56F84789VLL
**     Component   : Events
**     Version     : Driver 01.03
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2014-07-01, 10:34, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.03
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Header_File.h"
UWord16 counterA = 0;
UWord16 counterB = 0;
UWord16 counterC = 0;

static UWord16 edgeA = 0;
static UWord16 edgeB = 0;
static UWord16 edgeC = 0;
static UWord16 edgeA_1 = 0;
static UWord16 edgeB_1 = 0;
static UWord16 edgeC_1 = 0;

UWord16 DeltaA = 0;
UWord16 DeltaB = 0;
UWord16 DeltaC = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cap0_OnCapture (module Events)
**
**     Component   :  Cap0 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void Cap0_OnCapture(void)
{
	//count the CNT delta
	edgeA = TMRA_0_CAPT;	
	DeltaA = (UWord16)sub((Word16)edgeA , (Word16)edgeA_1);	
	edgeA_1 = edgeA;
//define max period   6*60rpm	
	if(DeltaA > 32767)
		DeltaA = 32767;
	//update Hallstate
	CheckHallState(Motor.DirectionFlag);
	HallFlag = 0;
	
}

/*
** ===================================================================
**     Event       :  Cap1_OnCapture (module Events)
**
**     Component   :  Cap1 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void Cap1_OnCapture(void)
{
	//count the CNT delta
	edgeB = TMRA_1_CAPT;	
	DeltaB = (UWord16)sub((Word16)edgeB , (Word16)edgeB_1);	
	edgeB_1 = edgeB;
//define max period   6*60rpm	
	if(DeltaB > 32767)
		DeltaB = 32767;
	//update Hallstate
	CheckHallState(Motor.DirectionFlag);
	HallFlag = 1;
}

/*
** ===================================================================
**     Event       :  Cap2_OnCapture (module Events)
**
**     Component   :  Cap2 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void Cap2_OnCapture(void)
{
  //count the CNT delta
	edgeC = TMRA_2_CAPT;	
	DeltaC = (UWord16)sub((Word16)edgeC , (Word16)edgeC_1);	
	edgeC_1 = edgeC;
  //define max period   6*60rpm	
	if(DeltaC > 32767)
		DeltaC = 32767;
	//update Hallstate
	CheckHallState(Motor.DirectionFlag);
	HallFlag = 2;
}

/*
** ===================================================================
**     Event       :  PIT_1ms_OnInterrupt (module Events)
**
**     Component   :  PIT_1ms [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/* Comment following line if the appropriate 'Interrupt preserve registers' property */
/* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)           */
#pragma interrupt called
void PIT_1ms_OnInterrupt(void)
{
  /* Write your code here ... */
	
	  MC33927_GetSR0(& DriverSR0);
	  MC33927_GetSR1(& DriverSR1);
	  MC33927_GetSR2(& DriverSR2);
	  DriverSR3 = MC33927_GetSR3();
}

#if defined(PWM_RELOAD_ISR_FAST_INT)
#pragma interrupt fast
#elif defined(PWM_RELOAD_ISR_VECT_TABLE_ISR_FAST_INT)
#pragma define_section interrupt_fast "interrupt_fast.text"  RX
#pragma section interrupt_fast begin
#pragma interrupt fast
#else
#pragma interrupt saveall
#endif
void PWM_RELOAD_ISR(void)
{
	F6_NegVal();
	
	PWMA_MCTRL |= PWMA_MCTRL_LDOK_MASK;
	
	PWMA_SM0STS |= PWMA_SM0STS_RF_MASK; 
}


/* END Events */

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
