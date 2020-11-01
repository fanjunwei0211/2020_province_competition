/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h> 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "led.h"
#include "motor.h"
#include "encoder.h"
#include "pid.h"
#include "printf.h"
#include "key.h"
#include "control.h"
#include "JY901.h"

#include "DataScope_DP.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SPEED 80
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//int Sensor_Value;
int Temp_Value[2]={0};  //8路传感器返回值

int Move_Flag = 0;
int Encoder1,Encoder2,Encoder3,Encoder4;
int moto1,moto2,moto3,moto4;
int Target_L = 80,Target_R = 80;//,Target_C = 80,Target_D = 80; //满辐大概180
int Target_Speed = 50;
int Sensor[8]={0};
int Zhijiao_Flag = 0;   //设定直角程序  1->是直角程序  小灯熄灭
float Roll_Value;

/*---------------------------------陀螺仪------------------------------*/
char ACCCALSW[5] = {0XFF,0XAA,0X01,0X01,0X00};//进入加速度校准模式
char SAVACALSW[5]= {0XFF,0XAA,0X00,0X00,0X00};//保存当前配置

extern struct STime		stcTime;
extern struct SAcc 		stcAcc;
extern struct SGyro 		stcGyro;
extern struct SAngle 	stcAngle;
extern struct SMag 		stcMag;
extern struct SDStatus stcDStatus;
extern struct SPress 	stcPress;
extern struct SLonLat 	stcLonLat;
extern struct SGPSV 		stcGPSV;
extern struct SQ       stcQ;
unsigned char TxBuffer_T;
/*---------------------------------陀螺仪------------------------------*/



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*-------------------------上位机---------------------------*/

void Data_Send()
{
	int Send_Count;
	DataScope_Get_Channel_Data(Encoder1, 1 );
	DataScope_Get_Channel_Data(Encoder2, 2 );
	DataScope_Get_Channel_Data(Encoder3, 3 ); 
	DataScope_Get_Channel_Data( Encoder4 , 4 );   
	DataScope_Get_Channel_Data(0, 5 );
	DataScope_Get_Channel_Data(0 , 6 );
	DataScope_Get_Channel_Data(0, 7 );
	DataScope_Get_Channel_Data( 0, 8 ); 
	DataScope_Get_Channel_Data(0, 9 );  
	DataScope_Get_Channel_Data( 0 , 10);
	Send_Count = DataScope_Data_Generate(10);
	for(int i = 0 ; i < Send_Count; i++) 
	{
		while((USART1->SR&0X40)==0);  
		USART1->DR = DataScope_OutPut_Buffer[i]; 
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM8_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM10_Init();
  MX_TIM11_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim10);
	HAL_TIM_Base_Start_IT(&htim11);
//	Sensor_Init();
	Motor_Start();
	Encoder_start();
	HAL_UART_Receive_IT(&huart2,&TxBuffer_T,1);	
	
	while(!KeyState())
	{
		if(Encoder4 > 20)
		{
			Zhijiao_Flag ++;
			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
			if(Zhijiao_Flag > 1)
				Zhijiao_Flag = 0;
		}
	}
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	
	Move_Flag = 1;
	
  while (1)
  {
		Sensor_Get();
		HAL_Delay(2);
		if(Zhijiao_Flag == 0)
		{
			track_zhixian_PID();
		}
		else
		{
			if(Zhijiao_Detect())
			{
				Target_L = Target_R = 50;
				HAL_Delay(10);
				while(1)
				{
//					Move_Flag = 0;
					HAL_Delay(2);
					Target_L = -60;
					Target_R = 60;
					Sensor_Get();
					if(Sensor[3]==0 || Sensor[4]==0 || Sensor[5]==0 || Sensor[6]==0 || Sensor[7]==0)
						break;
				}
			}
//			track_zhixian_PID();
		}
//		if(Roll_Value < -15 || Roll_Value > 15)
//		{
////			Target_Speed = 50;
//			track_zhixian_PID();
//		}
//		else
//		{
//			Target_Speed = SPEED;
//			track_zhixian_PID();
//		}
		
		XianFu();

			
		

		
		
//		HAL_Delay(5);
		
		/*-----------------------陀螺仪测试---------------------*/
//		HAL_Delay(1000);
//		int i=0;
////		Led_Flash(5);
//		i++;
//		if(i>20)
//		{
//			i = 0;
//			printf("正在进行加速度校准\r\n");
//			sendcmd(ACCCALSW);HAL_Delay(100);//等待模块内部自动校准好，模块内部会自动计算需要一定的时间
//			sendcmd(SAVACALSW);HAL_Delay(100);//保存当前配置
//			printf("加速度校准完成\r\n");
//		}
//		//输出加速度
//		//串口接受到的数据已经拷贝到对应的结构体的变量中了，根据说明书的协议，以加速度为例 stcAcc.a[0]/32768*16就是X轴的加速度，
//		printf("Acc:%.3f %.3f %.3f\r\n",(float)stcAcc.a[0]/32768*16,(float)stcAcc.a[1]/32768*16,(float)stcAcc.a[2]/32768*16);
//			HAL_Delay(10);
//		//输出角速度
//		printf("Gyro:%.3f %.3f %.3f\r\n",(float)stcGyro.w[0]/32768*2000,(float)stcGyro.w[1]/32768*2000,(float)stcGyro.w[2]/32768*2000);
//			HAL_Delay(10);
//		//输出角度
//		printf("Angle:%.3f %.3f %.3f\r\n",(float)stcAngle.Angle[0]/32768*180,(float)stcAngle.Angle[1]/32768*180,(float)stcAngle.Angle[2]/32768*180);
//			HAL_Delay(10);
//		printf("\r\n\r\n");

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static int Tim_Delay=0;  //TIM10
	static int Tim_Delay11=0; 
	
	if(htim->Instance == TIM11)   //0.1ms
	{
		Tim_Delay11++;
		if(Tim_Delay11>=100)
		{
			Tim_Delay11=0;
			
//			Sensor_Get();
			/*------------------------------陀螺仪-------------------------------------*/
			Roll_Value = (float)stcAngle.Angle[0]/32768*180;  //陀螺仪俯仰角
			if(Roll_Value < -15 || Roll_Value > 15)
			{
//				Target_Speed = 50;
			}
			else
			{
				Target_Speed = SPEED;
			}
			
			
		}
	}
	
	if(htim->Instance == TIM10)   //0.1ms
	{
		Tim_Delay++;
		if(Tim_Delay >= 100) //100->10ms
		{
			Tim_Delay = 0;
			
			Encoder1 = Read_Encoder(3);
			Encoder2 = Read_Encoder(4);
			Encoder3 = Read_Encoder(5);
			Encoder4 = Read_Encoder(8);
			
			if(Move_Flag == 1)
			{
				moto1 = Incremental_PI_A(Encoder1,Target_L);
				moto2 = Incremental_PI_B(Encoder2,Target_L);
				moto3 = Incremental_PI_C(Encoder3,Target_R);
				moto4 = Incremental_PI_D(Encoder4,Target_R);
				Set_Pwm(moto1, moto2, moto3, moto4);
				Led_Flash(100);
			}
			else
			{
				Set_Pwm(0,0,0,0);
			}
			
		}
	} 
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	CopeSerial2Data(TxBuffer_T);//处理数据
	HAL_UART_Receive_IT(&huart2,&TxBuffer_T,1);	
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
