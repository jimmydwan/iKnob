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
/** \file wwdt.c
**
**	History:
**
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "wwdt.h"

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
** \brief	 WWDT_ConfigRunMode
**			 ����WWDT������ģʽ
** \param [in] mode: (1)WWDT_CLEAN_ALLTIME_MODE
**					 (2)WWDT_CLEAN_WINDOW_MODE
** \return none 
** \note
*****************************************************************************/
void WWDT_ConfigRunMode(uint8_t mode)
{	
	if( WWDT_CLEAN_ALLTIME_MODE == mode)
	{
		if (EA == 1) //����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
		{
			EA = 0;		 //��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
			_nop_();	
			TA = 0xAA;
			TA = 0x55;
			WWDTCON2 &= ~(WWDT_WWDTCON2_MODE_Msk);
			EA = 1;
		}
		else
		{
			TA = 0xAA;
			TA = 0x55;
			WWDTCON2 &= ~(WWDT_WWDTCON2_MODE_Msk);	
		}
	}
	if( WWDT_CLEAN_WINDOW_MODE == mode)
	{
		if (EA == 1) //����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
		{
			EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
			_nop_();
			TA = 0xAA;
			TA = 0x55;
			WWDTCON2 |= (WWDT_WWDTCON2_MODE_Msk);
			EA = 1;
		}
		else
		{
			TA = 0xAA;
			TA = 0x55;
			WWDTCON2 |= (WWDT_WWDTCON2_MODE_Msk);	
		}	
	}
}
/*****************************************************************************
** \brief	WWDT_ConfigOverflowTime
**			 ����WWDT�����ʱ��
** \param [in] time: WWDT_CLK_DIV_256 ~ WWDT_CLK_DIV_4194304
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_ConfigOverflowTime(uint8_t time)
{
	uint8_t temp;
	temp = WWDTCON;
	temp &= ~(WWDT_WWDTCON_WWDTPSC_Msk);
	temp |= (time<<WWDT_WWDTCON_WWDTPSC_Pos);	
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON = temp;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON = temp;
	}
}
 
/*****************************************************************************
** \brief	WWDT_ConfigCompareValue
**			 ����WWDT�ıȽ�ֵ
** \param [in] value: 0~0x1F
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_ConfigCompareValue(uint8_t value)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		CMPDAT = value;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		CMPDAT = value;
	}
}
  
/*****************************************************************************
** \brief	WWDT_ClearWWDT
**			��WWDT
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_ClearWWDT(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON |= WWDT_WWDTCON_WWDTCLR_Msk;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON |= WWDT_WWDTCON_WWDTCLR_Msk;
	}
}
 
/*****************************************************************************
** \brief	WWDT_EnableWWDTWakeUp
**			ʹ��WWDT���߻���System
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_EnableWWDTWakeUp(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 |= WWDT_WWDTCON2_WWDTSLE_Msk;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 |= WWDT_WWDTCON2_WWDTSLE_Msk;
	}
}
/*****************************************************************************
** \brief	WWDT_DisableWWDTWakeUp
**			�ر�WWDT���߻���System
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_DisableWWDTWakeUp(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_WWDTSLE_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_WWDTSLE_Msk);
	}	
}
 
/*****************************************************************************
 ** \brief	 WWDT_EnableCompareInt
 **			 ʹ��WWDT�����Ƚ��ж�
 ** \param [in] none
 **
 ** \return none 
 ** \note
 *****************************************************************************/
 void WWDT_EnableCompareInt(void)
 {
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 |= WWDT_WWDTCON2_WWDTIE_Msk;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 |= WWDT_WWDTCON2_WWDTIE_Msk;
	}	
 }
/*****************************************************************************
 ** \brief	 WWDT_DisableCompareInt
 **			 �ر�WWDT�����Ƚ��ж�
 ** \param [in] none
 **
 ** \return none 
 ** \note
 *****************************************************************************/
 void WWDT_DisableCompareInt(void)
 {
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_WWDTIE_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_WWDTIE_Msk);
	}		
 }
/*****************************************************************************
 ** \brief	 WWDT_GetCompareIntFlag
 **			 ��ȡWWDT�����Ƚ��жϱ�־
 ** \param [in] none
 **
 ** \return 0�����жϣ�1�����ж�
 ** \note
 *****************************************************************************/
uint8_t WWDT_GetCompareIntFlag(void)
{
	return((WWDTCON2 & WWDT_WWDTCON2_WWDTIF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 WWDT_ClearCompareIntFlag
 **			 ���WWDT�����Ƚ��жϱ�־
 ** \param [in] none
 **
 ** \return 0�����жϣ�1�����ж�
 ** \note
 *****************************************************************************/
void WWDT_ClearCompareIntFlag(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_WWDTIF_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_WWDTIF_Msk);
	}
}

/*****************************************************************************
** \brief	WWDT_EnableWWDTReset
**			ʹ��WWDT��λSystem
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_EnableWWDTReset(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON |= WWDT_WWDTCON_WWDTRE_Msk;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON |= WWDT_WWDTCON_WWDTRE_Msk;
	}
}
/*****************************************************************************
** \brief	WWDT_DisableWWDTReset
**			�ر�WWDT��λSystem
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_DisableWWDTReset(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_FORCE_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_FORCE_Msk);
	}
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON  &= ~(WWDT_WWDTCON_WWDTRE_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON  &= ~(WWDT_WWDTCON_WWDTRE_Msk);
	}		
}

/*****************************************************************************
** \brief	WWDT_Start
**			ʹ��WWDT
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_Start(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON |= WWDT_WWDTCON_WWDTEN_Msk;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON |= WWDT_WWDTCON_WWDTEN_Msk;
	}
}
/*****************************************************************************
** \brief	WWDT_Stop
**			�ر�WWDT
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_Stop(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_FORCE_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 &= ~(WWDT_WWDTCON2_FORCE_Msk);
	}
	
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON &= ~(WWDT_WWDTCON_WWDTEN_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON &= ~(WWDT_WWDTCON_WWDTEN_Msk);
	}
}

/*****************************************************************************
** \brief	WWDT_ForceRun
**			ǿ��WWDT���в�������λϵͳģʽ
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_ForceRun(void)
{
	if (EA == 1)//����TAʱ��ʱ��������ϣ������Ҫ�ر��ж�
	{
		EA = 0;		//��CPU_WAITCLOCKѡ��1T��ģʽʱ����EA=0������nop,ѡ���Tʱ���ӡ�
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 |= WWDT_WWDTCON_WWDTPSC_Msk;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WWDTCON2 |= WWDT_WWDTCON_WWDTPSC_Msk;
	}	
}
 




