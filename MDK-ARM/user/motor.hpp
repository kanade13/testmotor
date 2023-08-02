#pragma once
#include "main.h"
#include "PID.hpp"
#include "tim.h"
#define max_speed 15000
class motor{
private:
    int counter={0};
    int speed{0};
public:
    void Motor_Counter(GPIO_TypeDef * GPIO,uint16_t GPIO_PIN);
    void Motor_Output(int num);
    void clear_counter();
    void get_speed();
};
