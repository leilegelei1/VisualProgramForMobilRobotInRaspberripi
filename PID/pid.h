#include <Serial.h>

extern float AngleSpeed, DisSpeed;

void PID_Call(float angle, int diserror);
void PID_Init();
void PID_Call_Led(int angle);
