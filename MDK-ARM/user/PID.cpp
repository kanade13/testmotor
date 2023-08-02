#include "PID.hpp"
//电机的位置式pid控制，注意：position和target的单位为 脉冲数/单位时间

int Position_PID::do_position_pid(int position,int target){
    bias=target-position;
    integal_bias+=bias;
    pwm=kp*bias+ki*integal_bias+kd*(bias-last_bias);
    last_bias=bias;
    return pwm;
}