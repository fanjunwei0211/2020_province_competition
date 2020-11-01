#include "encoder.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim8;
void Encoder_start(void)
{
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim8,TIM_CHANNEL_ALL);
}
	
int Read_Encoder(uint8_t TIMX)//读取计数器的值
{
  int Encoder_TIM;
	switch(TIMX)
	{
	  //case 2:Encoder_TIM=(short)TIM2->CNT; TIM2 -> CNT=0;  break;
		case 3:Encoder_TIM=-(short)TIM3->CNT; TIM3 -> CNT=0;  break;
		case 4:Encoder_TIM=-(short)TIM4->CNT; TIM4 -> CNT=0;  break;
		case 5:Encoder_TIM=(short)TIM5->CNT; TIM5 -> CNT=0;  break;
		case 8:Encoder_TIM=-(short)TIM8->CNT; TIM8 -> CNT=0;  break;
		default: Encoder_TIM=0;
	}
  return Encoder_TIM;
}
