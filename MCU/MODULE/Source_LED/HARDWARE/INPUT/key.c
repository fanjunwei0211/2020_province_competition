#include "key.h"

int KeyState(void)
{
	if(HAL_GPIO_ReadPin(INPUT1_GPIO_Port,INPUT1_Pin) == 1)
	{
		HAL_Delay(5);
		while(HAL_GPIO_ReadPin(INPUT1_GPIO_Port,INPUT1_Pin) == 1);
		return 1;
	}
	return 0;
}
