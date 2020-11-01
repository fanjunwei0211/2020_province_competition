#include "pid.h"



/**************************************************************************
�������ܣ�����PI������
��ڲ���������������ֵ��Ŀ���ٶ�
����  ֵ�����PWM
��������ʽ��ɢPID��ʽ 
pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
e(k)������ƫ�� 
e(k-1)������һ�ε�ƫ��  �Դ����� 
pwm�����������
�����ǵ��ٶȿ��Ʊջ�ϵͳ���棬ֻʹ��PI����
pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)
**************************************************************************/
int Incremental_PI_A (int Encoder,int Target)
{ 	
	float Velocity_KP=12,Velocity_KI=0.3;	
	static int Bias,Pwm,Last_bias;
	Bias=Target-Encoder;                //����ƫ��
	Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //����ʽPI������
	Last_bias=Bias;	                   //������һ��ƫ�� 
	return Pwm;                         //�������
}
int Incremental_PI_B (int Encoder,int Target)
{ 	
	float Velocity_KP=12,Velocity_KI=0.3;	
	static int Bias,Pwm,Last_bias;
	Bias=Target-Encoder;                //����ƫ��
	Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //����ʽPI������
	Last_bias=Bias;	                   //������һ��ƫ�� 
	return Pwm;                         //�������
}
int Incremental_PI_C (int Encoder,int Target)
{ 	
	float Velocity_KP=12,Velocity_KI=0.3;	
	static int Bias,Pwm,Last_bias;
	Bias=Target-Encoder;                //����ƫ��
	Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //����ʽPI������
	Last_bias=Bias;	                   //������һ��ƫ�� 
	return Pwm;                         //�������
}

int Incremental_PI_D (int Encoder,int Target)
{ 	
	float Velocity_KP=12,Velocity_KI=0.3;	
	static int Bias,Pwm,Last_bias;
	Bias=Target-Encoder;                //����ƫ��
	Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //����ʽPI������
	Last_bias=Bias;	                   //������һ��ƫ�� 
	return Pwm;                         //�������
}


//float pid_position_type(pid_typedef *pid,float desired,float actual)//pid����������ֵ��ʵ��ֵ
//{
//	pid->dx = desired - actual;
//	pid->f_dx = pid->dx*pid->kp + pid->sum_dx*pid->ki + (pid->dx-pid->previous_dx)*pid->kd;
//	pid->sum_dx += pid->dx;
//	pid->previous_dx = pid->dx;
//	
//	return pid->f_dx;
//}
//float pid_increment_type(pid_typedef *pid,float desired,float actual)//pid����������ֵ��ʵ��ֵ
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
