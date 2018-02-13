#ifndef _Serial_H
#define _Serial_H
int serialInit(void);
bool sendMessage(int fd,unsigned char* message);
#endif