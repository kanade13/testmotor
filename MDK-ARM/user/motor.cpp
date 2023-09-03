#include "motor.hpp"

void motor::Motor_Output(){

	pid.set_definition(this->definition);
	pid.setnow(Revolution_Per_Second);
	
	int pwm=this->pid.do_pid()/1.246*10000;
	if(pwm==0){
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
	}
	if(pwm>0){
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
	}
	if(pwm<0){
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);
	}
	//__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_2,(pwm>0)?pwm:-pwm); 
	__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_2,(pwm>0)?pwm:-pwm);//设定ccr以更改占空比，输出pwm信号
}

void motor::Motor_Counter(GPIO_TypeDef * GPIO,uint16_t GPIO_PIN){
	/*if ((HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_SET)&&(HAL_GPIO_ReadPin(GPIO,GPIO_PIN)==GPIO_PIN_RESET)){
		counter++;
	}
	if ((HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_RESET)&&(HAL_GPIO_ReadPin(GPIO,GPIO_PIN)==GPIO_PIN_SET)){
		counter++;
	}*/
	this->counter++;
}
void motor::clear_counter(){
	this->counter=0;
}

void motor::get_speed(){
	float a=counter*Contect_frequency;
	float b=Pulses_Per_Revolution*Gear_Ratio;
	this->Revolution_Per_Second=a/b;
}

void motor::set_definition(float def)
{
	this->definition=def;
}