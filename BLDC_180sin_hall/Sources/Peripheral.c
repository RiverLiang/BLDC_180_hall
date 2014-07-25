/*
 * Device_Init.c
 *
 *  Created on: Jul 1, 2014
 *      Author: B46561
 */
#include "Header_File.h"


void Peripheral_Init()
{
	__EI(0);
}

byte SPI_Send(byte bytData)
{

	/* clear SS - GPIO_C7*/
	clrReg16Bits(GPIOC_DR,0x80);
	
	/* Waits until empty buffer */
	while((QSPI0_SPSCR & QSPI0_SPSCR_SPTE_MASK) == 0)/* test SPTE bit */
	{
	};
	QSPI0_SPDTR = bytData;

	/* Waits until data transferred  */
	while((QSPI0_SPSCR & QSPI0_SPSCR_SPRF_MASK) == 0) /* test SPRF bit */
	{
	};
	
	/* set SS */
	setReg16Bits(GPIOC_DR,0x80);  

	/* Return received data */
	return((unsigned char)QSPI0_SPDRR);      
}
