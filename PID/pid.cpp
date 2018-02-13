#include <pid.h>
#include <Serial.h>
#include <iostream>
using namespace std;

float AngleKp, AngleKi, AngleKd;
float DisKp, DisKi, DisKd;

float AngleSpeed, DisSpeed;



//角速度相关参数的声明
float angle_now, angle_old;
int error_now, error_old, error_d, error_i;
float pwm_old = 0;
const int pid_i_const = 100;
const int pid_i_const_low = -100;
float pwm_kp, pwm_kd, pwm_ki, pwm_pd;

//距离偏差相关参数的声明
float dis_angle_now, dis_angle_old;
int dis_error_now, dis_error_old, dis_error_d, dis_error_i;
float dis_pwm_old = 0;
const int dis_pid_i_const = 100;
const int dis_pid_i_const_low = -100;
float dis_pwm_kp, dis_pwm_kd, dis_pwm_ki, dis_pwm_pd;

//LED for pid controller
float led_angle_now, led_angle_old;
int led_error_now, led_error_old, led_error_d, led_error_i;
float led_pwm_old = 0;
const int led_pid_i_const = 100;
const int led_pid_i_const_low = -100;
float led_pwm_kp, led_pwm_kd, led_pwm_ki, led_pwm_pd;
float LedKp, LedKi, LedKd;


void PID_Init()
{
    AngleKp = 21.4;
    AngleKi = 0;
    AngleKd = 40.4;

    DisKp = 2.4;
    DisKi = 0;
    DisKd = 22.4;

    LedKp = 65.4;
    LedKi = 0;
    LedKd = 100.4;
}


void PID_Call(float angle, int dis)
{
    {
        //角速度PID计算
		
        if (angle_now > 80)
        {
            angle_now = angle_old;
        }
        if (angle_now < -80)
            angle_now = angle_old;
        angle_old = angle_now;
        error_now = 0 - angle;
        //printf("error %d\r\n",error_now);
        pwm_kp = AngleKp*error_now;


        error_d = error_now - error_old;

        pwm_kd = AngleKd*error_d;

        error_i += error_now;
        if (error_i > pid_i_const)
            error_i = pid_i_const;
        if (error_i < pid_i_const_low)
            error_i = pid_i_const_low;
        pwm_ki = AngleKi*error_i;
        error_old = error_now;
        pwm_pd = pwm_kp + pwm_kd + error_i;
        pwm_old = pwm_pd;
        AngleSpeed = pwm_pd;

    }

    {	
	
        //距离误差速度计算
        if (dis_angle_now > 35)
        {
            dis_angle_now = dis_angle_old;
        }
        if (dis_angle_now < -35)
            dis_angle_now = dis_angle_old;
        dis_angle_old = dis_angle_now;
        dis_error_now = 0 - dis;
        dis_pwm_kp = DisKp*dis_error_now;


        dis_error_d = dis_error_now - dis_error_old;

        dis_pwm_kd = DisKd*dis_error_d;

        dis_error_i += dis_error_now;
        if (dis_error_i > dis_pid_i_const)
            dis_error_i = dis_pid_i_const;
        if (dis_error_i < dis_pid_i_const_low)
            dis_error_i = dis_pid_i_const_low;
        dis_pwm_ki = DisKi*dis_error_i;
        dis_error_old = dis_error_now;
        dis_pwm_pd = dis_pwm_kp + dis_pwm_kd + dis_error_i;
        dis_pwm_old = dis_pwm_pd;
        DisSpeed = dis_pwm_pd;
    }
    //cout << AngleSpeed << " " << DisSpeed << endl;
}

void PID_Call_Led(int angle)
{
    //角速度PID计算
        if (led_angle_now > 110)
        {
            led_angle_now = led_angle_old;
        }
        if (led_angle_now < -110)
            led_angle_now = led_angle_old;
        led_angle_old = led_angle_now;
        led_error_now = 0 - angle;
        //printf("error %d\r\n",error_now);
        led_pwm_kp = LedKp*led_error_now;


        led_error_d = led_error_now - led_error_old;

        led_pwm_kd = LedKd*led_error_d;

        led_error_i += led_error_now;
        if (led_error_i > led_pid_i_const)
            led_error_i = led_pid_i_const;
        if (led_error_i < led_pid_i_const_low)
            led_error_i = led_pid_i_const_low;
        led_pwm_ki = LedKi*led_error_i;
        led_error_old = led_error_now;
        led_pwm_pd = led_pwm_kp + led_pwm_kd + led_error_i;
        led_pwm_old = led_pwm_pd;
        AngleSpeed = led_pwm_pd;
}


