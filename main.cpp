#include<iostream>
#include<Serial.h>
#include<Image.h>
#include<pid.h>
using namespace std;

int main(void)
{
	//cout<<"This is a test"<<endl;
	int fd = serialInit();
	PID_Init();
	//unsigned char  a[3]={0x00,0x00,0x00};
	//while(1){
	//sendMessage(fd,a);
	//}
	startImage(fd);
	return 0;
}
