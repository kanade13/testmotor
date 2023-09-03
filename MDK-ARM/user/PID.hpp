#pragma once
#define max_speed 3.7
class PID{
private:
    float kp=0.5;
    float ki=0.08;
    float kd=0.02;

    float now=0;
    float definition=0;

    float error=0;
    float error_l=0;
    float error_ll=0;

    float out=0;

    //优化项
    float deadband=0.05;
public:
    float do_pid();
    void set_definition(float definition);
    void setnow(float now);
};

