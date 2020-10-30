#include "main.h"

typedef struct
{
	float kp;
	float ki;
	float kd;
	float dx;
	float sum_dx;
	float previous_dx;
	float pre_previous_dx;
	float f_dx;
}pid_typedef;
extern pid_typedef pid1,pid2,pid3,pid4;

void pid_init(void);
void pid_deinit(pid_typedef *pid);
float pid_position_type(pid_typedef *pid,float desired,float actual);//位置式pid
float pid_increment_type(pid_typedef *pid,float desired,float actual);//增量式pid
int Incremental_PI_A (int Encoder,int Target);
int Incremental_PI_B (int Encoder,int Target);
int Incremental_PI_C (int Encoder,int Target);
int Incremental_PI_D (int Encoder,int Target);
