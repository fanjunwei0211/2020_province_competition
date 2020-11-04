//#include "main.h"
//#include "usart.h"

//extern UART_HandleTypeDef huart1;

///*-------匿名上位机串口通信协议---------*/
////数据拆分宏定义   >1字节时拆分发送
//#define BYTE0(dwTemp)       (*(char *)(&dwTemp))     //取出int型变量的低字节
//#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))     //    取存储在此变量下一内存字节的内容，高字节
//#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
//#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))
//char testdatatosend[50];   //发送数据缓冲

//void Test_Send_User(int data1, int data2, int data3)	//发送用户数据，这里有3个数据，分别对应本教程3个数据
//{
//	char _cnt=0;
//	
//	testdatatosend[_cnt++]=0xAA;//0xAA为帧头
//	testdatatosend[_cnt++]=0x05;//0x05为数据发送源，具体请参考匿名协议，本字节用户可以随意更改
//	testdatatosend[_cnt++]=0xAF;//0xAF为数据目的地，AF表示上位机，具体请参考匿名协议
//	testdatatosend[_cnt++]=0xF1;//0xF1，表示本帧为F1用户自定义帧，对应高级收码的F1功能帧
//	testdatatosend[_cnt++]=0;//本字节表示数据长度，这里先=0，函数最后再赋值，这样就不用人工计算长度了
// 
//	testdatatosend[_cnt++]=BYTE1(data1);//将要发送的数据放至发送缓冲区
//	testdatatosend[_cnt++]=BYTE0(data1);
//	
//	testdatatosend[_cnt++]=BYTE1(data2);//将要发送的数据放至发送缓冲区
//	testdatatosend[_cnt++]=BYTE0(data2);
//	
//	testdatatosend[_cnt++]=BYTE3(data3);
//	testdatatosend[_cnt++]=BYTE2(data3);
//	testdatatosend[_cnt++]=BYTE1(data3);
//	testdatatosend[_cnt++]=BYTE0(data3);
// 
//	testdatatosend[4] = _cnt-5;//_cnt用来计算数据长度，减5为减去帧开头5个非数据字节
//	
//	char sum = 0;	//以下为计算sum校验字节，从0xAA也就是首字节，一直到sum字节前一字节
//	for(char i=0;i<_cnt;i++)
//		sum += testdatatosend[i];
//	
//	testdatatosend[_cnt++]=sum;	//将sum校验数据放置最后一字节
// 
//	HAL_UART_Transmit(&huart1,testdatatosend,_cnt,100);
//}
