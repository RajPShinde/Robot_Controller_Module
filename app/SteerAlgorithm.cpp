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
 *  @file    SteerAlgorithm.cpp
 *  @author  Sprint-1 Raj Shinde- driver and Prasheel Renkuntla- navigator
 *  @author  Sprint-2 Prasheel Renkuntla- driver and Raj Shinde- navigator
 *  @date    10/10/2019
 *  @version 1.0
 *  @brief   Mid Term Project
 *  @section
 */

#include <iostream>

#include <cmath>

#include "SteerAlgorithm.hpp"

SteerAlgorithm::SteerAlgorithm() {
lWheelAngle_ = 0;
rWheelAngle_ = 0;
heading_ = 0;
robotAngle_ = 0;
corrRadius_ = 100;
}

SteerAlgorithm::~SteerAlgorithm() {}

double SteerAlgorithm::getCorrRadius_() {
return corrRadius_;
}

bool SteerAlgorithm::setCorrRadius_(double r) {
bool flag = true;
corrRadius_=r;
if(corrRadius_ != r) {
	flag=false;
}
return flag;
}

double SteerAlgorithm::arcLength(double diffAngle, double corrRadius) {
return ((diffAngle/360)*(2*M_PI*corrRadius));
}

double SteerAlgorithm::changeWheelAngles(double corrRadius,
					 double shaftLength, 
					 double shaftDistance) {
lWheelAngle_ = (M_PI/2) - std::atan((corrRadius + (shaftLength / 2))
						 / shaftDistance) * dir; 
rWheelAngle_ = (M_PI/2) - std::atan((corrRadius - (shaftLength / 2))
						 / shaftDistance) * dir; 
return std::max(lWheelAngle_,rWheelAngle_);
}

bool SteerAlgorithm::resetWheel() {
bool flag = true;
lWheelAngle_=0;
rWheelAngle_=0;
if(lWheelAngle_!=0 && rWheelAngle_!=0){
	flag=false;
}
return flag;
}

double SteerAlgorithm::turnTime(double arclength, double newVelocity) {
return (arclength/newVelocity);
}

