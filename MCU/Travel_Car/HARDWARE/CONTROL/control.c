#include "main.h"
#include "control.h"
#include "sensor8.h"

extern int Target_L,Target_R;//,Target_C,Target_D; //�������180
extern int Sensor[8];
extern int Target_L,Target_R;
extern int Target_Speed;


void Sensor_Get(void)
{
	int Track[2] = { 0 };       //���ݻ����� 
	Read_Data(Track);
	int Temp_Value=Track[0];
	for(int i=0; i<8; i++)
	{
		Sensor[i] = Temp_Value%2;
		Temp_Value /=2;
	}
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

void XianFu()
{
	if(Target_L>180)
		Target_L = 180;
	else if(Target_L < -180)
		Target_L = -180;
	
	if(Target_R>180)
		Target_R = 180;
	else if(Target_R <-180)
		Target_R = -180;
}

/*************************************
*�������ƣ�track_PID
*�������ܣ�ֱ��ѭ�����ô��������ӣ�ֻ���ƫ��ֵ
*������pwm������ٶ�ֵ��P������ϵ����ȡֵ��0��1
*˵����
*			
**************************************/
void track_PID(int pwm,float P)
{
	static float Integral_error,Last_error;
	int temp_data[2] = { 0 };       //���ݻ�����
	int error = 0;         //ƫ��ֵ
	int L_Pwm,R_Pwm;			 //�������ٶ�
	float I = 0,D = 0;		 //����ϵ����΢��ϵ��
	
	Read_Data(temp_data);

}
