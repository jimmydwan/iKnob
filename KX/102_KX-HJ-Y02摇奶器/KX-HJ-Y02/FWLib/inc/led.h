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
/** \file led.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __LED_H__
#define __LED_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f731xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **LEDģʽ
 ---------------------------------------------------------------------------*/
/*-----��������ģʽ---------------------------------------------------------*/
#define LED_DUTY_4			(0x3)		/*1/4 DUTY*/
#define LED_DUTY_5			(0x2)		/*1/5 DUTY*/
#define LED_DUTY_6			(0x1)		/*1/6 DUTY*/
#define LED_DUTY_8			(0x0)		/*1/8 DUTY*/

#define LED_COM_CATHODE		(0x00)		/*��������ģʽ*/
#define LED_COM_ANODE		(0x01)		/*��������ģʽ*/

/*-----��������ģʽ---------------------------------------------------------*/
#define LED_LATTICE_4X4		(0x01)		/*4*4����*/
#define LED_LATTICE_5X5		(0x02)		/*5*5����*/
#define LED_LATTICE_6X6		(0x03)		/*6*6����*/
#define LED_LATTICE_6X7		(0x04)		/*6*7����*/
#define LED_LATTICE_7X7		(0x05)		/*7*7����*/
#define LED_LATTICE_7X8		(0x06)		/*7*8����*/
#define LED_LATTICE_8X8		(0x07)		/*8*8����*/

#define LED_SCAN_INTERRUPT	(0x00)		/*�ж�ɨ��ģʽ*/
#define LED_SCAN_LOOP		(0x01)		/*ѭ��ɨ��ģʽ*/

/*----------------------------------------------------------------------------
 **LED ʱ��Դѡ��
 ---------------------------------------------------------------------------*/
#define LED_CLK_LSI			(0x3)		
#define LED_CLK_LSE			(0x1)
#define LED_CLK_FSYS		(0x0)


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
 ** \brief	 LED_EnableMatrixMode
 **			 ʹ��LED��������ģʽ
 ** \param [in] none		
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableMatrixMode(void);
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
void LED_ConfigMatrixMode(uint8_t ClkSel, uint8_t Duty, uint8_t Common);
/*****************************************************************************
 ** \brief	 LED_ConfigMatrixClkDiv
 **			 ����LED��������ģʽʱ�ӷ�Ƶ
 ** \param [in] ClkDiv: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigMatrixClkDiv(uint16_t ClkDiv);
/*****************************************************************************
 ** \brief	 LED_ConfigMatrixComTime
 **			 ���þ�������ģʽCOM����Чʱ��
 ** \param [in] Time �� 0x01~0xff
 ** \return  none
 ** \note   ��ֹ���ó�0x00
******************************************************************************/
void LED_ConfigMatrixComTime(uint8_t Time);
/*****************************************************************************
 ** \brief	 LED_StartMatrix
 **			 ����LED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StartMatrix(void);
/*****************************************************************************
 ** \brief	 LED_StopMatrix
 **			 ֹͣLED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StopMatrix(void);


/*****************************************************************************
 ** \brief	 LED_EnableLatticeMode
 **			 ʹ��LED��������ģʽ
 ** \param [in] none		
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableLatticeMode(void);
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
void LED_ConfigLatticeMode(uint8_t ClkSel, uint8_t Mode, uint8_t Scan);
/*****************************************************************************
 ** \brief	 LED_ConfigLatticeClkDiv
 **			 ����LED��������ģʽʱ�ӷ�Ƶ
 ** \param [in] ClkDiv: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticeClkDiv(uint16_t ClkDiv);
/*****************************************************************************
 ** \brief	 LED_ConfigLatticePeriod1
 **			 ����LED��������ģʽ������1
 ** \param [in] Period: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticePeriod1(uint16_t Period);
/*****************************************************************************
 ** \brief	 LED_ConfigLatticePeriod2
 **			 ����LED��������ģʽ������2
 ** \param [in] Period: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticePeriod2(uint16_t Period);
/*****************************************************************************
 ** \brief	 LED_StartLattice
 **			 ����LED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StartLattice(void);
/*****************************************************************************
 ** \brief	 LED_StopLattice
 **			 ֹͣLED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StopLattice(void);
/*****************************************************************************
 ** \brief	 LED_RestartLattice
 **			 ����LED��������
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_RestartLattice(void);


/*****************************************************************************
 ** \brief	 LED_EnableInt
 **			 ʹ��LED��������ģʽ�ж�
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableInt(void);
/*****************************************************************************
 ** \brief	 LED_DisableInt
 **			 �ر�LED��������ģʽ�ж�
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_DisableInt(void);
/*****************************************************************************
 ** \brief	 LED_GetIntFlag
 **			 ��ȡLED��������ģʽ�жϱ�־
 ** \param [in] none
 ** \return  0:���ж�  1:�����ж�
 ** \note   
******************************************************************************/
uint8_t LED_GetIntFlag(void);
/*****************************************************************************
 ** \brief	 LED_ClearIntFlag
 **			 ���LED��������ģʽ�жϱ�־
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ClearIntFlag(void);



#endif /* __LED_H__ */
