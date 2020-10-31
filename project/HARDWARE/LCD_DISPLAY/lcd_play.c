#include  "include.h"


//#include  "lcd_play.h"
//#include  "lcd.h"
//#include  "myiic.h"


/******************************************************************************
      函数说明：LCDz显示温湿度值
      入口数据：tem_x,tem_y   温度值起始坐标 75
								hum_x,hum_y   湿度值的起始坐标 110
                index 汉字的序号
                size  字号  大小
								u16 color 字体颜色设置
      返回值：  无
******************************************************************************/
/* void LCD_ShowChinese(u16 x,u16 y,u8 index,u8 size,u16 color)	*/


//功能 将温湿度显示在LCD
void  humiture_display(u16 tem_y,u16 hum_y,u8 size,u16 color )
{
		
    	SHT30_read_result_myiic(0x44);
		 	LCD_ShowChinese(10,tem_y,11,size,color);   //温
			LCD_ShowChinese(45,tem_y,12,size,color);   //度
	    LCD_ShowNum1(80,tem_y,humiture[0],4,color);//修改温度值
			LCD_ShowChar(150,tem_y,'C',size,color);
	
	
			LCD_ShowChinese(10,hum_y,13,size,color);   //湿
			LCD_ShowChinese(45,hum_y,12,size,color);   //度
	    LCD_ShowNum1(80,hum_y,humiture[2],4,color);//修改温度值
			LCD_ShowChar(150,hum_y,'%',size,color);
	
//			LCD_ShowChinese(10,90,14,16,RED);   //园
//			LCD_ShowChinese(45,90,15,16,RED);  //电
    



}