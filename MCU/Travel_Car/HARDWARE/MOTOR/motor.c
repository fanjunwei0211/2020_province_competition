#include "main.h"
#include "gpio.h"

extern TIM_HandleTypeDef htim2;

void Motor_Start(void)
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}


void Set_Pwm(int moto1, int moto2, int moto3, int moto4)
{
	TIM2->CCR1 = moto1;
	TIM2->CCR2 = moto2;
	TIM2->CCR3 = moto3;
	TIM2->CCR4 = moto4;
}