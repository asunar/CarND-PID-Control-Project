#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this -> Kp = Kp;
    this -> Ki = Ki;
    this -> Kd = Kd;

    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte) {
	sum_cte += cte;
  	p_error = - Kp * cte;
  	i_error = - Ki * sum_cte;
  	d_error = - Kd * (cte - prev_cte);
  	prev_cte = cte;

    total_error = cte;
  	//std::cout << "updated error" << std::endl;
}

double PID::TotalError() {

    return total_error;
}

double PID::getValue() {
	double steeringAngle = p_error + i_error + d_error;
	steeringAngle = steeringAngle<-1?-1:steeringAngle;
	steeringAngle = steeringAngle>1?1:steeringAngle;
	return steeringAngle;
}

