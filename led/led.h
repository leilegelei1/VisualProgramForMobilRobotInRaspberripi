#include <iostream>
#include <pid.h>
using namespace std;

#define ForwardFlag 0
#define BackFlag 1
#define LeftFlag 2
#define RightFlag 3
#define TurnFlag 4
#define StopFlag 5

typedef struct
{
    int Judgeflag;
}LedJudgeflag;

extern int Pianjiao;
extern int Judgeflag;
void LedInit();
unsigned char ReadLed();
void MoveOk();
void PIDInAll(float angle,int dis,int fd);
