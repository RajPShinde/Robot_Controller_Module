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

#include "SteerAlgorithm.hpp"

SteerAlgorithm::SteerAlgorithm() {
lWheelAngle_ = 0;
rWheelAngle_ = 0;
heading_ = 0;
robotAngle_ = 0;
corrRadius_ = 10;
}

SteerAlgorithm::~SteerAlgorithm() {}

double SteerAlgorithm::getCorrRadius_() {
return 20;
}

bool SteerAlgorithm::setCorrRadius_(double r) {
return false;
}

double SteerAlgorithm::arcLength(double diffAngle, double corrRadius) {
return 100;
}

double SteerAlgorithm::changeWheelAngles(double corrRadius,
double shaftLength, double shaftDistance) {
return 50;
}

bool SteerAlgorithm::resetWheel() {
return false;
}

double SteerAlgorithm::turnTime(double arclength, double newVelocity) {
return -100;
}

