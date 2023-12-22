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
/** \file pwm.c
**
** 
**
**	History:
**	
*****************************************************************************/

/****************************************************************************/
/*	include files
*****************************************************************************/
#include "pwm.h"
/****************************************************************************/
/*	Local pre-processor symbols/macros ('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions (declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions ('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions ('static')
*****************************************************************************/

/****************************************************************************/
/*	Local function prototypes ('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/
/********************************************************************************
 ** \brief	 PWM_ConfigRunMode
 **			 ����PWM������ģʽ
 ** \param [in] PWMRunMode:   (1)PWM_WFG_INDEPENDENT
 **							   (2)PWM_WFG_COMPLEMENTARY
 **							   (3)PWM_WFG_SYNCHRONIZED
 **							   (4)PWM_OC_GROUP
 **							   (5)PWM_OC_INDEPENDENT
 ** \return  none
 ** \note    ����5����ʽ����ϳɲ�ͬ������ģʽ���ҹ���һ��8λ�Ĵ���
 ******************************************************************************/
void PWM_ConfigRunMode( uint8_t PWMRunModeMask)
{
	PWMCON = PWMRunModeMask; 			/*ע��ֱ�Ӹ�ֵ*/
}
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelClk	
** \param [in] ChannelNum : PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 **				ClkDiv: (1)PWM_CLK_DIV_1 
 **						(2)PWM_CLK_DIV_2
 **						(3)PWM_CLK_DIV_4
 **						(4)PWM_CLK_DIV_8
 **						(5)PWM_CLK_DIV_16
 **						(6)PWM_CLK_DIV_32
 ** \return  none	
 ** \note 
 **	(1)����ΪPWM01PSC��ͬ����PWM0��PWM1ͨ�� �����Դ˺���ͳһ����PWMPSC=0x01
 **	����Ҫ�����ķ�Ƶ��������ԼĴ�����ֵ
 **	(2)PWM ��Ƶ��Ϊ������PWMxPSC PWMnDIV 
 **	��һ����Ƶ(PWMxPSC)��0x00 Ԥ��Ƶֹͣ���Ҽ�����ֹͣ��ϵͳʱ�ӷ�Ƶϵ��PWMxPSC+1
 **	�ڶ�����Ƶ��PWMnDIV): 0x00 FPWMPSC/2; 0x01 FPWMPSC/4��0x02:FPWMPSC/8��0x3 FPWMPSC/16
 **	0x04 FPWMPSC ; ���� Fsys 
 ** ��Ƶ������1~4096����Fsys=8M��PWM��Ƶ�ʷ�Χ��1.95k ~ 8M	
*****************************************************************************/
void PWM_ConfigChannelClk(uint8_t ChannelNum,uint8_t ClkDiv)
{
	switch(ChannelNum)
	{
		case PWM0:
			 PWM01PSC = 0x01;
			 PWM0DIV = ClkDiv;
			break;
		case PWM1:
			PWM01PSC = 0x01;
			PWM1DIV = ClkDiv;
			break;
		case PWM2:
			 PWM23PSC = 0x01;
			 PWM2DIV = ClkDiv;
			 break;
		case PWM3:
			 PWM23PSC = 0x01;
			 PWM3DIV = ClkDiv;
			 break;	
		case PWM4:
			 PWM45PSC = 0x01;
			 PWM4DIV = ClkDiv;
			 break;				
		case PWM5:
			 PWM45PSC = 0x01;
			 PWM5DIV = ClkDiv;
			 break;		
		default:
			break;
	}
}
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelPeriod
 **			 ����PWMͨ����Ƶ���Լ�ռ�ձ�
 ** \param [in] ChannelNum : PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 **				Period: 16λ����ֵ
 ** \return none
 ** \note    
 ****************************************************************************/
void PWM_ConfigChannelPeriod(uint8_t ChannelNum,uint16_t Period)
{	
	switch(ChannelNum)
	{
		case PWM0:
			PWMP0H = Period>>8;
			PWMP0L = Period;
			PWMLOADEN |= PWM_CH_0_MSK;
			break;
		case PWM1:
			PWMP1H = Period>>8;
			PWMP1L = Period;
			PWMLOADEN |= PWM_CH_1_MSK;
			break;
		case PWM2:
			PWMP2H = Period>>8;
			PWMP2L = Period;
			PWMLOADEN |= PWM_CH_2_MSK;
			break;
		case PWM3:
			PWMP3H = Period>>8;
			PWMP3L = Period;
			PWMLOADEN |= PWM_CH_3_MSK;
			break;	
		case PWM4:
			PWMP4H = Period>>8;
			PWMP4L = Period;
			PWMLOADEN |= PWM_CH_4_MSK;
			break;				
		case PWM5:
			PWMP5H = Period>>8;
			PWMP5L = Period;
			PWMLOADEN |= PWM_CH_5_MSK;
			break;		
		default:
			break;
	}	
}
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelDuty
 **			 ����PWMͨ��ռ�ձ�
 ** \param [in] ChannelNum  :PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 **				Duty: 16λռ�ձ�
 ** \return none
 ** \note   
 ****************************************************************************/
void PWM_ConfigChannelDuty(uint8_t ChannelNum,uint16_t Duty)
{
	switch(ChannelNum)
	{
		case PWM0:
			PWMD0H = Duty>>8;
			PWMD0L = Duty;
			PWMLOADEN |= PWM_CH_0_MSK;
			break;
		case PWM1:
			PWMD1H = Duty>>8;
			PWMD1L = Duty;
			PWMLOADEN |= PWM_CH_1_MSK;
			break;
		case PWM2:
			PWMD2H = Duty>>8;
			PWMD2L = Duty;
			PWMLOADEN |= PWM_CH_2_MSK;
			break;
		case PWM3:
			PWMD3H = Duty>>8;
			PWMD3L = Duty;
			PWMLOADEN |= PWM_CH_3_MSK;
			break;	
		case PWM4:
			PWMD4H = Duty>>8;
			PWMD4L = Duty;
			PWMLOADEN |= PWM_CH_4_MSK;
			break;				
		case PWM5:
			PWMD5H = Duty>>8;
			PWMD5L = Duty;
			PWMLOADEN |= PWM_CH_5_MSK;
			break;		
		default:
			break;
	}		
}
 
/****************************************************************************
 ** \brief	 PWM_EnableOneShotMode
 **			 ����One-Shotģʽ
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void PWM_EnableOneShotMode(uint8_t ChannelMask)
{			
	PWMCNTM &= ~ChannelMask;	
}
/****************************************************************************
 ** \brief	 PWM_EnableAutoLoadMode
 **			 �����Զ�����ģʽ
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void PWM_EnableAutoLoadMode(uint8_t ChannelMask)
{			
	PWMCNTM |= ChannelMask;	
}

/****************************************************************************
 ** \brief	 PWM_EnableSynCount	
 **			ʹ��PWMnͬ������
 ** \param [in]  none
 ** \return  none
 ** \note	
 ****************************************************************************/
void PWM_EnableSynCount( void)
{			
	PWMCON |= PWM_PWMCON_PWMRUN_Msk;	
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	PWMCON &= ~(PWM_PWMCON_PWMRUN_Msk);	
}

/****************************************************************************
 ** \brief	 PWM_Start		
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
 ****************************************************************************/
void PWM_Start( uint8_t ChannelMask)
{			
	PWMCNTE |= ChannelMask;		/*ʹ��PWMn������*/
}
/*****************************************************************************
 ** \brief	 PWM_Stop
 **
 ** \param [in] ChannelMask  : PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note    
*****************************************************************************/
void PWM_Stop( uint8_t ChannelMask)
{
	PWMCNTE &= ~ ChannelMask;		/*ֹͣ����*/
}

/*****************************************************************************
 ** \brief	 PWM_EnableOutput
 **			 ����PWM���
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK   
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_EnableOutput( uint8_t ChannelMask)
{
	PWMOE |= ChannelMask;		/*ʹ��PWM���*/	
}
/*****************************************************************************
 ** \brief	 PWM_DisableOutput
 **			 �ر�PWM���
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note    
*****************************************************************************/
void PWM_DisableOutput( uint8_t ChannelMask)
{
	PWMOE &= ~(ChannelMask);		
}

/****************************************************************************
 ** \brief	 PWM_EnableDeadZone
 **			 ��������
 ** \param [in] Channel: PWM0��PWM1....PWM5		
 **			DeadTime : ����ʱ��( 0~0xFF) = DeadTime * TPWM
 ** \return  none
 ** \note  
*****************************************************************************/
void PWM_EnableDeadZone( uint8_t Channel, uint8_t DeadTime)
{
	switch(Channel)
	{
		case PWM0:
		case PWM1:
			PWMDTE  |= PWM_PWMDTE_PWM01DTE_Msk;
			PWM01DT = DeadTime;
			break;
		case PWM2:
		case PWM3:
			PWMDTE  |= PWM_PWMDTE_PWM23DTE_Msk;
			PWM23DT = DeadTime;
			break;
		case PWM4:
		case PWM5:
			PWMDTE  |= PWM_PWMDTE_PWM45DTE_Msk;
			PWM45DT = DeadTime;
			break;
		default:
			break;		
	}	
}
/*****************************************************************************
 ** \brief	 PWM_DisableDeadZone
 **			 �ر�PWM����
 ** \param [in] Channel: PWM0��PWM1....PWM5	
 ** \return  none
 ** \note  
*****************************************************************************/
void PWM_DisableDeadZone( uint8_t Channel)
{
	switch(Channel)
	{
		case PWM0:
		case PWM1:
			PWMDTE  &= ~(PWM_PWMDTE_PWM01DTE_Msk);
			break;
		case PWM2:
		case PWM3:
			PWMDTE  &= ~(PWM_PWMDTE_PWM23DTE_Msk);
			break;
		case PWM4:
		case PWM5:
			PWMDTE  &= ~(PWM_PWMDTE_PWM45DTE_Msk);
			break;
		default:
			break;		
	}	
}

/*****************************************************************************
 ** \brief	 PWM_EnableDownCmpInt
 **			 �������±Ƚ��ж�
 ** \param [in]ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_EnableDownCmpInt( uint8_t ChannelMask)
{
	PWMDIE  |= ChannelMask;
}
/*****************************************************************************
 ** \brief	 PWM_DisableDownCmpInt
 **			 �ر����±Ƚ��ж�
 ** \param [in]  ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_DisableDownCmpInt( uint8_t ChannelMask)
{
	PWMDIE  &= ~ChannelMask;	
}
/*****************************************************************************
 ** \brief	 PWM_GetUpCmpIntFlag
 **			 ��ȡ���±Ƚ��жϱ�־λ
 ** \param [in] ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return  0: ���жϲ���
 **          1�����жϲ���
 ** \note   
*****************************************************************************/
uint8_t PWM_GetDownCmpIntFlag( uint8_t ChannelNum)
{
	return(PWMDIF & (1<<ChannelNum)? 1:0);
}
/*****************************************************************************
 ** \brief	 PWM_ClearUpCmpIntFlag
 **			 ������±Ƚ��жϱ�־λ
 ** \param [in]  ChannelNum :PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_ClearDownCmpIntFlag( uint8_t ChannelNum)
{
	PWMDIF = 0xff & (~(1<<ChannelNum));
}

/*****************************************************************************
 ** \brief	 PWM_EnableZeroInt
 **			 ��������ж�
 ** \param [in] ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_EnableZeroInt( uint8_t ChannelMask)
{
	PWMZIE |= ChannelMask;
}
/*****************************************************************************
 ** \brief	 PWM_DisableZeroInt
 **			 �ر�����ж� 
 ** \param [in]ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_DisableZeroInt( uint8_t ChannelMask)
{
	PWMZIE &= ~ChannelMask;
}
/*****************************************************************************
 ** \brief	 PWM_ClearZeroIntFlag
 **			 �������жϱ�־λ
 ** \param [in]  ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_ClearZeroIntFlag( uint8_t ChannelNum)
{
	PWMZIF = 0xff & (~(1<<ChannelNum));
}
/*****************************************************************************
 ** \brief	 PWM_GetZeroIntFlag
 **			 ��ȡ����жϱ�־λ 
 ** \param [in] ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return   0�����жϲ���
 **           1�����жϲ���   
 ** \note   
 *****************************************************************************/
uint8_t PWM_GetZeroIntFlag( uint8_t ChannelNum)
{
	return(PWMZIF & (1<<ChannelNum)? 1:0);
}

/*****************************************************************************
 ** \brief	 PWM_EnableReverseOutput
 **			 �����������
 ** \param [in] ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note  
*****************************************************************************/
void  PWM_EnableReverseOutput( uint8_t ChannelMask)
{
	PWMPINV |=ChannelMask;
}
/*****************************************************************************
 ** \brief	 PWM_DisableReverseOutput
 **			 �رշ������
 ** \param [in] ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void  PWM_DisableReverseOutput( uint8_t ChannelMask)
{
	PWMPINV &=~ChannelMask;
}
/*****************************************************************************
 ** \brief	 PWM_AllIntEnable
 **			 ʹ��PWM���ж�
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  PWM_AllIntEnable(void)
{
	EIE2 |= IRQ_EIE2_PWMIE_Msk;
}
/*****************************************************************************
 ** \brief	 PWM_AllIntDisable
 **			 �ر�PWM���ж�
 ** \param [in] none
 ** \return  none
 ** \note   
 ****************************************************************************/
void  PWM_AllIntDisable(void)
{
	EIE2 &= ~(IRQ_EIE2_PWMIE_Msk);
}
