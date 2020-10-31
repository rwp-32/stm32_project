//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-10-31
//  最近修改   : 
//  功能描述   : LCD SPI接口演示例程(STM32F103系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND     电源地
//              VCC     3.3v电源
//              D0   PA0（SCL）
//              D1   PA1（SDA）
//              RES  PA2
//              DC   PA3
//              CS   PA4   
//							BLK  PA5 控制背光
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2018-10-31
//All rights reserved
//******************************************************************************/


#include  "include.h"
#include  "system.h"
typedef struct Sht30_value
{
	union16  temp;
	union16  humi;
	unsigned char  crc;
}sht30_value_ST,*p_sht_value_ST;

sht30_value_ST   gv_sht30_value;   

int main(void)
 {	
	 delay_init();	    	 //延时函数初始化	  
	 NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	 Lcd_Init();			//初始化OLED 
	 IIC_Init();	 
   uart_init(9600);
	 uart2_init(9600);
	 LCD_Clear(WHITE);
	 BACK_COLOR=WHITE;
	 LED_ON;
	 bt_protocol_init();
	 while(1)
	 {
		 	LCD_ShowChinese(45,0,5,32,RED);   //中
			LCD_ShowChinese(80,0,6,32,RED);   //景
			LCD_ShowChinese(115,0,7,32,RED);   //园
			LCD_ShowChinese(155,0,3,32,RED);  //电
		  humiture_display(75,110,16,BLACK);
	    bluetooth_to_scrawl();
   }
}