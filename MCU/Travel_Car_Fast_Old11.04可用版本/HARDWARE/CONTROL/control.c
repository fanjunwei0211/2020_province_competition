#include "main.h"
#include "control.h"
#include "gpio.h"

extern int Target_L,Target_R;//,Target_C,Target_D; //�������180
extern int Sensor[8];
extern int Target_Speed,Target_Pwm;
extern int moto1,moto2,moto3,moto4;


void Sensor_Get(void)
{
//	int Track[2] = { 0 };       //���ݻ����� 
//	Read_Data(Track);
//	int Temp_Value=Track[0];
//	for(int i=0; i<8; i++)
//	{
//		Sensor[i] = Temp_Value%2;
//		Temp_Value /=2;
//	}
	Sensor[0] = HAL_GPIO_ReadPin(sensor1_GPIO_Port,sensor1_Pin);
	Sensor[1] = HAL_GPIO_ReadPin(sensor2_GPIO_Port,sensor2_Pin);
	Sensor[2] = HAL_GPIO_ReadPin(sensor3_GPIO_Port,sensor3_Pin);
	Sensor[3] = HAL_GPIO_ReadPin(sensor4_GPIO_Port,sensor4_Pin);
	Sensor[4] = HAL_GPIO_ReadPin(sensor5_GPIO_Port,sensor5_Pin);
	Sensor[5] = HAL_GPIO_ReadPin(sensor6_GPIO_Port,sensor6_Pin);
	Sensor[6] = HAL_GPIO_ReadPin(sensor7_GPIO_Port,sensor7_Pin);
	Sensor[7] = HAL_GPIO_ReadPin(sensor8_GPIO_Port,sensor8_Pin);
	
	
}


void track_zhixian()
{
	static int Last_Sensor[8];
	if(Sensor[3] == 0 && Sensor[4] == 0)
	{
		Target_L = Target_Speed;
		Target_R = Target_Speed;
	}
	else if(Sensor[3]==0 && Sensor[4]!=0)
	{
		Target_L = Target_Speed-10;
		Target_R = Target_Speed+10;
	}
	else if(Sensor[3]!=0 && Sensor[4]==0)
	{
		Target_L = Target_Speed+10;
		Target_R = Target_Speed-10;
	}
	else if(Sensor[2]!=0 && Sensor[3]==0)
	{
		Target_L = Target_Speed-20;
		Target_R = Target_Speed+20;
	}
	else if(Sensor[2]==0 && Sensor[3]!=0)
	{
		Target_L = Target_Speed-30;
		Target_R = Target_Speed+30;
	}
	else if(Sensor[2]==0 && Sensor[3]==0)
	{
		Target_L = Target_Speed-25;
		Target_R = Target_Speed+25;
	}
//	else if(Sensor[1]!=0 && Sensor[2]==0)
//	{
//		Target_L = Target_Speed;
//		Target_R = Target_Speed+40;
//	}
//	else if(Sensor[1]==0 && Sensor[2]!=0)
//	{
//		Target_L = Target_Speed;
//		Target_R = Target_Speed+50;
//	}
//	else if(Sensor[0]!=0 && Sensor[1]==0)
//	{
//		Target_L = Target_Speed;
//		Target_R = Target_Speed+60;
//	}
//	else if(Sensor[0]==0 && Sensor[1]!=0)
//	{
//		Target_L = Target_Speed;
//		Target_R = Target_Speed+70;
//	}
	else if(Sensor[4]==0 && Sensor[5]!=0)
	{
		Target_L = Target_Speed+20;
		Target_R = Target_Speed-20;
	}
	else if(Sensor[4]!=0 && Sensor[5]==0)
	{
		Target_L = Target_Speed+30;
		Target_R = Target_Speed-30;
	}
	else if(Sensor[4]==0 && Sensor[5]==0)
	{
		Target_L = Target_Speed+25;
		Target_R = Target_Speed-25;
	}
	else
	{
			for(int i=0; i<8; i++)
		{
			Sensor[i] = Last_Sensor[i];
		}
	}
//	else if(Sensor[5]==0 && Sensor[6]!=0)
//	{
//		Target_L = Target_Speed+40;
//		Target_R = Target_Speed;
//	}
//	else if(Sensor[5]!=0 && Sensor[6]==0)
//	{
//		Target_L = Target_Speed+50;
//		Target_R = Target_Speed;
//	}
//	else if(Sensor[6]==0 && Sensor[7]!=0)
//	{
//		Target_L = Target_Speed+60;
//		Target_R = Target_Speed;
//	}
//	else if(Sensor[6]!=0 && Sensor[7]==0)
//	{
//		Target_L = Target_Speed+70;
//		Target_R = Target_Speed;
//	}
	
	for(int i=0; i<8; i++)
	{
		Last_Sensor[i] = Sensor[i];
	}
		

}

void track_zhixian_Po()
{
	static int Last_Sensor[8];
	if(Sensor[3] == 0 && Sensor[4] == 0)
	{
		Target_L = Target_Speed;
		Target_R = Target_Speed;
	}
	else if(Sensor[3]==0 && Sensor[4]!=0)
	{
		Target_L = Target_Speed-10;
		Target_R = Target_Speed+10;
	}
	else if(Sensor[3]!=0 && Sensor[4]==0)
	{
		Target_L = Target_Speed+10;
		Target_R = Target_Speed-10;
	}
	else if(Sensor[2]!=0 && Sensor[3]==0)
	{
		Target_L = Target_Speed-20;
		Target_R = Target_Speed+20;
	}
	else if(Sensor[2]==0 && Sensor[3]!=0)
	{
		Target_L = Target_Speed-30;
		Target_R = Target_Speed+30;
	}
	else if(Sensor[2]==0 && Sensor[3]==0)
	{
		Target_L = Target_Speed-25;
		Target_R = Target_Speed+25;
	}
	else if(Sensor[4]==0 && Sensor[5]!=0)
	{
		Target_L = Target_Speed+20;
		Target_R = Target_Speed-20;
	}
	else if(Sensor[4]!=0 && Sensor[5]==0)
	{
		Target_L = Target_Speed+30;
		Target_R = Target_Speed-30;
	}
	else if(Sensor[4]==0 && Sensor[5]==0)
	{
		Target_L = Target_Speed+25;
		Target_R = Target_Speed-25;
	}
	else
	{
		Target_L = Target_Speed;
		Target_R = Target_Speed;
	}
	
	for(int i=0; i<8; i++)
	{
		Last_Sensor[i] = Sensor[i];
	}
		

}


void track_zhixian_PID()
{
	static int Last_Sensor[8];	
	float Velocity_KP=20,Velocity_KI=0,Velocity_KD=0;	
	static int Bias,Speed=0,Last_bias,Last_old_bias,Bias_Sum=0;                
	
	if(Sensor[3] == 0 && Sensor[4] == 0)
	{
		Bias = 0;
	}
	else if(Sensor[3]==0 && Sensor[4]!=0)
	{
		Bias = 1;
	}
	else if(Sensor[3]!=0 && Sensor[4]==0)
	{
		Bias = -1;
	}
	else if(Sensor[2]!=0 && Sensor[3]==0)
	{
		Bias =2;
	}
	else if(Sensor[2]==0 && Sensor[3]!=0)
	{
		Bias = 3;
	}
	else if(Sensor[2]==0 && Sensor[3]==0)
	{
		Bias = 3;
	}
	else if(Sensor[1]!=0 && Sensor[2]==0)
	{
		Bias = 4;
	}
	else if(Sensor[1]==0 && Sensor[2]==0)
	{
		Bias = 4;
	}
	else if(Sensor[0]!=0 && Sensor[1]==0)
	{
		Bias = 5;
	}
	else if(Sensor[0]==0 && Sensor[1]==0)
	{
		Bias = 5;
	}
	else if(Sensor[0]==0 && Sensor[1]!=0)
	{
		Bias = 6;
	}
	else if(Sensor[4]==0 && Sensor[5]!=0)
	{
		Bias = -2;
	}
	else if(Sensor[4]!=0 && Sensor[5]==0)
	{
		Bias = -3;
	}
	else if(Sensor[4]==0 && Sensor[5]==0)
	{
		Bias = -3;
	}
	else if(Sensor[5]==0 && Sensor[6]!=0)
	{
		Bias = -4;
	}
	else if(Sensor[5]==0 && Sensor[6]==0)
	{
		Bias = -4;
	}
	else if(Sensor[6]==0 && Sensor[7]!=0)
	{
		Bias = -5;
	}
	else if(Sensor[6]==0 && Sensor[7]==0)
	{
		Bias = -5;
	}
	else if(Sensor[6]!=0 && Sensor[7]==0)
	{
		Bias = -6;
	}
	else
	{
		moto1=moto2=Target_Pwm;
		moto3=moto4=Target_Pwm;
	}
	
//	if(Bias==0)
//		Bias_Sum=0;
//	Bias_Sum += Bias;
	for(int i=0; i<8; i++)
	{
		Last_Sensor[i] = Sensor[i];
	}
//	Bias=Target-Encoder;                //����ƫ��
	Speed+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;//+Velocity_KD*(Bias-2*Last_bias+Last_old_bias);   //����ʽPI������
	Last_old_bias=Last_bias;
	Last_bias=Bias;	  	//������һ��ƫ��      
	moto1 = moto2 = Target_Pwm-Speed; //������ƫʱSpeedΪ��,������ƫΪ��
	moto3 = moto4 = Target_Pwm+Speed;

}

int Zhijiao_Detect()
{
	int Cnt=0;
	for(int i=0; i< 4; i++)
	{
		if(Sensor[i] == 0)
			Cnt++;
	}
	if(Cnt>=3 && Sensor[0] == 0)
		return 1;
	
	return 0;
}

void XianFu()
{
	if(moto1>500)
		moto1 = moto2 = 500;
	else if(moto1 < -500)
		moto1 = moto2 = -500;
	
	if(moto3>500)
		moto3 = moto4 = 500;
	else if(moto3 <-500)
		moto3 = moto4 = -500;
	
}

///*************************************
//*�������ƣ�track_PID
//*�������ܣ�ֱ��ѭ�����ô��������ӣ�ֻ���ƫ��ֵ
//*������pwm������ٶ�ֵ��P������ϵ����ȡֵ��0��1
//*˵����
//*			
//**************************************/
//void track_PID(int pwm,float P)
//{
//	static float Integral_error,Last_error;
//	int temp_data[2] = { 0 };       //���ݻ�����
//	int error = 0;         //ƫ��ֵ
//	int L_Pwm,R_Pwm;			 //�������ٶ�
//	float I = 0,D = 0;		 //����ϵ����΢��ϵ��
//	
//	Read_Data(temp_data);

//}
