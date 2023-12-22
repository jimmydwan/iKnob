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

/****************************************************************************/
/** \file led.c
**
**  
**
**	History:
**
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "led.h"

/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
****************************************************************************/
/*****************************************************************************
 ** \brief	 LED_EnableMatrixMode
 **			 ʹ��LED��������ģʽ
 ** \param [in] none		
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableMatrixMode(void)
{
	LEDMODE = 0x55;
}
/*****************************************************************************
 ** \brief	 LED_ConfigMatrixMode
 **			 ����LED��������ģʽ
 ** \param [in] ClkSel: (1)	LED_CLK_LSI
 **						(2) LED_CLK_LSE
 **						(3)	LED_CLK_FSYS
 **				Duty:	(1) LED_DUTY_4
 **						(2)	LED_DUTY_5
 **						(3)	LED_DUTY_6
 **						(4)	LED_DUTY_8	  
 **				Common:	(1) LED_COM_CATHODE			��������ģʽ
 **						(2)	LED_COM_ANODE   		��������ģʽ			
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigMatrixMode(uint8_t ClkSel, uint8_t Duty, uint8_t Common)
{
	LEDCON &= 0x80;
	LEDCON |=  ClkSel | (Duty<<LED_LEDCON_DUTY_Pos) | (Common<<LED_LEDCON_CCCA_Pos);	
}
/*****************************************************************************
 ** \brief	 LED_ConfigMatrixClkDiv
 **			 ����LED��������ģʽʱ�ӷ�Ƶ
 ** \param [in] ClkDiv: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigMatrixClkDiv(uint16_t ClkDiv)
{
	LEDCLKL =  (uint8_t)ClkDiv;
	LEDCLKH = (uint8_t)(ClkDiv>>8);
}
/*****************************************************************************
 ** \brief	 LED_ConfigMatrixComTime
 **			 ���þ�������ģʽCOM����Чʱ��
 ** \param [in] Time �� 0x01~0xff
 ** \return  none
 ** \note   ��ֹ���ó�0x00
******************************************************************************/
void LED_ConfigMatrixComTime(uint8_t Time)
{
	LEDCOMTIME = Time;
}
/*****************************************************************************
 ** \brief	 LED_StartMatrix
 **			 ����LED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StartMatrix(void)
{
	LEDCON |= LED_LEDCON_EN_Msk;
}
/*****************************************************************************
 ** \brief	 LED_StopMatrix
 **			 ֹͣLED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StopMatrix(void)
{
	LEDCON &= ~(LED_LEDCON_EN_Msk);
}
	
/*****************************************************************************
 ** \brief	 LED_EnableLatticeMode
 **			 ʹ��LED��������ģʽ
 ** \param [in] none		
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableLatticeMode(void)
{
	LEDMODE = 0xAA;
}
/*****************************************************************************
 ** \brief	 LED_ConfigLatticeMode
 **			 ����LED��������ģʽ
 ** \param [in] ClkSel: (1)	LED_CLK_LSI
 **						(2) LED_CLK_LSE
 **						(3)	LED_CLK_FSYS
 **				Mode:	(1) LED_LATTICE_4X4			4*4����
 **						(2)	LED_LATTICE_5X5			5*5����
 **						(3)	LED_LATTICE_6X6			6*6����
 **						(4)	LED_LATTICE_6X7			6*7����
 **						(5)	LED_LATTICE_7X7			7*7����
 **						(6)	LED_LATTICE_7X8			7*8����
 **						(7)	LED_LATTICE_8X8 		8*8����
 **				Scan:	(1) LED_SCAN_INTERRUPT		�ж�ɨ��ģʽ
 **						(2)	LED_SCAN_LOOP   		ѭ��ɨ��ģʽ			
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticeMode(uint8_t ClkSel, uint8_t Mode, uint8_t Scan)
{
	LEDCON1 &=0x80;
	LEDCON1 |= ClkSel | (Mode<<LED_LEDCON1_DUTY_Pos)|(Scan<<LED_LEDCON1_MODE_Pos);
}
/*****************************************************************************
 ** \brief	 LED_ConfigLatticeClkDiv
 **			 ����LED��������ģʽʱ�ӷ�Ƶ
 ** \param [in] ClkDiv: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticeClkDiv(uint16_t ClkDiv)
{
	LEDCLKL1 =  (uint8_t)ClkDiv;
	LEDCLKH1 = (uint8_t)(ClkDiv>>8);	
}
/*****************************************************************************
 ** \brief	 LED_ConfigLatticePeriod1
 **			 ����LED��������ģʽ������1
 ** \param [in] Period: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticePeriod1(uint16_t Period)
{
	SCAN1WL =  (uint8_t)Period;
	SCAN1WH = (uint8_t)(Period>>8);	
}
/*****************************************************************************
 ** \brief	 LED_ConfigLatticePeriod2
 **			 ����LED��������ģʽ������2
 ** \param [in] Period: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticePeriod2(uint16_t Period)
{
	SCAN2WL =  (uint8_t)Period;
	SCAN2WH = (uint8_t)(Period>>8);			
}

/*****************************************************************************
 ** \brief	 LED_StartLattice
 **			 ����LED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StartLattice(void)
{
	LEDCON1 |= LED_LEDCON1_START_Msk;
}
/*****************************************************************************
 ** \brief	 LED_StopLattice
 **			 ֹͣLED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StopLattice(void)
{
	LEDCON1 &= ~(LED_LEDCON1_START_Msk);
}

/*****************************************************************************
 ** \brief	 LED_RestartLattice
 **			 ����LED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_RestartLattice(void)
{
	LEDCON1 &= ~(LED_LEDCON1_START_Msk);
	LEDCON1 |= LED_LEDCON1_START_Msk;	
}

/*****************************************************************************
 ** \brief	 LED_EnableInt
 **			 ʹ��LED��������ģʽ�ж�
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableInt(void)
{
	LEDSTATUS |= LED_LEDSTATUS_LEDIE_Msk;
}
/*****************************************************************************
 ** \brief	 LED_DisableInt
 **			 �ر�LED��������ģʽ�ж�
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_DisableInt(void)
{
	LEDSTATUS &= ~(LED_LEDSTATUS_LEDIE_Msk);
}
/*****************************************************************************
 ** \brief	 LED_GetIntFlag
 **			 ��ȡLED��������ģʽ�жϱ�־
 ** \param [in] none
 ** \return  0:���ж�  1:�����ж�
 ** \note   
******************************************************************************/
uint8_t LED_GetIntFlag(void)
{
	return((LEDSTATUS & LED_LEDSTATUS_LEDIF_Msk) ? 1:0);
}
/*****************************************************************************
 ** \brief	 LED_ClearIntFlag
 **			 ���LED��������ģʽ�жϱ�־
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ClearIntFlag(void)
{
	LEDSTATUS &= ~(LED_LEDSTATUS_LEDIF_Msk);
}



