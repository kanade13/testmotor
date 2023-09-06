#include "chassis.hpp"
// 整车移动量转换为单轮速度  x:前+后- m/s  y:左+右- m/s z:逆+顺-

#define diameter 0.15
#define pi 3.1415
void Chassis::Move_Transfrom()
{
	double TargetA=(speed.vx+speed.vy-speed.vz*(Car_H/2+Car_W/2))/(pi*diameter);
	double TargetB=(speed.vx-speed.vy-speed.vz*(Car_H/2+Car_W/2))/(pi*diameter);
	double TargetC=(speed.vx+speed.vy+speed.vz*(Car_H/2+Car_W/2))/(pi*diameter);
	double TargetD=(speed.vx-speed.vy+speed.vz*(Car_H/2+Car_W/2))/(pi*diameter);
    this->motorspeed.setmotorspeed(TargetA,TargetB,TargetC,TargetD);
}
void Chassis::do_motor_output(){
	motora.Motor_Output(GPIOC,GPIO_PIN_1,GPIOC,GPIO_PIN_2,TIM_CHANNEL_2);
	motorb.Motor_Output(GPIOC,GPIO_PIN_7,GPIOC,GPIO_PIN_8,TIM_CHANNEL_1);
	motorc.Motor_Output(GPIOD,GPIO_PIN_0,GPIOD,GPIO_PIN_1,TIM_CHANNEL_3);
	motord.Motor_Output(GPIOF,GPIO_PIN_2,GPIOF,GPIO_PIN_3,TIM_CHANNEL_4);
}

void Chassis::do_motor_speed(){
	motora.get_speed();
    motora.clear_counter();
	motorb.get_speed();
    motorb.clear_counter();
	motorc.get_speed();
    motorc.clear_counter();
	motord.get_speed();
    motord.clear_counter();
}

void Chassis::set_all_def(){
	motora.set_definition(motorspeed.TargetA);
	motorb.set_definition(motorspeed.TargetB);
	motorc.set_definition(motorspeed.TargetC);
	motord.set_definition(motorspeed.TargetD);
}