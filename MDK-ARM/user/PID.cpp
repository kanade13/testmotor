#include "PID.hpp"
//电机的增量式PID控制

float PID::do_pid()
{
  //设置死区
    error_ll=error_l;
    error_l=error;
    error=definition-now;
  float abserror=((error>0) ? error : -error);
  if(abserror<this->deadband){
    return out;
  }
  float out_p = kp*(error - error_l);
  float out_i = ki*error;
  float out_d = kd*(error - 2*error_l +error_ll);

  out+=out_p+out_i+out_d;

  if(out>max_speed)
		out=max_speed;	//限幅
	else if(out<-max_speed)
		out=-max_speed;		//限幅
  
  return out;
}

void PID::set_definition(float definition){
  this->definition=definition;
}

void PID::setnow(float now){
  this->now=now;
}