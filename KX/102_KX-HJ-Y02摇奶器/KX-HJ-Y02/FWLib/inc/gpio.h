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
/** \file gpio.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __GPIO_H__
#define __GPIO_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f731xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **GPIO����
 ---------------------------------------------------------------------------*/
#define  GPIO_PIN_0_MSK				(0x01)		/* GPIO Pin 0 mask */
#define  GPIO_PIN_1_MSK				(0x02)		/* GPIO Pin 1 mask */
#define  GPIO_PIN_2_MSK				(0x04)		/* GPIO Pin 2 mask */
#define  GPIO_PIN_3_MSK				(0x08)		/* GPIO Pin 3 mask */
#define  GPIO_PIN_4_MSK				(0x10)		/* GPIO Pin 4 mask */
#define  GPIO_PIN_5_MSK				(0x20)		/* GPIO Pin 5 mask */
#define  GPIO_PIN_6_MSK				(0x40)		/* GPIO Pin 6 mask */
#define  GPIO_PIN_7_MSK				(0x80)		/* GPIO Pin 7 mask */

#define  GPIO_PIN_0					(0x00)		/* GPIO Pin 0 number*/
#define  GPIO_PIN_1					(0x01)		/* GPIO Pin 1 number */
#define  GPIO_PIN_2					(0x02)		/* GPIO Pin 2 number */
#define  GPIO_PIN_3					(0x03)		/* GPIO Pin 3 number */
#define  GPIO_PIN_4					(0x04)		/* GPIO Pin 4 number */
#define  GPIO_PIN_5					(0x05)		/* GPIO Pin 5 number */
#define  GPIO_PIN_6					(0x06)		/* GPIO Pin 6 number */
#define  GPIO_PIN_7					(0x07)		/* GPIO Pin 7 number */

#define  GPIO0						(0x00)
#define  GPIO1						(0x01)
#define  GPIO2						(0x02)
#define  GPIO5						(0x05)

#define  GPIO_P00					(0x00)
#define  GPIO_P01					(0x01)
#define  GPIO_P02					(0x02)
#define  GPIO_P03					(0x03)
#define  GPIO_P04					(0x04)
#define  GPIO_P05					(0x05)
#define  GPIO_P06					(0x06)
#define  GPIO_P07					(0x07)

#define  GPIO_P10					(0x10)
#define  GPIO_P11					(0x11)
#define  GPIO_P12					(0x12)
#define  GPIO_P13					(0x13)
#define  GPIO_P14					(0x14)
#define  GPIO_P15					(0x15)
#define  GPIO_P16					(0x16)
#define  GPIO_P17					(0x17)

#define  GPIO_P20					(0x20)
#define  GPIO_P21					(0x21)
#define  GPIO_P22					(0x22)
#define  GPIO_P23					(0x23)

#define  GPIO_P50					(0x50)
#define  GPIO_P51					(0x51)
#define  GPIO_P52					(0x52)
#define  GPIO_P53					(0x53)
#define  GPIO_P54					(0x54)
#define  GPIO_P55					(0x55)

/*----------------------------------------------------------------------------
 ** IO���Ÿ���ģʽ
---------------------------------------------------------------------------*/
#define  GPIO_MUX_GPIO		(0x00)			/*GPIO����*/

#define  GPIO_MUX_TXD1		(0x06)			/*TXD1����*/
#define  GPIO_MUX_RXD1		(0x07)			/*RXD1����*/

/*--GPIO���ֹ���---------------------------------------------------------*/
/*--Timer2�Ƚ������ͨ��-----------------------------------------------*/
#define  GPIO_P00_MUX_CC0	(0x04)
#define  GPIO_P01_MUX_CC1	(0x04)
#define  GPIO_P02_MUX_CC2	(0x04)
#define  GPIO_P03_MUX_CC3	(0x04)

#define  GPIO_P20_MUX_CC0	(0x04)
#define  GPIO_P21_MUX_CC1	(0x04)
#define  GPIO_P22_MUX_CC2	(0x04)
#define  GPIO_P23_MUX_CC3	(0x04)

/*--���������ͨ��-----------------------------------------------------*/
#define  GPIO_P06_MUX_BUZZ	(0x04)
#define  GPIO_P16_MUX_BUZZ	(0x04)

/*--ϵͳʱ�����ͨ����ϵͳʱ�ӵ�64��Ƶ����ֻ������IO���ɣ�---------------*/
#define  GPIO_P07_MUX_CLO	(0x04)
#define  GPIO_P17_MUX_CLO	(0x04)

/*--I2Cͨ��----------------------------------------------------------*/
#define  GPIO_P00_MUX_SCL	(0x02)
#define  GPIO_P01_MUX_SDA	(0x02)

#define  GPIO_P10_MUX_SCL	(0x02)
#define  GPIO_P11_MUX_SDA	(0x02)

#define  GPIO_P20_MUX_SCL	(0x02)
#define  GPIO_P21_MUX_SDA	(0x02)

#define  GPIO_P50_MUX_SCL	(0x02)
#define  GPIO_P51_MUX_SDA	(0x02)


/*--����ͨ��-------------------------------------------------------------*/

#define  GPIO_P04_MUX_TXD0	(0x02)
#define  GPIO_P05_MUX_RXD0	(0x02)

#define  GPIO_P14_MUX_TXD0	(0x02)
#define  GPIO_P15_MUX_RXD0	(0x02)

#define  GPIO_P54_MUX_TXD0	(0x02)
#define  GPIO_P55_MUX_RXD0	(0x02)


/*--SPIͨ��-------------------------------------------------------------*/
#define  GPIO_P00_MUX_SCLK	(0x03)
#define  GPIO_P01_MUX_MOSI	(0x03)
#define  GPIO_P02_MUX_MISO	(0x03)
#define  GPIO_P03_MUX_NSS	(0x03)
#define  GPIO_P04_MUX_NSS	(0x03)
#define  GPIO_P05_MUX_NSS	(0x03)
#define  GPIO_P06_MUX_NSS	(0x03)

#define  GPIO_P03_MUX_NSSO0	(0x03)
#define  GPIO_P04_MUX_NSSO1	(0x03)
#define  GPIO_P05_MUX_NSSO2	(0x03)
#define  GPIO_P06_MUX_NSSO3	(0x03)


#define  GPIO_P10_MUX_SCLK	(0x03)
#define  GPIO_P11_MUX_MOSI	(0x03)
#define  GPIO_P12_MUX_MISO	(0x03)
#define  GPIO_P13_MUX_NSS	(0x03)
#define  GPIO_P14_MUX_NSS	(0x03)
#define  GPIO_P15_MUX_NSS	(0x03)
#define  GPIO_P16_MUX_NSS	(0x03)

#define  GPIO_P13_MUX_NSSO0	(0x03)
#define  GPIO_P14_MUX_NSSO1	(0x03)
#define  GPIO_P15_MUX_NSSO2	(0x03)
#define  GPIO_P16_MUX_NSSO3	(0x03)

#define  GPIO_P20_MUX_SCLK	(0x03)
#define  GPIO_P21_MUX_MOSI	(0x03)
#define  GPIO_P22_MUX_MISO	(0x03)
#define  GPIO_P23_MUX_NSS	(0x03)

#define  GPIO_P23_MUX_NSSO0	(0x03)


#define  GPIO_P50_MUX_SCLK	(0x03)
#define  GPIO_P51_MUX_MOSI	(0x03)
#define  GPIO_P52_MUX_MISO	(0x03)
#define  GPIO_P53_MUX_NSS	(0x03)
#define  GPIO_P54_MUX_NSS	(0x03)
#define  GPIO_P55_MUX_NSS	(0x03)

#define  GPIO_P53_MUX_NSSO0	(0x03)
#define  GPIO_P54_MUX_NSSO1	(0x03)
#define  GPIO_P55_MUX_NSSO2	(0x03)


/*--PWMͨ��----------------------------------------------------------*/
#define  GPIO_P00_MUX_PG0	(0x05)
#define  GPIO_P01_MUX_PG1	(0x05)
#define  GPIO_P02_MUX_PG2	(0x05)
#define  GPIO_P03_MUX_PG3	(0x05)
#define  GPIO_P04_MUX_PG4	(0x05)
#define  GPIO_P05_MUX_PG5	(0x05)

#define  GPIO_P10_MUX_PG0	(0x05)
#define  GPIO_P11_MUX_PG1	(0x05)
#define  GPIO_P12_MUX_PG2	(0x05)
#define  GPIO_P13_MUX_PG3	(0x05)
#define  GPIO_P14_MUX_PG4	(0x05)
#define  GPIO_P15_MUX_PG5	(0x05)

#define  GPIO_P20_MUX_PG0	(0x05)
#define  GPIO_P21_MUX_PG1	(0x05)
#define  GPIO_P22_MUX_PG2	(0x05)
#define  GPIO_P23_MUX_PG3	(0x05)

#define  GPIO_P50_MUX_PG0	(0x05)
#define  GPIO_P51_MUX_PG1	(0x05)
#define  GPIO_P52_MUX_PG2	(0x05)
#define  GPIO_P53_MUX_PG3	(0x05)
#define  GPIO_P54_MUX_PG4	(0x05)
#define  GPIO_P55_MUX_PG5	(0x05)

/*--Timer2����ͨ����ֻ������PS_CAPn�Ĵ�����ֵ��--------------------------------*/
#define  GPIO_P14_MUX_CAP0	(0x14)		/*PS_CAP0�Ĵ���*/
#define  GPIO_P15_MUX_CAP1	(0x15)		/*PS_CAP1�Ĵ���*/
#define  GPIO_P16_MUX_CAP2	(0x16)		/*PS_CAP2�Ĵ���*/
#define  GPIO_P17_MUX_CAP3	(0x17)		/*PS_CAP3�Ĵ���*/

/*--Timer0�ſ����루ֻ������PS_T0G�Ĵ�����ֵ��--------------------------------*/
#define  GPIO_P02_MUX_T0G	(0x02)
#define  GPIO_P12_MUX_T0G	(0x12)
#define  GPIO_P22_MUX_T0G	(0x22)

/*--Timer0�ⲿʱ�����루ֻ������PS_T0�Ĵ�����ֵ��----------------------------*/
#define  GPIO_P03_MUX_T0	(0x03)
#define  GPIO_P13_MUX_T0	(0x13)
#define  GPIO_P23_MUX_T0	(0x23)

/*--Timer1�ſ����루ֻ������PS_T1G�Ĵ�����ֵ��--------------------------------*/
#define  GPIO_P02_MUX_T1G	(0x02)
#define  GPIO_P12_MUX_T1G	(0x12)
#define  GPIO_P22_MUX_T1G	(0x22)

/*--Timer1�ⲿʱ�����루ֻ������PS_T1�Ĵ�����ֵ��----------------------------*/
#define  GPIO_P03_MUX_T1	(0x03)
#define  GPIO_P13_MUX_T1	(0x13)
#define  GPIO_P23_MUX_T1	(0x23)

/*--Timer2 �ⲿ�������루ֻ������PS_T2EX�Ĵ�����ֵ��--------------------------*/
#define  GPIO_P02_MUX_T2EX	(0x02)
#define  GPIO_P12_MUX_T2EX	(0x12)
#define  GPIO_P22_MUX_T2EX	(0x22)

/*--Timer2�ⲿ������ſ����루ֻ������PS_T2�Ĵ�����ֵ��-----------------------*/
#define  GPIO_P03_MUX_T2	(0x03)
#define  GPIO_P13_MUX_T2	(0x13)
#define  GPIO_P23_MUX_T2	(0x23)

/*--ADC Ӳ���������ţ�ֻ������PS_ADET�Ĵ�����ֵ��-----------------------------*/
#define  GPIO_P06_MUX_ADET	(0x06)

/*--�ⲿ�ж�0���ţ�ֻ������PS_INT0�Ĵ�����ֵ��-----------------------------*/
#define  GPIO_P06_MUX_INT0	(0x06)
#define  GPIO_P07_MUX_INT0	(0x07)

/*--�ⲿ�ж�1���ţ�ֻ������PS_INT1�Ĵ�����ֵ��-----------------------------*/
#define  GPIO_P07_MUX_INT1	(0x07)

/*--ANALOG����--------------------------------------------------------------*/
#define  GPIO_MUX_ANA		(0x01)			/*ģ�⹦��(GPIO���ֹ��ܹر�)*/
/*----ADC����ͨ��-----------------------------------------------------------*/
#define  GPIO_P00_MUX_AN0	(0x01)
#define  GPIO_P01_MUX_AN1	(0x01)
#define  GPIO_P02_MUX_AN2	(0x01)
#define  GPIO_P03_MUX_AN3	(0x01)
#define  GPIO_P04_MUX_AN4	(0x01)
#define  GPIO_P05_MUX_AN5	(0x01)
#define  GPIO_P06_MUX_AN6	(0x01)
#define  GPIO_P07_MUX_AN7	(0x01)

#define  GPIO_P10_MUX_AN8	(0x01)
#define  GPIO_P11_MUX_AN9	(0x01)
#define  GPIO_P12_MUX_AN10	(0x01)
#define  GPIO_P13_MUX_AN11	(0x01)
#define  GPIO_P14_MUX_AN12	(0x01)
#define  GPIO_P15_MUX_AN13	(0x01)
#define  GPIO_P16_MUX_AN14	(0x01)
#define  GPIO_P17_MUX_AN15	(0x01)

#define  GPIO_P20_MUX_AN16	(0x01)
#define  GPIO_P21_MUX_AN17	(0x01)
#define  GPIO_P22_MUX_AN18	(0x01)
#define  GPIO_P23_MUX_AN19	(0x01)

#define  GPIO_P50_MUX_AN39	(0x01)
#define  GPIO_P51_MUX_AN40	(0x01)
#define  GPIO_P52_MUX_AN41	(0x01)
#define  GPIO_P53_MUX_AN42	(0x01)
#define  GPIO_P54_MUX_AN43	(0x01)
#define  GPIO_P55_MUX_AN44	(0x01)

/********************************************************************************
 ** \brief	 GPIO_SET_MUX_MODE
 **			 ����IO�ڵĸ��ù���
 ** \param [in] PorttCFG ��IO�ڵĸ��üĴ��� P00CFG.....
 **            PinMode ��IO�ڵĸ��ù��� 
 ** \return  none
********************************************************************************/
#define  GPIO_SET_MUX_MODE(PortCFG,PinMode)		(PortCFG = PinMode)	

/********************************************************************************
 ** \brief	 GPIO_SET_PS_MODE
 **			 ���ö˿����빦�ܷ���
 ** \param [in]  Ps_mode��PS_INT0��PS_INT1..... PS_RXD1
 **				 gpio:	(1)GPIO_P00 .... GPIO_P55
 **						(2)GPIO_P02_MUX_T0G....GPIO_P23_MUX_T1
 ** \return  none
********************************************************************************/
#define  GPIO_SET_PS_MODE(Ps_mode,gpio)		(Ps_mode = gpio)	


/********************************************************************************
 ** \brief	 GPIO_ENABLE_OUTPUT
 **			 ʹ��GPIOΪ���ģʽ
 ** \param [in] PortTRIS ������Ĵ��� P0TRIS,P1TRIS,P2TRIS,P5TRIS  
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define	 GPIO_ENABLE_OUTPUT(PortTRIS, PinNum)	(PortTRIS |= (1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_INPUT
 **			 ʹ��GPIOΪ��̬����ģʽ
 ** \param [in] PortTRIS ������Ĵ��� P0TRIS,P1TRIS,P2TRIS,P5TRIS 
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_INPUT(PortTRIS, PinNum)	(PortTRIS &= ~(1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_OD
 **			 GPIO��©���ܿ���
 ** \param [in] PortOD  :��©���ܼĴ�����P0OD,P1OD,P2OD,P5OD
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_OD(PortOD, PinNum)			(PortOD |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_OD
 **			 GPIO��©���ܹر�
 ** \param [in] PortOD  :��©���ܼĴ�����P0OD,P1OD,P2OD,P5OD
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_OD(PortOD, PinNum)		(PortOD &= ~(1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_UP
 **			 GPIO�������ܿ���
 ** \param [in] PortUP  :�������ܼĴ�����P0UP,P1UP,P2UP,P5UP
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_UP(PortUP, PinNum)			(PortUP |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_UP
 **			 GPIO�������ܹر�
 ** \param [in] PortUP  :�������ܼĴ�����P0UP,P1UP,P2UP,P5UP
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_UP(PortUP, PinNum)		(PortUP &= ~(1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_RD
 **			 GPIO�������ܿ���
 ** \param [in] PortRD  :�������ܼĴ�����P0RD,P1RD,P2RD,P5RD
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_RD(PortRD, PinNum)			(PortRD |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_RD
 **			 GPIO�������ܹر�
 ** \param [in] PortRD  :�������ܼĴ�����P0RD,P1RD,P2RD,P5RD
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_RD(PortRD, PinNum)		(PortRD &= ~(1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_SR
 **			 GPIO��б�ʹ��ܿ���
 ** \param [in] PortSR  :б�ʿ��ƹ��ܼĴ�����P0SR,P1SR,P2SR,P5SR
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_SR(PortSR, PinNum)      (PortSR |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_SR
 **			 GPIO ��б�ʹ��ܹر�
 ** \param [in] PortSR  :б�ʿ��ƹ��ܼĴ�����P0SR,P1SR,P2SR,P5SR
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_SR(PortSR, PinNum)     (PortSR &= ~(1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_SET_DS
 **			 ��λ��������ѡ��Ĵ���
 ** \param [in] PortDS  :��������ѡ��Ĵ�����P0DS,P1DS,P2DS,P5DS
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define GPIO_SET_DS(PortDS, PinNum)			(PortDS |= (1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_CLR_DS
			������������ѡ��Ĵ���
 ** \param [in] PortDS  :��������ѡ��Ĵ�����P0DS,P1DS,P2DS,P5DS
 **            PinNum��GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define GPIO_CLR_DS(PortDS, PinNum)			(PortDS &= ~(1<<PinNum))

/*----------------------------------------------------------------------------
 **GPIO �����жϴ���ģʽ
/*---------------------------------------------------------------------------*/
#define  GPIO_INT_RISING	(0x01)			/*�����ش����ж�*/
#define  GPIO_INT_FALLING	(0x02)			/*�½��ش����ж�*/
#define  GPIO_INT_BOTH_EDGE	(0x03)			/*�������½��ؾ������ж�*/

/********************************************************************************
 ** \brief	 GPIO_SET_INT_MODE
 **			 ����IO�ڵ��ⲿ�жϹ���
 ** \param [in] PorttEICFG ��IO�ڵ��ⲿ�ж�ģʽ���üĴ���
 **            PinIntMode ��IO�ڵĸ��ù��� 
 ** \return  none
 ******************************************************************************/
#define  GPIO_SET_INT_MODE(PortEICFG, PinIntMode)	(PortEICFG = PinIntMode)

/********************************************************************************
 ** \brief	 GPIO_ENABLE_INT_MODE
 **			ʹ��IO�ڵ��ⲿ�жϹ���
 ** \param [in] PorttEXTIE ��IO�ڵ��ⲿ�жϼĴ���
 **            PinMSK��GPIO_PIN_0_MSK .. GPIO_PIN_7_MSK
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_INT_MODE(PortEXTIE,PinMSK)		(PortEXTIE |= PinMSK)	

/********************************************************************************
 ** \brief	 GPIO_DISABLE_INT_MODE
 **			�ر�IO�ڵ��ⲿ�жϹ���
 ** \param [in] PorttEXTIE ��IO�ڵ��ⲿ�жϼĴ���
 **            PinMSK: GPIO_PIN_0_MSK .. GPIO_PIN_7_MSK
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_INT_MODE(PortEXTIE,PinMSK)	(PortEXTIE &= ~PinMSK)	

/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

 /********************************************************************************
 ** \brief	 GPIO_EnableInt
 **			 ʹ��IO�ڵ��жϹ���
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO5
 **			    PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK			 
 ** \return  none
 ** \note   
 ******************************************************************************/
void GPIO_EnableInt(uint8_t Port, uint8_t PinMSK);
/********************************************************************************
 ** \brief	 GPIO_DisableInt
 **			 �ر�IO�ڵ��жϹ���
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO5
 **			    PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK			 
 ** \return  none
 ** \note   
 ******************************************************************************/
void GPIO_DisableInt(uint8_t Port, uint8_t PinMSK);

 /******************************************************************************
 ** \brief	 GPIO_GetIntFlag
 **			 ��ȡ�жϱ�־
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO5
 **			    PinNum:  GPIO_PIN_0~GPIO_PIN_7 		 
 ** \return  0�����жϲ���
 **			 1�����жϲ���
 ** \note  
 ******************************************************************************/
uint8_t  GPIO_GetIntFlag(uint8_t Port, uint8_t PinNum);
 /********************************************************************************
 ** \brief	 GPIO_ClearIntFlag
 **			����жϱ�־λ
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO5
 **			    PinNum:  GPIO_PIN_0~GPIO_PIN_7 		 
 ** \return  none
 ** \note  
 ******************************************************************************/
void GPIO_ClearIntFlag(uint8_t Port, uint8_t PinNum);

#endif /* __GPIO_H__ */






