#ifndef __ENCODER_H
#define __ENCODER_H

#include "main.h"
#include "gpio.h"
#include "stdint.h"

extern void Encoder_start(void);
extern int Read_Encoder(uint8_t TIMX);

#endif
