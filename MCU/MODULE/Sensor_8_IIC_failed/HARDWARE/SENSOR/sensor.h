#ifndef __SENSOR_H
#define __SENSOR_H

#include "main.h"
#include "gpio.h"
//IO方向设置
 

#define SDA_IN()  {GPIOC->MODER&=~(3<<(1*2));GPIOC->MODER|=0<<1*2;}
#define SDA_OUT() {GPIOC->MODER&=~(3<<(1*2));GPIOC->MODER|=1<<1*2;}

//IO操作函数	 
/* IO操作 */
#define IIC_SCL(n)  (n?HAL_GPIO_WritePin(sensor_SCL_GPIO_Port,sensor_SCL_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(sensor_SCL_GPIO_Port,sensor_SCL_Pin,GPIO_PIN_RESET)) //SCL
#define IIC_SDA(n)  (n?HAL_GPIO_WritePin(sensor_SDA_GPIO_Port,sensor_SDA_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(sensor_SDA_GPIO_Port,sensor_SDA_Pin,GPIO_PIN_RESET)) //SDA
#define READ_SDA    HAL_GPIO_ReadPin(sensor_SDA_GPIO_Port,sensor_SDA_Pin)					//输入SDA


//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号
uint8_t IIC_Write_Byte(uint8_t dat);			//IIC发送一个字节
uint8_t IIC_Read_Byte(uint8_t ack);//IIC读取一个字节
uint8_t IIC_Wait_Ack(void); 				//IIC等待ACK信号

uint8_t Read_Data2(uint8_t addr);
void Set_ID(uint8_t addr, uint8_t new_addr);



#endif
