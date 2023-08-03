#include "motor.hpp"

void motor::Motor_Output(int num){
	if(num==0){
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
	}
	if(num>0){
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
	}
	if(num<0){
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	}
	int pwm=this->pid.do_position_pid(speed,num);
	if(pwm>max_speed)
		pwm=max_speed;	//限幅
	else if(pwm<-max_speed)
		pwm=-max_speed;		//限幅
	
	__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_2,(pwm>0)?pwm:-pwm); //设定ccr以更改占空比，输出pwm信号
}

void motor::Motor_Counter(GPIO_TypeDef * GPIO,uint16_t GPIO_PIN){
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_SET){
		if(HAL_GPIO_ReadPin(GPIO,GPIO_PIN)==GPIO_PIN_RESET){
			counter++;
		}
		else if(HAL_GPIO_ReadPin(GPIO,GPIO_PIN)==GPIO_PIN_SET){
			counter--;
		}
	}
	else{
		if(HAL_GPIO_ReadPin(GPIO,GPIO_PIN)==GPIO_PIN_RESET){
			counter--;
		}
		else if(HAL_GPIO_ReadPin(GPIO,GPIO_PIN)==GPIO_PIN_SET){
			counter++;
		}
	}
}
void motor::clear_counter(){
	this->counter=0;
}

void motor::get_speed(){
	this->speed=counter;
}
