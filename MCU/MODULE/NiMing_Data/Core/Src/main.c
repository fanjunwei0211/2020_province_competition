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
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "NiMing.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*-------������λ������ͨ��Э��---------*/
//���ݲ�ֺ궨��   >1�ֽ�ʱ��ַ���
#define BYTE0(dwTemp)       (*(char *)(&dwTemp))     //ȡ��int�ͱ����ĵ��ֽ�
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))     //    ȡ�洢�ڴ˱�����һ�ڴ��ֽڵ����ݣ����ֽ�
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))
uint8_t testdatatosend[50];   //�������ݻ���

void Test_Send_User(int data1, int data2, int data3)	//�����û����ݣ�������3�����ݣ��ֱ��Ӧ���̳�3������
{
	char _cnt=0;
	
	testdatatosend[_cnt++]=0xAA;//0xAAΪ֡ͷ
	testdatatosend[_cnt++]=0x05;//0x05Ϊ���ݷ���Դ��������ο�����Э�飬���ֽ��û������������
	testdatatosend[_cnt++]=0xAF;//0xAFΪ����Ŀ�ĵأ�AF��ʾ��λ����������ο�����Э��
	testdatatosend[_cnt++]=0xF1;//0xF1����ʾ��֡ΪF1�û��Զ���֡����Ӧ�߼������F1����֡
	testdatatosend[_cnt++]=0;//���ֽڱ�ʾ���ݳ��ȣ�������=0����������ٸ�ֵ�������Ͳ����˹����㳤����
 
	
	testdatatosend[_cnt++]=BYTE1(data1);//��Ҫ���͵����ݷ������ͻ�����
	testdatatosend[_cnt++]=BYTE0(data1);
	
	testdatatosend[_cnt++]=BYTE1(data2);//��Ҫ���͵����ݷ������ͻ�����
	testdatatosend[_cnt++]=BYTE0(data2);
	
	
	testdatatosend[_cnt++]=BYTE1(data3);
	testdatatosend[_cnt++]=BYTE0(data3);
	testdatatosend[_cnt++]=BYTE3(data3);
	testdatatosend[_cnt++]=BYTE2(data3);
	
 
	testdatatosend[4] = _cnt-5;//_cnt�����������ݳ��ȣ���5Ϊ��ȥ֡��ͷ5���������ֽ�
	
	char sum = 0;	//����Ϊ����sumУ���ֽڣ���0xAAҲ�������ֽڣ�һֱ��sum�ֽ�ǰһ�ֽ�
	for(char i=0;i<_cnt;i++)
		sum += testdatatosend[i];
	
	testdatatosend[_cnt++]=sum;	//��sumУ�����ݷ������һ�ֽ�
 
	HAL_UART_Transmit(&huart1,testdatatosend,_cnt,100);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	
  /* USER CODE BEGIN 1 */
	int a=0,b=0,c=0;
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		a+=1;
		b+=2;
		c+=3;
		Test_Send_User(a,b,c);
		HAL_Delay(100);
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
