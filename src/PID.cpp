#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  double error = -Kp * p_error - Ki * i_error - Kd * d_error;
  if (error < -1){
    error = -1;
  } else if (error > 1) {
    error = 1;
  }
  cout << "i_error: " << i_error << " D :" << (Kd * d_error) << " I:" << (Ki * i_error) << " P: " << (Kp * p_error) << " " << error << endl;
  return error;
}
