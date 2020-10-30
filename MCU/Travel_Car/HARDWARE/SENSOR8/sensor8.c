#include "main.h"
#include "usart.h"

extern UART_HandleTypeDef huart3;

uint8_t USART_RX_STA[3] = { 0 };       //接收状态标记	  
int Num;


/*********************************************************************
 *  函数名称：Read_Data(int *Data)
 *  函数功能：读取串口数据并赋给数据缓存区
 *  形    参：*Data，指针
 *  输    出：无
 *  备    注：
 *			   	   
 ********************************************************************/    
int Read_Data1()	       
{	
	int Receive_data = 0;       //数据缓存区
	uint8_t Temp=0x57;
	HAL_UART_Transmit(&huart3, &Temp, 1, 1000);
	
	while(1)
  {
		if(USART_RX_STA[0] != 0x75) { Num = 0; }  //判断帧头0x75,否者重新接收
		if(Num == 3)
		{
			Num = 0;
			if(USART_RX_STA[2] == 0x02)  //判断帧尾0x02,否者不赋值
			{
				Receive_data = USART_RX_STA[1];				       				
			}        
			break;
		}
		HAL_UART_Transmit(&huart3, &Temp, 1, 1000);
	}
	return  Receive_data;
/*--------------------------数字量数值----------------------------*/	
}


void Read_Data(uint16_t *Data)	       
{	
	uint8_t y=0;
//	uint16_t Receive_data = 0;       //数据缓存区
	uint8_t Temp=0x57;
	HAL_UART_Transmit(&huart3, &Temp, 1, 1000);
	
/*---------------------------数字量数值----------------------------*/	
	
	if(Num != 1)
	{
		
		HAL_Delay(1);
		if(y>5)
		{
			y=0;
			return ;
		}
		y++;
	}
	*Data = USART_RX_STA[0];
	
/////////////////////////数字量数值///////////////////////////////	

///////////////////////////偏移量数值///////////////////////////////	
	
//	while(Num != 3)
//	{
//		
//		Delay_ms(1);
//		if(y>10)
//		{
//			y=0;
//			break;
//		}
//		y++;
//	}
//	Receive_data = USART_RX_STA[1];
//	Receive_data <<= 8;
//	Receive_data |= USART_RX_STA[2];

//	*Data = USART_RX_STA[0];
//	*(Data+1) = Receive_data;
	
///////////////////////////偏移量数值///////////////////////////////	

	Num = 0; 
}


/*********************************************************************
 *  函数名称：Set_Data
 *  函数功能：设置功能参数
 *  形    参：add:寄存器地址,Par: 参数,
 *  输    出：无
 *  备    注：无
 ********************************************************************/
void Set_Data(int add,int Par)	       
{	
///////////////////////////设置功能参数///////////////////////////////	
//  while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//检测UART发送结束
	uint8_t Temp_Uart=0x4C;
	HAL_UART_Transmit(&huart3, &Temp_Uart,1,1000);
	while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//检测UART发送结束
	HAL_UART_Transmit(&huart3, (uint8_t *)&add,1,1000);
	while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//检测UART发送结束
	HAL_UART_Transmit(&huart3, (uint8_t *)&Par,1,1000);
	while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//检测UART发送结束

///////////////////////////设置功能参数///////////////////////////////		
}

void Sensor_Init(void)
{
	uint8_t Temp=0x57;
	HAL_UART_Transmit(&huart3, &Temp, 1, 1000);
	HAL_UART_Receive_IT(&huart3,&USART_RX_STA[Num++],1);			//使能串口3，一般每次都调用就能实现实时接收蓝牙传输的信息
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(&huart3,&USART_RX_STA[Num++],1);
}
