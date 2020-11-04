#include "main.h"
#include "control.h"
#include "gpio.h"

extern int Target_L,Target_R;//,Target_C,Target_D; //满辐大概180
extern int Sensor[8];
extern int Target_Speed;


void Sensor_Get(void)
{
//	int Track[2] = { 0 };       //数据缓存区 
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
	float Velocity_KP=5,Velocity_KI=0;	
	static int Bias,Speed,Last_bias;
	                 //保存上一次偏差                      
	
	if(Sensor[3] == 0 && Sensor[4] == 0)
	{
		Bias = 0;
	}
	else if(Sensor[3]==0 && Sensor[4]!=0)
	{
		Bias = 2;
	}
	else if(Sensor[3]!=0 && Sensor[4]==0)
	{
		Bias = -2;
	}
	else if(Sensor[2]!=0 && Sensor[3]==0)
	{
		Bias =4;
	}
	else if(Sensor[2]==0 && Sensor[3]!=0)
	{
		Bias = 6;
	}
	else if(Sensor[2]==0 && Sensor[3]==0)
	{
		Bias = 6;
	}
	else if(Sensor[1]!=0 && Sensor[2]==0)
	{
		Bias = 8;
	}
	else if(Sensor[1]==0 && Sensor[2]==0)
	{
		Bias = 8;
	}
	else if(Sensor[0]!=0 && Sensor[1]==0)
	{
		Bias = 10;
	}
	else if(Sensor[0]==0 && Sensor[1]==0)
	{
		Bias = 10;
	}
	else if(Sensor[0]==0 && Sensor[1]!=0)
	{
		Bias = 12;
	}
	else if(Sensor[4]==0 && Sensor[5]!=0)
	{
		Bias = -4;
	}
	else if(Sensor[4]!=0 && Sensor[5]==0)
	{
		Bias = -6;
	}
	else if(Sensor[4]==0 && Sensor[5]==0)
	{
		Bias = -6;
	}
	else if(Sensor[5]==0 && Sensor[6]!=0)
	{
		Bias = -8;
	}
	else if(Sensor[5]==0 && Sensor[6]==0)
	{
		Bias = -8;
	}
	else if(Sensor[6]==0 && Sensor[7]!=0)
	{
		Bias = -10;
	}
	else if(Sensor[6]==0 && Sensor[7]==0)
	{
		Bias = -10;
	}
	else if(Sensor[6]!=0 && Sensor[7]==0)
	{
		Bias = -12;
	}
	else
	{
		
		for(int i=0; i<8; i++)
		{
			Sensor[i] = Last_Sensor[i];
		}
	}
	
	for(int i=0; i<8; i++)
	{
		Last_Sensor[i] = Sensor[i];
	}
	Speed+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
	Last_bias=Bias;	  	
	Target_L = Target_Speed-Speed;  //整体左偏时Speed为负,整体右偏为正
	Target_R = Target_Speed+Speed;

}

void track_zhixian_PID_Po()
{
	static int Last_Sensor[8];	
	float Velocity_KP=5,Velocity_KI=0;	
	static int Bias,Speed,Last_bias;
	                 //保存上一次偏差                      
	
	if(Sensor[3] == 0 && Sensor[4] == 0)
	{
		Bias = 0;
	}
	else if(Sensor[3]==0 && Sensor[4]!=0)
	{
		Bias = 2;
	}
	else if(Sensor[3]!=0 && Sensor[4]==0)
	{
		Bias = -2;
	}
	else if(Sensor[2]!=0 && Sensor[3]==0)
	{
		Bias =4;
	}
	else if(Sensor[2]==0 && Sensor[3]!=0)
	{
		Bias = 6;
	}
	else if(Sensor[2]==0 && Sensor[3]==0)
	{
		Bias = 6;
	}
	else if(Sensor[1]!=0 && Sensor[2]==0)
	{
		Bias = 8;
	}
	else if(Sensor[1]==0 && Sensor[2]==0)
	{
		Bias = 8;
	}
	else if(Sensor[0]!=0 && Sensor[1]==0)
	{
		Bias = 10;
	}
	else if(Sensor[0]==0 && Sensor[1]==0)
	{
		Bias = 10;
	}
	else if(Sensor[0]==0 && Sensor[1]!=0)
	{
		Bias = 12;
	}
	else if(Sensor[4]==0 && Sensor[5]!=0)
	{
		Bias = -4;
	}
	else if(Sensor[4]!=0 && Sensor[5]==0)
	{
		Bias = -6;
	}
	else if(Sensor[4]==0 && Sensor[5]==0)
	{
		Bias = -6;
	}
	else if(Sensor[5]==0 && Sensor[6]!=0)
	{
		Bias = -8;
	}
	else if(Sensor[5]==0 && Sensor[6]==0)
	{
		Bias = -8;
	}
	else if(Sensor[6]==0 && Sensor[7]!=0)
	{
		Bias = -10;
	}
	else if(Sensor[6]==0 && Sensor[7]==0)
	{
		Bias = -10;
	}
	else if(Sensor[6]!=0 && Sensor[7]==0)
	{
		Bias = -12;
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
	Speed+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
	Last_bias=Bias;	  	
	Target_L = Target_Speed-Speed;  //整体左偏时Speed为负,整体右偏为正
	Target_R = Target_Speed+Speed;

}


int Zhijiao_Detect()
{
	int Cnt=0,CntR=0;
	for(int i=0; i< 4; i++)
	{
		if(Sensor[i] == 0)
			Cnt++;
	}
	for(int i=4; i<8; i++)
	{	
		if(Sensor[i] == 0)
			CntR++;
	}
	if(Cnt>=3)
		return 1;
	
	return 0;
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

///*************************************
//*函数名称：track_PID
//*函数功能：直线循迹，用串口线连接，只输出偏移值
//*参数：pwm：最大速度值，P：比例系数，取值：0至1
//*说明：
//*			
//**************************************/
//void track_PID(int pwm,float P)
//{
//	static float Integral_error,Last_error;
//	int temp_data[2] = { 0 };       //数据缓存区
//	int error = 0;         //偏差值
//	int L_Pwm,R_Pwm;			 //左右轮速度
//	float I = 0,D = 0;		 //积分系数，微分系数
//	
//	Read_Data(temp_data);

//}
