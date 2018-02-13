#include <wiringPi.h>
#include <wiringSerial.h>
#include <iostream>
#include <Serial.h>
using namespace std;

int serialInit(void)
{
	wiringPiSetup();
	int fd;
	unsigned char UartBuff[10];
	if((fd = serialOpen("/dev/serial0",115200))<0){
	cout<<"串口打开失败"<<endl;
	}
	else{
	cout<<"串口打开成功"<<endl;
	}
	return fd;
}

bool sendMessage(int fd,unsigned char* message)
{
        unsigned char Message[9];
		for(int i=0;i<7;i++)
		{
			//serialPrintf(fd,"This is just a test\r\n");
			Message[i]=message[i];
		}
		Message[7]=0X0D;
		Message[8]=0X0A;
		for(int i=0;i<9;i++)
            serialPutchar(fd,Message[i]);
		//delay(500);
}
