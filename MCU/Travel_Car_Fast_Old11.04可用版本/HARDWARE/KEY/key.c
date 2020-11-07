#include "key.h"

int KeyState(void)
{
	if(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) == 0)
	{
		HAL_Delay(5);
		while(HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) == 0);
		return 1;
	}
	return 0;
}
