#pragma once
class Position_PID{
private:
    float kp,ki,kd,bias,integal_bias,last_bias;
    float pwm;
public:
    int do_position_pid(int position,int target);
};