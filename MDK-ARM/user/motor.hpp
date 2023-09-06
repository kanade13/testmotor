#pragma once
#include "main.h"
#include "PID.hpp"
#include "tim.h"

class motor{
public:
    unsigned int counter=0;
    float Revolution_Per_Second=0;//速度,每秒旋转的圈数
    float definition=0;
public:
    static const int Gear_Ratio=51;
    static const int Pulses_Per_Revolution=13;
    static const int Contect_frequency=200;//每5ms发送一次电机速度,故检测频率设为200
    PID pid;
    void Motor_Counter();
    void Motor_Output(GPIO_TypeDef* gpioa,uint16_t gpiopina,GPIO_TypeDef* gpiob,uint16_t gpiopinb,unsigned int tim_channel);
    void clear_counter();
    void get_speed();
    void set_definition(float definiton);
    float return_speed(){return Revolution_Per_Second;}
    motor():counter(0),Revolution_Per_Second(0){}
};
