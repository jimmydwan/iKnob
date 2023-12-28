#ifndef __TM1621C_H
#define __TM1621C_H
#include "userMain.h"

#define DATA_IO P33
#define WR_IO P32
// #define RD_IO P05
#define CS_IO P54

#define CLS_HT_WR 

#define BIAS 0x52    // 0b1000 0101 0010  1/3duty 4com
#define SYSDIS 0X00  // 0b1000 0000 0000  ����ϵͳ������LCDƫѹ������
#define SYSEN 0X02   // 0b1000 0000 0010 ��ϵͳ ����
#define LCDOFF 0X04  // 0b1000 0000 0100  ��LCDƫѹ
#define LCDON 0X06   // 0b1000 0000 0110  ��LCDƫ ѹ
#define RC256 0X30   // 0b1000 0011 0000  �ڲ�ʱ��RC256K
#define WDTDIS 0X0A  // 0b1000 0000 1010  ��ֹ���Ź�
#define SYS_DIS 0x00 // 关闭系统�?荡器和LCD偏压发生�?
#define SYS_EN 0x02  // 打开系统�?荡器
#define LCD OFF 0x04 // 关闭LCD 偏压发生�?
#define LCD_ON 0x06  // 打开LCD 偏压发生�?
#define DRIVE_METHOD 0x52
#define _Nop() \
    _nop_();   \
    _nop_();   \
    _nop_();   \
    _nop_();   \
    _nop_();   \
    _nop_();   \
    _nop_()

void tm1621cInit();
void TM1620cWriteData(unsigned char addr, unsigned char Data);
void TM1620_WriteCommand(unsigned char cmd);
#endif