#include "stdio.h"
#include "main.h"

extern UART_HandleTypeDef huart1;
//extern UART_HandleTypeDef huart2;

#define U1

#ifdef __GNUC__
	#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
	#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
	
PUTCHAR_PROTOTYPE
{
#ifdef U1
	HAL_UART_Transmit(&huart1 , (uint8_t *)&ch, 1, 0xFFFF);
#else
//	HAL_UART_Transmit(&huart2 , (uint8_t *)&ch, 1, 0xFFFF);
#endif
	return ch;
}

