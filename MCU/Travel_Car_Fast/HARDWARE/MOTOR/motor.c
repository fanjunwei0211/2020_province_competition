#include "main.h"
#include "gpio.h"

extern TIM_HandleTypeDef htim2;

int myabs(int num)
{
	return (num>0?num:-num);
}

void Motor_Start(void)
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}


void Set_Pwm(int moto1, int moto2, int moto3, int moto4)
{
	if(moto1 < 0)
	{
		HAL_GPIO_WritePin(AIN3_GPIO_Port,AIN3_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(AIN4_GPIO_Port,AIN4_Pin,GPIO_PIN_RESET);
	}
	else 
	{
		HAL_GPIO_WritePin(AIN3_GPIO_Port,AIN3_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AIN4_GPIO_Port,AIN4_Pin,GPIO_PIN_SET);
	}
	TIM2->CCR1 = myabs(moto1);
	
	
	if(moto2 > 0)
	{
		HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_RESET);
	}
	else 
	{
		HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_SET);
	}
	TIM2->CCR2 = myabs(moto2);
	
	if(moto3 > 0)
	{
		HAL_GPIO_WritePin(BIN3_GPIO_Port,BIN3_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(BIN4_GPIO_Port,BIN4_Pin,GPIO_PIN_RESET);
	}
	else 
	{
		HAL_GPIO_WritePin(BIN3_GPIO_Port,BIN3_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BIN4_GPIO_Port,BIN4_Pin,GPIO_PIN_SET);
	}
	TIM2->CCR4 = myabs(moto3);
	
	if(moto4 > 0)
	{
		HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,GPIO_PIN_RESET);
	}
	else 
	{
		HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,GPIO_PIN_SET);
	}
	TIM2->CCR3 = myabs(moto4);
}

void Set_Pwm1(int moto)
{
	if(moto < 0)
	{
		HAL_GPIO_WritePin(AIN3_GPIO_Port,AIN3_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(AIN4_GPIO_Port,AIN4_Pin,GPIO_PIN_RESET);
	}
	else 
	{
		HAL_GPIO_WritePin(AIN3_GPIO_Port,AIN3_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AIN4_GPIO_Port,AIN4_Pin,GPIO_PIN_SET);
	}
	TIM2->CCR1 = myabs(moto);
	
}