#pragma once

#include "motor.hpp"

class Speed{
private:
    double vx{0.0};
    double vy{0.0};
    double vz{0.0};
public:
    void setspeed(double x,double y,double z){
        vx=x;
        vy=y;
        vz=z;
    }
};
class Motorspeed{
    double TargetA{0.0},TargetB{0.0},TargetC{0.0},TargetD{0.0};
    public:
    void setmotorspeed(double a,double b,double c,double d){
        TargetA=a;
        TargetB=b;
        TargetC=c;
        TargetD=d;
    }
};
class Chassis{
public:
    void Move_Transfrom(double Vx,double Vy,double Vz);
    void do_motor_output(int pwma,int pwmb,int pwmc,int pwmd);
    void do_motor_counter(GPIO_TypeDef * GPIO1,uint16_t GPIO_PIN1);
    void do_motor_speed();
    Chassis();
private:
    const double Car_H,Car_W;
    motor motora,motorb,motorc,motord;
    Speed speed;
    Motorspeed motorspeed;
};

extern Chassis chassis;
