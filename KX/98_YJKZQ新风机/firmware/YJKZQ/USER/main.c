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
/** \file main.c
**
**
**
**	History:
**
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "cms80f761xx.h"
#include "delay.h"
#include "main.h"
#include "time.h"
#include "CheckTouchKey_80F761x.h"
#include "CheckTouchKey_Set.h"
#include "REL_Protocol.h"
#include "lcd.h"
#include "gpio.h"
#include "display.h"
/****************************************************************************/
/*	Local pre-processor symbols('#define')
*****************************************************************************/
// ���Ź����ʱ��Լ350ms�������жϣ��忴�Ź���ʹ�ܿ��Ź���λ�������ж�
#define clrwdt()       \
	\	
{                \
		u8 ea_tmp;     \
		ea_tmp = EA;   \
		CKCON |= 0xC0; \
		CKCON &= 0xDF; \
		EA = 0;        \
		_nop_();       \
		_nop_();       \
		TA = 0xAA;     \
		TA = 0x55;     \
		WDCON = 0x03;  \
		EA = ea_tmp;   \
	}

// ���ڲ�ʱ��
#define cmscksel()     \
	{                  \
		u8 ea_tmp;     \
		ea_tmp = EA;   \
		\	
	EA = 0;            \
		_nop_();       \
		_nop_();       \
		TA = 0xAA;     \
		TA = 0x55;     \
		SCKSEL = 0x04; \
		_nop_();       \
		_nop_();       \
		_nop_();       \
		_nop_();       \
		_nop_();       \
		_nop_();       \
		EA = ea_tmp;   \
	}
/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/
/******************************************************************************
 ** \brief	 LCD_Config
 ** \param [in]
 **
 ** \return  none
 ** \note  4λ8��7����ʱ��Һ����ʾ��  3.3V  1/3 Bias 1/4 Duty
 ******************************************************************************/
void LCD_Config(void)
{
	/*
	(1)����LEDģ������ģʽ
	*/
	LCD_ConfigRunMode(LCD_DISPLAY_NORMAL);

	LCD_ConfigDuty(LCD_DUTY_4);					  // 1/4DUTY
	LCD_ConfigVLCD(LCD_VSEL_VLCD, 5, LCD_BIAS_3); // VDD =5V, VLcv = 3.3V , 1/3bias

	LCD_ConfigClk(LCD_CLK_FSYS, LCD_CLKDIV_4096);
	LCD_ConfigResistance(LCD_FCMODE_0, LCD_R_60K, LCD_FCCTL_8);

	/*-----------------------------------------------------------------
	��ѡ��LSE��Ϊʱ��Դ��
	(1)Config�о����ѡ��OSCON/OSCOUT AS LSE
	(2)LSE_EnableLSE();  ����LSEģ��
	------------------------------------------------------------------*/

	/*
	(2)����COM��
	*/
	GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_ANA); // COM0
	GPIO_SET_MUX_MODE(P05CFG, GPIO_MUX_ANA); // COM1
	GPIO_SET_MUX_MODE(P02CFG, GPIO_MUX_ANA); // COM2
	GPIO_SET_MUX_MODE(P03CFG, GPIO_MUX_ANA); // COM3

	LCDCOMEN = (0x0f << 2); // ʹ��COM0~COM3

	/*
	(3)����SEG��
	*/

	GPIO_SET_MUX_MODE(P06CFG, GPIO_MUX_ANA); // SEG2	-> ������ SEG2
	GPIO_SET_MUX_MODE(P07CFG, GPIO_MUX_ANA); // SEG3	-> ������ SEG1
	GPIO_SET_MUX_MODE(P34CFG, GPIO_MUX_ANA); // SEG24	-> ������ SEG12
	GPIO_SET_MUX_MODE(P35CFG, GPIO_MUX_ANA); // SEG25	-> ������ SEG11
	GPIO_SET_MUX_MODE(P40CFG, GPIO_MUX_ANA); // SEG28	-> ������ SEG10
	GPIO_SET_MUX_MODE(P41CFG, GPIO_MUX_ANA); // SEG29	-> ������ SEG3

	GPIO_SET_MUX_MODE(P42CFG, GPIO_MUX_ANA); // SEG30	-> ������ SEG4
	GPIO_SET_MUX_MODE(P43CFG, GPIO_MUX_ANA); // SEG31	-> ������ SEG5
	GPIO_SET_MUX_MODE(P44CFG, GPIO_MUX_ANA); // SEG32	-> ������ SEG6
	GPIO_SET_MUX_MODE(P45CFG, GPIO_MUX_ANA); // SEG33	-> ������ SEG9
	GPIO_SET_MUX_MODE(P46CFG, GPIO_MUX_ANA); // SEG34	-> ������ SEG8
	GPIO_SET_MUX_MODE(P47CFG, GPIO_MUX_ANA); // SEG35	-> ������ SEG7

	LCDSEGEN0 = (3 << 6);
	LCDSEGEN3 = 0xF3;
	LCDSEGEN4 = 0xF;
	/*
	(6)����SEG������
	*/

	// LCDSEG2 = 0xFF;
	// LCDSEG3 = 0xFF;
	// LCDSEG24 = 0xFF;
	// LCDSEG25 = 0xFF;
	// LCDSEG28 = 0xFF;
	// LCDSEG29 = 0xFF;

	// LCDSEG30 = 0xFF;
	// LCDSEG31 = 0xFF;
	// LCDSEG32 = 0xFF;
	// LCDSEG33 = 0xFF;
	// LCDSEG34 = 0xFF;
	// LCDSEG35 = 0xFF;

		LCDSEG2 = 0x00;
	LCDSEG3 = 0x00;
	LCDSEG24 = 0x00;
	LCDSEG25 = 0x00;
	LCDSEG28 = 0x00;
	LCDSEG29 = 0x00;

	LCDSEG30 = 0x00;
	LCDSEG31 = 0x00;
	LCDSEG32 = 0x00;
	LCDSEG33 = 0x00;
	LCDSEG34 = 0x00;
	LCDSEG35 = 0x00;
	/*
	(7)����LCD
	*/
	LCD_Start();
	BG_ON;
}
/*****************************************************************************
 ** \brief	 GPIO_Init
 **
 ** \param [in]  none
 **
 ** \return 0
 *****************************************************************************/
// ������IO���򣬿������������������ʱPxxCFG�Ĵ����踳ֵ0��Ĭ���������߿�����
// IO����Ĵ���PxTRIS��ӦBITֵ��
// 0:����,�����Žϲ�
// 1:���,�����Ż�ã������ȿ��ܻή��
void GPIO_Init(void)
{
	P0 = 0x00;
	P1 = 0x00;
	P2 = 0x00;
	P3 = 0x00;
	P4 = 0x00;
	P5 = 0X00;

	P0TRIS = 0xFF; // 0:input mode	1:output mode
	P1TRIS = 0xFF;
	P2TRIS = 0xFF;
	P3TRIS = 0xFF;
	P4TRIS = 0xFF;
	P5TRIS = 0xFF;

	P0OD = 0x00; // 0:normal output	1:opendrain output
	P1OD = 0x00;
	P2OD = 0x00;
	P5OD = 0X00;

	P0UP = 0x00; // 0:disable	pull high	1:enable pull high
	P1UP = 0x00;
	P2UP = 0x00;
	P5UP = 0X00;

	P0RD = 0x00; // 0:disbale pull low	1:enable pull low
	P1RD = 0x00;
	P2RD = 0x00;
	P5RD = 0X00;

	P0SR = 0x00; // 0:Fast slope	1:Slow slope
	P1SR = 0x00;
	P2SR = 0x00;
	P5SR = 0X00;

	P00CFG = 0x00;
	P01CFG = 0x00;
	P02CFG = 0x00;
	P03CFG = 0x00;
	P04CFG = 0x00;
	P05CFG = 0x00;
	P06CFG = 0x00;
	P07CFG = 0x00;

	P10CFG = 0x00;
	P11CFG = 0x00;
	P12CFG = 0x00;
	P13CFG = 0x00;
	P14CFG = 0x00;
	P15CFG = 0x00;
	P16CFG = 0x00;
	P17CFG = 0x00;

	P20CFG = 0x00;
	P21CFG = 0x00;
	P22CFG = 0x00;
	P23CFG = 0x00;
#ifndef CMS_TOUCH_DEBUG // ������Ҫ�����óɴ��ڣ���Ҫע��
	P24CFG = 0x00;
	P25CFG = 0x00;
#endif
	P26CFG = 0x00;
	P27CFG = 0x00;

	P30CFG = 0x00;
	P31CFG = 0x00;
	P32CFG = 0x00;
	P33CFG = 0x00;
	P34CFG = 0x00;
	P35CFG = 0x00;
	P36CFG = 0x00;
	P37CFG = 0x00;

	P40CFG = 0x00;
	P41CFG = 0x00;
	P42CFG = 0x00;
	P43CFG = 0x00;
	P44CFG = 0x00;
	P45CFG = 0x00;
	P46CFG = 0x00;
	P47CFG = 0x00;

	P50CFG = 0x00;
	P51CFG = 0x00;
	P52CFG = 0x00;
	P53CFG = 0x00;
	P54CFG = 0x00;
	P55CFG = 0x00;

	P0 = 0x00;
	P1 = 0x00;
	P2 = 0x00;
	P3 = 0x00;
	P4 = 0x00;
	P5 = 0X00;
}

/*****************************************************************************
 ** \brief	 Kscan
 **
 ** \param [in]  none
 **
 ** \return 0
 *****************************************************************************/
void Kscan(void)
{
	static unsigned long int KeyOldFlag = 0;
	unsigned long int KeyOnOutput = KeyFlag;
	if (KeyOnOutput)
	{
		if (KeyOnOutput != KeyOldFlag)
		{
			KeyOldFlag = KeyOnOutput; // �м�⵽����
			if (0x1 == KeyOnOutput)
			{
			}
			else if (0x2 == KeyOnOutput)
			{
			}
			else if (0x4 == KeyOnOutput)
			{
			}
			else if (0x8 == KeyOnOutput)
			{
			}
		}
	}
	else
	{
		KeyOldFlag = 0;
	}
}
#include "userMain.h"
#include "tm1621c.h"
#include "display.h"
/*****************************************************************************
 ** \brief	 main
 **
 ** \param [in]  none
 **
 ** \return 0
 *****************************************************************************/
int main(void)
{
	//-----------------------------------
	clrwdt(); // �˺궨���忴�Ź���ؼ���ָ��ʱ�����жϣ�ʹ��ʱ��ע��
	Delay_ms(100);
	clrwdt(); // �˺궨���忴�Ź���ؼ���ָ��ʱ�����жϣ�ʹ��ʱ��ע��
	GPIO_Init();
	TMR0_Config();	   // Fosc/1��Fhsi/1,TMR0�ж�����Ϊ125us
#ifdef CMS_TOUCH_DEBUG // ���Ժ궨���Ƿ�Ϊ1
	UART0_Config();
#endif

	tm1621cInit();
	LCD_Config();
	clrwdt();
	cmscksel(); // ����ʱ��Դ����ʼ��ѡ��HSI
	EA = 1;		// �������ж�

	while (1)
	{
		if (g_mainTime >= 20) // 2.5ms
		{
			g_mainTime = 0;
			clrwdt(); // �˺궨���忴�Ź���ؼ���ָ��ʱ�����жϣ�ʹ��ʱ��ע��
			__CMS_CheckTouchKey();
			Kscan(); // ��������

#ifdef CMS_TOUCH_DEBUG // ���Ժ궨���Ƿ�Ϊ1
			REL_SenderLoop0();
#endif
		}

		userMain();
	}
}
