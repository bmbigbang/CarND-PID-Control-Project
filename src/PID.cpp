#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Kd, double Ki) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
  PID::sum_err = 0.0;
  PID::count = 0;
  PID::diff_cte = 0;
  PID::last_cte = 0;
}

void PID::UpdateError(double cte) {

  PID::sum_err += pow(cte, 2);
  PID::count++;

}

double PID::TotalError() {
  return PID::sum_err / PID::count;
}

