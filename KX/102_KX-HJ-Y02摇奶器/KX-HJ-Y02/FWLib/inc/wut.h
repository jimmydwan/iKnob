/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/*****************************************************************************/
/** \file wut.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __WUT_H__
#define __WUT_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f731xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 ** ��ʱ���� ʱ�ӷ�Ƶϵ��
---------------------------------------------------------------------------*/
#define		WUT_CLK_DIV_1 			(0x00)		// 1��Ƶ
#define		WUT_CLK_DIV_8 			(0x01)		// 8��Ƶ
#define		WUT_CLK_DIV_32 			(0x02)		// 32��Ƶ
#define		WUT_CLK_DIV_256 		(0x03)		// 256��Ƶ

/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

/*****************************************************************************
 ** \brief	 WUT_EnableWUTWakeUp
 **			 ʹ��WUT��ʱ����System����
 ** \param [in] none
 **
 ** \return none
 ** \note   
 *****************************************************************************/
void WUT_EnableWUTWakeUp(void);
/*****************************************************************************
 ** \brief	 WUT_DisableWUTWakeUp
 **			 �رն�ʱ����System����
 ** \param [in] none
 **
 ** \return none
 ** \note   
 *****************************************************************************/
void WUT_DisableWUTWakeUp(void);

/*****************************************************************************
 ** \brief	 WUT_ConfigCLK
 **			���ö�ʱ����ʱ��
 ** \param [in] clkdiv: (1)WUT_CLK_DIV_1 
 **						(2)WUT_CLK_DIV_8
 **						(2)WUT_CLK_DIV_32
**						(2)WUT_CLK_DIV_256
 ** \return none
 ** \note   
 *****************************************************************************/
void WUT_ConfigCLK(uint8_t clkdiv );

/*****************************************************************************
 ** \brief	 WUT_ConfigTime
 **			���ö�ʱ����ʱ��
 ** \param [in] time: 12it��0x0 ~ 0xFFF��
 ** \return none
 ** \note   
 *****************************************************************************/
void WUT_ConfigTime(uint16_t time );
/*****************************************************************************
 ** \brief	 WUT_GetOverflowFlag
 **			 ��ȡWUT��ʱ�����������־
 ** \param [in] none
 ** \return   0�������   1�����
 ** \note
 *****************************************************************************/
uint8_t WUT_GetOverflowFlag(void);
/*****************************************************************************
 ** \brief	 WUT_ClearOverflowFlag
 **			 ���WUT��ʱ�����������־
 ** \param [in] none
 ** \return   none
 ** \note
 *****************************************************************************/
void WUT_ClearOverflowFlag(void);


#endif /*  __WUT_H__ */



