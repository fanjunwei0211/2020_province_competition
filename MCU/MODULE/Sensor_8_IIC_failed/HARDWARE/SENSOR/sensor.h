#ifndef __SENSOR_H
#define __SENSOR_H

#include "main.h"
#include "gpio.h"
//IO��������
 

#define SDA_IN()  {GPIOC->MODER&=~(3<<(1*2));GPIOC->MODER|=0<<1*2;}
#define SDA_OUT() {GPIOC->MODER&=~(3<<(1*2));GPIOC->MODER|=1<<1*2;}

//IO��������	 
/* IO���� */
#define IIC_SCL(n)  (n?HAL_GPIO_WritePin(sensor_SCL_GPIO_Port,sensor_SCL_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(sensor_SCL_GPIO_Port,sensor_SCL_Pin,GPIO_PIN_RESET)) //SCL
#define IIC_SDA(n)  (n?HAL_GPIO_WritePin(sensor_SDA_GPIO_Port,sensor_SDA_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(sensor_SDA_GPIO_Port,sensor_SDA_Pin,GPIO_PIN_RESET)) //SDA
#define READ_SDA    HAL_GPIO_ReadPin(sensor_SDA_GPIO_Port,sensor_SDA_Pin)					//����SDA


//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�
uint8_t IIC_Write_Byte(uint8_t dat);			//IIC����һ���ֽ�
uint8_t IIC_Read_Byte(uint8_t ack);//IIC��ȡһ���ֽ�
uint8_t IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�

uint8_t Read_Data2(uint8_t addr);
void Set_ID(uint8_t addr, uint8_t new_addr);



#endif
