#include "chassis.hpp"
// 整车移动量转换为单轮速度  x:前+后-  y:左+右-  z:逆+顺-
void Chassis::Move_Transfrom(double Vx,double Vy,double Vz)
{
	double TargetA=Vx+Vy-Vz*(Car_H/2+Car_W/2);
	double TargetB=Vx-Vy-Vz*(Car_H/2+Car_W/2);
	double TargetC=Vx+Vy+Vz*(Car_H/2+Car_W/2);
	double TargetD=Vx-Vy+Vz*(Car_H/2+Car_W/2);
    this->motorspeed.setmotorspeed(TargetA,TargetB,TargetC,TargetD);
}
void Chassis::do_motor_output(int pwma,int pwmb,int pwmc,int pwmd){
	motora.Motor_Output(pwma);
	motorb.Motor_Output(pwmb);
	motorc.Motor_Output(pwmc);
	motord.Motor_Output(pwmd);
}

void Chassis::do_motor_counter(GPIO_TypeDef * GPIO,uint16_t GPIO_PIN){
	motora.Motor_Counter(GPIO,GPIO_PIN);
}

void Chassis::do_motor_speed(){
	motora.get_speed();
    motora.clear_counter();
}