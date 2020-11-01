#include "pid.h"



/**************************************************************************
函数功能：增量PI控制器
入口参数：编码器测量值，目标速度
返回  值：电机PWM
根据增量式离散PID公式 
pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
e(k)代表本次偏差 
e(k-1)代表上一次的偏差  以此类推 
pwm代表增量输出
在我们的速度控制闭环系统里面，只使用PI控制
pwm+=Kp[e（k）-e(k-1)]+Ki*e(k)
**************************************************************************/
int Incremental_PI_A (int Encoder,int Target)
{ 	
	float Velocity_KP=12,Velocity_KI=0.3;	
	static int Bias,Pwm,Last_bias;
	Bias=Target-Encoder;                //计算偏差
	Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
	Last_bias=Bias;	                   //保存上一次偏差 
	return Pwm;                         //增量输出
}
int Incremental_PI_B (int Encoder,int Target)
{ 	
	float Velocity_KP=12,Velocity_KI=0.3;	
	static int Bias,Pwm,Last_bias;
	Bias=Target-Encoder;                //计算偏差
	Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
	Last_bias=Bias;	                   //保存上一次偏差 
	return Pwm;                         //增量输出
}
int Incremental_PI_C (int Encoder,int Target)
{ 	
	float Velocity_KP=12,Velocity_KI=0.3;	
	static int Bias,Pwm,Last_bias;
	Bias=Target-Encoder;                //计算偏差
	Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
	Last_bias=Bias;	                   //保存上一次偏差 
	return Pwm;                         //增量输出
}

int Incremental_PI_D (int Encoder,int Target)
{ 	
	float Velocity_KP=12,Velocity_KI=0.3;	
	static int Bias,Pwm,Last_bias;
	Bias=Target-Encoder;                //计算偏差
	Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
	Last_bias=Bias;	                   //保存上一次偏差 
	return Pwm;                         //增量输出
}


//float pid_position_type(pid_typedef *pid,float desired,float actual)//pid参数，期望值，实际值
//{
//	pid->dx = desired - actual;
//	pid->f_dx = pid->dx*pid->kp + pid->sum_dx*pid->ki + (pid->dx-pid->previous_dx)*pid->kd;
//	pid->sum_dx += pid->dx;
//	pid->previous_dx = pid->dx;
//	
//	return pid->f_dx;
//}
//float pid_increment_type(pid_typedef *pid,float desired,float actual)//pid参数，期望值，实际值
//{
//	pid->dx = desired - actual;
//	pid->f_dx = (pid->dx-pid->previous_dx)*pid->kp + pid->dx*pid->ki 
//							+ (pid->dx-2*pid->previous_dx+pid->pre_previous_dx)*pid->kd;
//	pid->pre_previous_dx = pid->previous_dx;
//	pid->previous_dx = pid->dx;

//	return pid->f_dx;
//}
//void pid_deinit(pid_typedef *pid)
//{
//	pid->sum_dx=0;
//	pid->previous_dx=0;
//	pid->pre_previous_dx=0;
//}
//void pid_init()
//{
//	pid1.kp=50;
//	pid1.ki=1;
//	pid1.kd=0;
//	pid1.sum_dx=0;
//	pid1.previous_dx=0;
//	pid1.pre_previous_dx=0;
//	
//	pid2.kp=2;
//	pid2.ki=0.2;
//	pid2.kd=0;
//	pid2.sum_dx=0;
//	pid2.previous_dx=0;
//	pid2.pre_previous_dx=0;
//	
//	pid3.kp=2;
//	pid3.ki=0.07;
//	pid3.kd=0;
//	pid3.sum_dx=0;
//	pid3.previous_dx=0;
//	pid3.pre_previous_dx=0;
//	
//	pid4.kp=5;
//	pid4.ki=1;
//	pid4.kd=0;
//	pid4.sum_dx=0;
//	pid4.previous_dx=0;
//	pid4.pre_previous_dx=0;
//}
/*void pid_init()
{
	pid1.kp=2;
	pid1.ki=1;
	pid1.kd=0;
	pid1.sum_dx=0;
	pid1.previous_dx=0;
	pid1.pre_previous_dx=0;
	
	pid2.kp=2;
	pid2.ki=1;
	pid2.kd=0;
	pid2.sum_dx=0;
	pid2.previous_dx=0;
	pid2.pre_previous_dx=0;
	
	pid3.kp=2;
	pid3.ki=1;
	pid3.kd=0;
	pid3.sum_dx=0;
	pid3.previous_dx=0;
	pid3.pre_previous_dx=0;
	
	pid4.kp=2;
	pid4.ki=1;
	pid4.kd=0;
	pid4.sum_dx=0;
	pid4.previous_dx=0;
	pid4.pre_previous_dx=0;
}
*/
