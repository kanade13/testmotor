#pragma once

#include "motor.hpp"

class Speed{
public:
    double vx;
    double vy;
    double vz;
public:
    void setspeed(double x,double y,double z){
        vx=x;
        vy=y;
        vz=z;
    }
    Speed() : vx(0), vy(0), vz(0) {}
};
class Motorspeed{
public:
    double TargetA,TargetB,TargetC,TargetD;
public:
    void setmotorspeed(double a,double b,double c,double d){
        TargetA=a;
        TargetB=b;
        TargetC=c;
        TargetD=d;
    }
    Motorspeed():TargetA(0),TargetB(0),TargetC(0),TargetD(0){}
};
class Chassis{
public:
    void Move_Transfrom();
    void do_motor_output();
    void do_motor_speed();
    //int get_counter(){return motora.get_counter();}
    float return_speed(){return motora.return_speed();}
    Chassis(int car_h,int car_w):Car_H(car_h),Car_W(car_w){};
    void set_all_def();
public:
    const double Car_H,Car_W;
    motor motora,motorb,motorc,motord;
    Speed speed;
    Motorspeed motorspeed;
};


