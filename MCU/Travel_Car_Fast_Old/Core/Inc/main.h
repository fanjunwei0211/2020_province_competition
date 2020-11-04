/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define AIN4_Pin GPIO_PIN_2
#define AIN4_GPIO_Port GPIOE
#define BIN1_Pin GPIO_PIN_3
#define BIN1_GPIO_Port GPIOE
#define BIN2_Pin GPIO_PIN_4
#define BIN2_GPIO_Port GPIOE
#define BIN3_Pin GPIO_PIN_5
#define BIN3_GPIO_Port GPIOE
#define BIN4_Pin GPIO_PIN_6
#define BIN4_GPIO_Port GPIOE
#define LED_Pin GPIO_PIN_0
#define LED_GPIO_Port GPIOC
#define KEY_Pin GPIO_PIN_1
#define KEY_GPIO_Port GPIOC
#define Moto3_Pin GPIO_PIN_2
#define Moto3_GPIO_Port GPIOA
#define Moto4_Pin GPIO_PIN_3
#define Moto4_GPIO_Port GPIOA
#define Moto1_Pin GPIO_PIN_5
#define Moto1_GPIO_Port GPIOA
#define sensor8_Pin GPIO_PIN_15
#define sensor8_GPIO_Port GPIOE
#define sensor7_Pin GPIO_PIN_10
#define sensor7_GPIO_Port GPIOB
#define sensor6_Pin GPIO_PIN_11
#define sensor6_GPIO_Port GPIOB
#define sensor4_Pin GPIO_PIN_12
#define sensor4_GPIO_Port GPIOB
#define sensor3_Pin GPIO_PIN_13
#define sensor3_GPIO_Port GPIOB
#define sensor5_Pin GPIO_PIN_14
#define sensor5_GPIO_Port GPIOB
#define sensor2_Pin GPIO_PIN_15
#define sensor2_GPIO_Port GPIOB
#define sensor1_Pin GPIO_PIN_8
#define sensor1_GPIO_Port GPIOD
#define Moto2_Pin GPIO_PIN_3
#define Moto2_GPIO_Port GPIOB
#define AIN1_Pin GPIO_PIN_9
#define AIN1_GPIO_Port GPIOB
#define AIN2_Pin GPIO_PIN_0
#define AIN2_GPIO_Port GPIOE
#define AIN3_Pin GPIO_PIN_1
#define AIN3_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
