/******************************************************************************
*
* Freescale Semiconductor Inc.
* (c) Copyright 2004-2012 Freescale Semiconductor
* ALL RIGHTS RESERVED.
*
****************************************************************************//*!
*
* @file   freemaster.h
*
* @brief  FreeMASTER Driver main API header file, 56F8xxx platform
*
* @version 1.0.17.0
* 
* @date Oct-2-2012
* 
*******************************************************************************
*
* This is the only header file needed to be included by the user application
* to implement the FreeMASTER interface. In addition, user has to write the
* "freemaster_cfg.h" configuration file and put it anywhere on the #include path
*
*******************************************************************************/

#ifndef __FREEMASTER_H
#define __FREEMASTER_H

/* identify our current platform */
#define FMSTR_PLATFORM_56F8xxx 1

/* FreeMASTER configuration */
#include "freemaster_defcfg.h"

/*****************************************************************************
* Global types
******************************************************************************/

typedef unsigned long  FMSTR_ADDR;              /* CPU address type (use integer data type on 56F8xxx) */
typedef unsigned short FMSTR_SIZE;              /* general size type (at least 16 bits) */
typedef unsigned short FMSTR_BOOL;              /* general boolean type  */

/* application command-specific types */
typedef unsigned short FMSTR_APPCMD_CODE;
typedef unsigned short FMSTR_APPCMD_DATA, *FMSTR_APPCMD_PDATA;
typedef unsigned short FMSTR_APPCMD_RESULT;

/* pointer to application command callback handler */
typedef FMSTR_APPCMD_RESULT (*FMSTR_PAPPCMDFUNC)(FMSTR_APPCMD_CODE,FMSTR_APPCMD_PDATA,FMSTR_SIZE);

/* pipe-related types */
typedef void* FMSTR_HPIPE;                      /* pipe handle */
typedef unsigned short FMSTR_PIPE_PORT;         /* pipe port identifier (unsigned, 7 bits used) */
typedef unsigned short FMSTR_PIPE_SIZE;         /* pipe buffer size type (unsigned, at least 8 bits) */

/* pointer to pipe event handler */
typedef void (*FMSTR_PPIPEFUNC)(FMSTR_HPIPE);

/*****************************************************************************
* TSA-related user types and macros
******************************************************************************/

#include "freemaster_tsa.h"

/*****************************************************************************
* Fast Recorder inline code and macros
******************************************************************************/

#if defined(FMSTR_USE_FASTREC)
#if FMSTR_USE_FASTREC
#include "freemaster_fastrec.h"
#endif
#endif

/*****************************************************************************
* Constants
******************************************************************************/

/* application command status information  */
#define FMSTR_APPCMDRESULT_NOCMD      0xffU
#define FMSTR_APPCMDRESULT_RUNNING    0xfeU
#define MFSTR_APPCMDRESULT_LASTVALID  0xf7U  /* F8-FF are reserved  */

/* recorder time base declaration helpers */
#define FMSTR_REC_BASE_SECONDS(x)  ((x) & 0x3fffU)
#define FMSTR_REC_BASE_MILLISEC(x) (((x) & 0x3fffU) | 0x4000U)
#define FMSTR_REC_BASE_MICROSEC(x) (((x) & 0x3fffU) | 0x8000U)
#define FMSTR_REC_BASE_NANOSEC(x)  (((x) & 0x3fffU) | 0xc000U)

/*****************************************************************************
* Global functions 
******************************************************************************/

/* FreeMASTER serial communication API */
FMSTR_BOOL FMSTR_Init(void);    /* general initialization */
void FMSTR_Poll(void);          /* polling call, use in SHORT_INTR and POLL_DRIVEN modes */
void FMSTR_Isr(void);           /* SCI/JTAG/CAN interrupt handler for LONG_INTR and SHORT_INTR modes */

/* Recorder API */
void FMSTR_Recorder(void);
void FMSTR_TriggerRec(void);
void FMSTR_SetUpRecBuff(FMSTR_ADDR nBuffAddr, FMSTR_SIZE nBuffSize);

/* Application commands API */
FMSTR_APPCMD_CODE  FMSTR_GetAppCmd(void);
FMSTR_APPCMD_PDATA FMSTR_GetAppCmdData(FMSTR_SIZE* pDataLen);
FMSTR_BOOL         FMSTR_RegisterAppCmdCall(FMSTR_APPCMD_CODE nAppCmdCode, FMSTR_PAPPCMDFUNC pCallbackFunc);

void FMSTR_AppCmdAck(FMSTR_APPCMD_RESULT nResultCode);
void FMSTR_AppCmdSetResponseData(FMSTR_ADDR nResultDataAddr, FMSTR_SIZE nResultDataLen);

/* Loss-less Communication Pipes API */
FMSTR_HPIPE FMSTR_PipeOpen(FMSTR_PIPE_PORT nPort, FMSTR_PPIPEFUNC pCallback,
                           FMSTR_ADDR pRxBuff, FMSTR_PIPE_SIZE nRxSize, 
                           FMSTR_ADDR pTxBuff, FMSTR_PIPE_SIZE nTxSize);
void FMSTR_PipeClose(FMSTR_HPIPE hpipe);
FMSTR_PIPE_SIZE FMSTR_PipeWrite(FMSTR_HPIPE hpipe, FMSTR_ADDR addr, FMSTR_PIPE_SIZE length);
FMSTR_PIPE_SIZE FMSTR_PipeWrite8(FMSTR_HPIPE hpipe, FMSTR_ADDR addr, FMSTR_PIPE_SIZE length);
FMSTR_PIPE_SIZE FMSTR_PipeRead(FMSTR_HPIPE hpipe, FMSTR_ADDR addr, FMSTR_PIPE_SIZE length);
FMSTR_PIPE_SIZE FMSTR_PipeRead8(FMSTR_HPIPE hpipe, FMSTR_ADDR addr, FMSTR_PIPE_SIZE length);

/* Pipe printing and formatting */
FMSTR_BOOL FMSTR_PipePuts(FMSTR_HPIPE hpipe, const char* pszStr);
FMSTR_BOOL FMSTR_PipePrintf(FMSTR_HPIPE hpipe, const char* pszFmt, ...);
FMSTR_BOOL FMSTR_PipePrintfU8(FMSTR_HPIPE hpipe, const char* pszFmt, unsigned char arg);
FMSTR_BOOL FMSTR_PipePrintfS8(FMSTR_HPIPE hpipe, const char* pszFmt, signed char arg);
FMSTR_BOOL FMSTR_PipePrintfU16(FMSTR_HPIPE hpipe, const char* pszFmt, unsigned short arg);
FMSTR_BOOL FMSTR_PipePrintfS16(FMSTR_HPIPE hpipe, const char* pszFmt, signed short arg);
FMSTR_BOOL FMSTR_PipePrintfU32(FMSTR_HPIPE hpipe, const char* pszFmt, unsigned long arg);
FMSTR_BOOL FMSTR_PipePrintfS32(FMSTR_HPIPE hpipe, const char* pszFmt, signed long arg);

#endif /* __FREEMASTER_H */

