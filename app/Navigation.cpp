/************************************************************************
MIT License

Copyright © 2019 Raj Shinde

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the “Software”), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included 
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
 *************************************************************************/

/**
 *  @copyright MIT License, Copyright © 2019 Raj Shinde
 *  @file    Navigation.cpp
 *  @author  Sprint-1 Raj Shinde- driver and Prasheel Renkuntla- navigator
 *  @author  Sprint-2 Prasheel Renkuntla- driver and Raj Shinde- navigator
 *  @date    10/10/2019
 *  @version 1.0
 *  @brief   Mid Term Project
 *  @section
 */

#include <iostream>

#include <fstream> 

#include <time.h>

#include "Navigation.hpp"

#include "SteerAlgorithm.hpp"

Navigation::Navigation() {
kp_ = 0.5;
ki_ = 0.05;
kd_ = 0.001;
diffTime_ = 0.002;
error_ = 0;
previousError_ = 0;
}

Navigation::~Navigation() {}

//change is here
double Navigation::calculate(double targetHeading,
			     double currentVelocity, 				
			     double setPoint,
			     int flag) {
double newVelocity=0;
return newVelocity;
}

double Navigation::getKp_() {
return kp_;
}

double Navigation::getKi_() {
return ki_;
}

double Navigation::getKd_() {
return kd_;
}

bool Navigation::setKp_(double kp) {
bool flag = true;
kp_= kp;
if (kp_ != kp){
	flag=false;
}
return flag;
}

bool Navigation::setKi_(double ki) {
bool flag = true;
ki_= ki;
if (ki_ != ki){
	flag=false;
}
return flag;
}

bool Navigation::setKd_(double kd) {
bool flag = true;
kd_= kd;
if (kd_ != kd){
	flag=false;
}
return flag;
}

