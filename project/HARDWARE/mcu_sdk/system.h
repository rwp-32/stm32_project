/****************************************Copyright (c)*************************
**                               版权所有 (C), 2015-2017, 涂鸦科技
**
**                                 http://www.tuya.com
**
**--------------文件信息-------------------------------------------------------
**文   件   名: system.c
**描        述: bluetooth数据处理函数
**使 用 说 明 : 用户无需关心该文件实现内容
**
**
**--------------当前版本修订---------------------------------------------------
** 版  本: v1.0
** 日　期: 2017年5月3日
** 描　述: 1:创建涂鸦bluetooth对接MCU_SDK
**
**-----------------------------------------------------------------------------
******************************************************************************/
#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#ifdef SYSTEM_GLOBAL
  #define SYSTEM_EXTERN
#else
  #define SYSTEM_EXTERN   extern
#endif

//=============================================================================
//帧的字节顺序
//=============================================================================
#define         HEAD_FIRST                      0
#define         HEAD_SECOND                     1        
#define         PROTOCOL_VERSION                2
#define         FRAME_TYPE                      3
#define         LENGTH_HIGH                     4
#define         LENGTH_LOW                      5
#define         DATA_START                      6

//=============================================================================
//数据帧类型
//=============================================================================
#define         HEAT_BEAT_CMD                   0                               //心跳包
#define         PRODUCT_INFO_CMD                1                               //产品信息
#define         WORK_MODE_CMD                   2                               //查询MCU 设定的模块工作模式	
#define         BT_STATE_CMD                    3                               //bluetooth工作状态	
#define         BT_RESET_CMD                    4                               //重置bluetooth
#define         DATA_QUERT_CMD                  6                               //命令下发
#define         STATE_UPLOAD_CMD                7                               //状态上报	 
#define         STATE_QUERY_CMD                 8                               //状态查询   
#define         UPDATE_START_CMD                0x0a                            //升级开始
#define         UPDATE_TRANS_CMD                0x0b                            //升级传输


//=============================================================================
#define         VERSION                 0x00                                            //协议版本号
#define         PROTOCOL_HEAD           0x07                                            //固定协议头长度
#define         FIRM_UPDATA_SIZE        256                                            //升级包大小
#define         FRAME_FIRST             0x55
#define         FRAME_SECOND            0xaa
//============================================================================= 
SYSTEM_EXTERN unsigned char volatile bt_queue_buf[PROTOCOL_HEAD + BT_UART_QUEUE_LMT];  //串口队列缓存
SYSTEM_EXTERN unsigned char bt_uart_rx_buf[PROTOCOL_HEAD + BT_UART_RECV_BUF_LMT];         //串口接收缓存
SYSTEM_EXTERN unsigned char bt_uart_tx_buf[PROTOCOL_HEAD + BT_UART_SEND_BUF_LMT];        //串口发送缓存
//
SYSTEM_EXTERN volatile unsigned char *queue_in;
SYSTEM_EXTERN volatile unsigned char *queue_out;

SYSTEM_EXTERN unsigned char stop_update_flag;

#ifndef BT_CONTROL_SELF_MODE
SYSTEM_EXTERN unsigned char reset_bt_flag;                                                  //重置bt标志(TRUE:成功/FALSE:失败)
SYSTEM_EXTERN unsigned char set_btmode_flag;                                                //设置bluetooth工作模式标志(TRUE:成功/FALSE:失败)
SYSTEM_EXTERN unsigned char bt_work_state;                                                  //bt模块当前工作状态
#endif


/*****************************************************************************
函数名称 : set_bt_uart_byte
功能描述 : 写bt_uart字节
输入参数 : dest:缓存区其实地址;
           byte:写入字节值
返回参数 : 写入完成后的总长度
*****************************************************************************/
unsigned short set_bt_uart_byte(unsigned short dest, unsigned char byte);

/*****************************************************************************
函数名称 : set_bt_uart_buffer
功能描述 : 写bt_uart_buffer
输入参数 : dest:目标地址
           src:源地址
           len:数据长度
返回参数 : 无
*****************************************************************************/
unsigned short set_bt_uart_buffer(unsigned short dest, unsigned char *src, unsigned short len);

/*****************************************************************************
函数名称 : bt_uart_write_frame
功能描述 : 向bt串口发送一帧数据
输入参数 : fr_type:帧类型
           len:数据长度
返回参数 : 无
*****************************************************************************/
void bt_uart_write_frame(unsigned char fr_type, unsigned short len);

/*****************************************************************************
函数名称 : get_check_sum
功能描述 : 计算校验和
输入参数 : pack:数据源指针
           pack_len:计算校验和长度
返回参数 : 校验和
*****************************************************************************/
unsigned char get_check_sum(unsigned char *pack, unsigned short pack_len);

/*****************************************************************************
函数名称 : data_handle
功能描述 : 数据帧处理
输入参数 : offset:数据起始位
返回参数 : 无
*****************************************************************************/
void data_handle(unsigned short offset);

/*****************************************************************************
函数名称 : get_queue_total_data
功能描述 : 读取队列内数据
输入参数 : 无
返回参数 : 无
*****************************************************************************/
unsigned char get_queue_total_data(void);

/*****************************************************************************
函数名称 : Queue_Read_Byte
功能描述 : 读取队列1字节数据
输入参数 : 无
返回参数 : 无
*****************************************************************************/
unsigned char Queue_Read_Byte(void);
//static void get_mcu_bt_mode(void);
//static void product_info_update(void);

#endif
  
  