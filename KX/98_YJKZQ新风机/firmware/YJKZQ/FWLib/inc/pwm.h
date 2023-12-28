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
/** \file PWM.h
**
** 
**
** History:
** 
******************************************************************************/
#ifndef __PWM_H__
#define __PWM_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f761xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **PWMͨ��Mask
/*---------------------------------------------------------------------------*/
#define PWM_CHANNEL_NUM                     (6)    /* PWM channel number */
#define PWM_CH_0_MSK                       (0x1)   /* PWM channel 0 mask */
#define PWM_CH_1_MSK                       (0x2)   /* PWM channel 1 mask */
#define PWM_CH_2_MSK                       (0x4)   /* PWM channel 2 mask */
#define PWM_CH_3_MSK                       (0x8)   /* PWM channel 3 mask */
#define PWM_CH_4_MSK                       (0x10)  /* PWM channel 4 mask */
#define PWM_CH_5_MSK                       (0x20)  /* PWM channel 5 mask */

#define PWM0								(0x00)	/* PWM channel 0 number */
#define PWM1								(0x01)	/* PWM channel 1 number */
#define PWM2								(0x02)	/* PWM channel 2 number */
#define PWM3								(0x03)	/* PWM channel 3 number */
#define PWM4								(0x04)	/* PWM channel 4 number */
#define PWM5								(0x05)	/* PWM channel 5 number */

/*----------------------------------------------------------------------------
 **PWM���η�������Ԫ(WFG)ģʽ
/*---------------------------------------------------------------------------*/
#define PWM_WFG_INDEPENDENT 		(0x00)  /*������������ģʽ*/
#define PWM_WFG_COMPLEMENTARY 		(0x10)  /*����ģʽ*/
#define PWM_WFG_SYNCHRONIZED		(0x20)  /*ͬ��ģʽ*/
/*----------------------------------------------------------------------------
 **PWM������Ƶ�Ԫ(OC)ģʽ
/*---------------------------------------------------------------------------*/
#define PWM_OC_GROUP				(0x08)  /*���ģʽ*/
#define PWM_OC_INDEPENDENT 			(0x00)  /* ͨ�����Զ�������*/

/*----------------------------------------------------------------------------
 **EPWMʱ�ӷ�Ƶϵ��
 * �ܷ�Ƶ(PWMnDIV��Ƶ) = Fpwmn-PSC��Ƶ * CLK_DIV��Ƶ
 *   Fpwmn-PSC��Ƶ = PWMnPSC/2 (PWMnPSC��Ϊ0�����)----2��Ƶ
/*---------------------------------------------------------------------------*/
#define PWM_CLK_DIV_1						(0xff)					//=Fsys��ϵͳʱ�ӣ�		
#define PWM_CLK_DIV_2						(0x04)					//= Fpwmn-PSC   (PWMnPSC/2)
#define PWM_CLK_DIV_4						(0x00)					//= Fpwmn-PSC/2 ((PWMnPSC/2)/2)
#define PWM_CLK_DIV_8						(0x01)					//= Fpwmn-PSC/4 ((PWMnPSC/2)/4)
#define PWM_CLK_DIV_16					(0x02)					//= Fpwmn-PSC/8 ((PWMnPSC/2)/8)
#define PWM_CLK_DIV_32					(0x03)					//= Fpwmn-PSC/16((PWMnPSC/2)/16)
												  
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
 ** \brief	 PWM_ConfigRunMode
 **			 ����PWM������ģʽ
 ** \param [in] PWMRunMode:   (1)PWM_WFG_INDEPENDENT
 **							   (2)PWM_WFG_COMPLEMENTARY
 **							   (3)PWM_WFG_SYNCHRONIZED
 **							   (4)PWM_OC_GROUP
 **							   (5)PWM_OC_INDEPENDENT
 ** \return  none
 ** \note    ����5����ʽ����ϳɲ�ͬ������ģʽ���ҹ���һ��8λ�Ĵ���
 ****************************************************************************/
void PWM_ConfigRunMode( uint8_t PWMRunMode);
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelClk	
 ** \param [in] ClkDiv: (1)PWM_CLK_DIV_1 
 **						(2)PWM_CLK_DIV_2
 **						(2)PWM_CLK_DIV_4
 **						(2)PWM_CLK_DIV_8
 **						(2)PWM_CLK_DIV_16
 **						(2)PWM_CLK_DIV_32
 ** \return  none	
 ** \note 
 **	(1)PWM01PSC��ͬ����PWM0��PWM1ͨ�� �����Դ˺���ͳһ����PWMxxPSC=0x01
 **	����Ҫ�����ķ�Ƶ��������ԼĴ�����ֵ
 **	(2)PWM ��Ƶ��Ϊ������PWMxPSC PWMnDIV 
 **	��һ����Ƶ(PWMxPSC)��0x00 Ԥ��Ƶֹͣ���Ҽ�����ֹͣ��ϵͳʱ�ӷ�Ƶϵ��PWMxPSC+1
 **	�ڶ�����Ƶ��PWMnDIV): 0x00 FPWMPSC/2; 0x01 FPWMPSC/4��0x02:FPWMPSC/8��0x3 FPWMPSC/16
 **	0x04 FPWMPSC ; ���� Fsys 
 ** ��Ƶ������1~4096����Fsys=8M��PWM��Ƶ�ʷ�Χ��1.95k ~ 8M	
 ****************************************************************************/
void PWM_ConfigChannelClk(uint8_t ChannelNum,uint8_t ClkDiv);
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelPeriod
 **			 ����PWMͨ����Ƶ���Լ�ռ�ձ�
 ** \param [in] ChannelNum : PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 **				Period: 16λ����ֵ
 ** \return none
 ** \note    
 ****************************************************************************/
void PWM_ConfigChannelPeriod(uint8_t ChannelNum,uint16_t Period);
 
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelDuty
 **			 ����PWMͨ��ռ�ձ�
 ** \param [in] ChannelNum  :PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 **				Duty: 16λռ�ձ�
 ** \return none
 ** \note   
 ****************************************************************************/
void PWM_ConfigChannelDuty(uint8_t ChannelNum,uint16_t Duty);

 /****************************************************************************
 ** \brief	 PWM_EnableOneShotMode
 **			 ����One-Shotģʽ
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void PWM_EnableOneShotMode(uint8_t ChannelMask);
/****************************************************************************
 ** \brief	 PWM_EnableAutoLoadMode
 **			 �����Զ�����ģʽ
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void PWM_EnableAutoLoadMode(uint8_t ChannelMask);

/*****************************************************************************
 ** \brief	 PWM_Start
 **			
 ** \param [in]  ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
 ****************************************************************************/
void PWM_Start( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_Stop
 **				
 ** \param [in] ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note    ֹͣ��������PWM��������0
*****************************************************************************/
void PWM_Stop( uint8_t ChannelMask);

/*****************************************************************************
 ** \brief	 PWM_EnableOutput
 **			 ����PWM���
 ** \param [in] ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_EnableOutput( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_DisableOutput
 **			 �ر�PWM���
 ** \param [in] ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note    
*****************************************************************************/
void PWM_DisableOutput( uint8_t ChannelMask);

/****************************************************************************
 ** \brief	 PWM_EnableDeadZone
 **			 ��������
 ** \param [in] Channel: PWM0��PWM1....PWM5		
 **			DeadTime : ����ʱ��( 0~0xFF) = DeadTime * TPWM
 ** \return  none
 ** \note  
*****************************************************************************/
void PWM_EnableDeadZone( uint8_t Channel, uint8_t DeadTime);
/*****************************************************************************
 ** \brief	 PWM_DisableDeadZone
 **			 �ر�PWM����
 ** \param [in] Channel: PWM0��PWM1....PWM5	
 ** \return  none
 ** \note  
*****************************************************************************/
void PWM_DisableDeadZone( uint8_t Channel);

/*****************************************************************************
 ** \brief	 PWM_EnableDownCmpInt
 **			 �������±Ƚ��ж�
 ** \param [in] ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_EnableDownCmpInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_DisableDownCmpInt
 **			 �ر����±Ƚ��ж�
 ** \param [in] ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_DisableDownCmpInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_GetUpCmpIntFlag
 **			 ��ȡ���±Ƚ��жϱ�־λ
 ** \param [in] ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return  0: ���жϲ���
 **          1�����жϲ���
 ** \note   
*****************************************************************************/
uint8_t PWM_GetDownCmpIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 PWM_ClearUpCmpIntFlag
 **			 ������±Ƚ��жϱ�־λ
 ** \param [in] ChannelNum :PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_ClearDownCmpIntFlag( uint8_t ChannelNum);

/*****************************************************************************
 ** \brief	 PWM_EnableZeroInt
 **			 ��������ж�
 ** \param [in]  ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_EnableZeroInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_DisableZeroInt
 **			 �ر�����ж� 
 ** \param [in]ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_DisableZeroInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_GetZeroIntFlag
 **			 ��ȡ����жϱ�־λ 
 ** \param [in] ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return   0�����жϲ���
 **           1�����жϲ���   
 ** \note   
 *****************************************************************************/
uint8_t PWM_GetZeroIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 PWM_ClearZeroIntFlag
 **			 �������жϱ�־λ
 ** \param [in] ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_ClearZeroIntFlag( uint8_t ChannelNum);

/*****************************************************************************
 ** \brief	 PWM_EnableReverseOutput
 **			 �����������
 ** \param [in] ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note 
*****************************************************************************/
void  PWM_EnableReverseOutput( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_DisableReverseOutput
 **			 �رշ������
 ** \param [in]ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void  PWM_DisableReverseOutput( uint8_t ChannelMask);

/*****************************************************************************
 ** \brief	 PWM_AllIntEnable
 **			 ʹ��PWM���ж�
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  PWM_AllIntEnable(void);
/*****************************************************************************
 ** \brief	 PWM_AllIntDisable
 **			 �ر�PWM���ж�
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  PWM_AllIntDisable(void);

/****************************************************************************
 ** \brief	 PWM_EnableSynCount	
 **			ʹ��PWMnͬ������
 ** \param [in]  none
 ** \return  none
 ** \note	
 ****************************************************************************/
void PWM_EnableSynCount(void);





#endif /* __PWM_H__ */







