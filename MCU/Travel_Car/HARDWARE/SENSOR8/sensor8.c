#include "main.h"
#include "usart.h"

extern UART_HandleTypeDef huart3;

uint8_t USART_RX_STA[3] = { 0 };       //����״̬���	  
int Num;


/*********************************************************************
 *  �������ƣ�Read_Data(int *Data)
 *  �������ܣ���ȡ�������ݲ��������ݻ�����
 *  ��    �Σ�*Data��ָ��
 *  ��    ������
 *  ��    ע��
 *			   	   
 ********************************************************************/    
int Read_Data1()	       
{	
	int Receive_data = 0;       //���ݻ�����
	uint8_t Temp=0x57;
	HAL_UART_Transmit(&huart3, &Temp, 1, 1000);
	
	while(1)
  {
		if(USART_RX_STA[0] != 0x75) { Num = 0; }  //�ж�֡ͷ0x75,�������½���
		if(Num == 3)
		{
			Num = 0;
			if(USART_RX_STA[2] == 0x02)  //�ж�֡β0x02,���߲���ֵ
			{
				Receive_data = USART_RX_STA[1];				       				
			}        
			break;
		}
		HAL_UART_Transmit(&huart3, &Temp, 1, 1000);
	}
	return  Receive_data;
/*--------------------------��������ֵ----------------------------*/	
}


void Read_Data(uint16_t *Data)	       
{	
	uint8_t y=0;
//	uint16_t Receive_data = 0;       //���ݻ�����
	uint8_t Temp=0x57;
	HAL_UART_Transmit(&huart3, &Temp, 1, 1000);
	
/*---------------------------��������ֵ----------------------------*/	
	
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
	
/////////////////////////��������ֵ///////////////////////////////	

///////////////////////////ƫ������ֵ///////////////////////////////	
	
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
	
///////////////////////////ƫ������ֵ///////////////////////////////	

	Num = 0; 
}


/*********************************************************************
 *  �������ƣ�Set_Data
 *  �������ܣ����ù��ܲ���
 *  ��    �Σ�add:�Ĵ�����ַ,Par: ����,
 *  ��    ������
 *  ��    ע����
 ********************************************************************/
void Set_Data(int add,int Par)	       
{	
///////////////////////////���ù��ܲ���///////////////////////////////	
//  while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//���UART���ͽ���
	uint8_t Temp_Uart=0x4C;
	HAL_UART_Transmit(&huart3, &Temp_Uart,1,1000);
	while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//���UART���ͽ���
	HAL_UART_Transmit(&huart3, (uint8_t *)&add,1,1000);
	while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//���UART���ͽ���
	HAL_UART_Transmit(&huart3, (uint8_t *)&Par,1,1000);
	while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//���UART���ͽ���

///////////////////////////���ù��ܲ���///////////////////////////////		
}

void Sensor_Init(void)
{
	uint8_t Temp=0x57;
	HAL_UART_Transmit(&huart3, &Temp, 1, 1000);
	HAL_UART_Receive_IT(&huart3,&USART_RX_STA[Num++],1);			//ʹ�ܴ���3��һ��ÿ�ζ����þ���ʵ��ʵʱ���������������Ϣ
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(&huart3,&USART_RX_STA[Num++],1);
}
