
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
 *  @date    11/24/2019
 *  @version 6.0
 *  @brief   Mid Term Project
 *  @section Implements Ackermann on PID control
 */
#include <time.h>

#include <iostream>
#include <fstream>
#include <vector>

#include "gnuplot-iostream.h"
#include "Navigation.hpp"
#include "SteerAlgorithm.hpp"

Navigation::Navigation() {
//  Initialised Variables
kp_ = 0.5;
ki_ = 0.05;
kd_ = 0.001;
diffTime_ = 0.002;
error_ = 0;
previousError_ = 0;
}

Navigation::~Navigation() {}

double Navigation::calculate(double targetHeading,
                             double currentVelocity,
                             double setPoint,
                             int flag) {
double newVelocity = 0;
double errorValue = 0;     //  to store current error
double propOutput = 0;     //  to store proportional output
double integralVal = 0;    //  temp variable to calculate integral value
double intOutput = 0;      //  to store integral output
double derivativeVal = 0;  //  temp variable to calculate derivative value
double derOutput = 0;      //  to store derivative output
double tempVel;            //  temp variable to store current velocity
int velocityConverged = 0;
int headingConverged = 0;

double outTime = 0;        //  temp variable to determine convergence time
SteerAlgorithm Ackermann = SteerAlgorithm();

double tempHeading = targetHeading;      //  to store the target for graph

std::vector<std::pair<double, double>> combinedXY(1, std::make_pair(0, 0));
std::vector<std::pair<double, double>> points;
std::vector<std::pair<double, double>> pointsVelocity;

//  while loop to run until velocity and heading are converged
while(velocityConverged != 1 && headingConverged != 1) {
        //  Run PID control initially
        errorValue = setPoint - currentVelocity;
        propOutput = kp_ * errorValue;

        integralVal += errorValue * diffTime_;
        intOutput = ki_ * integralVal;

        derivativeVal = ((errorValue - previousError_) / diffTime_);
        derOutput = kd_ * derivativeVal;

        newVelocity = currentVelocity + (propOutput + intOutput + derOutput);
        previousError_ = errorValue;
        currentVelocity = newVelocity;

        clock_t toc = clock();

        //  store the current values in a vector for plotting
        pointsVelocity.push_back(std::make_pair((
                          static_cast<double> (clock())/CLOCKS_PER_SEC),
                          currentVelocity));
        if (flag == 2) {
        //  show the values on screen
        display(1, currentVelocity, newVelocity, heading, targetHeading);
        }
        if (setPoint == newVelocity) {
           velocityConverged = 1;
        }
        if ((targetHeading-heading) != 0 && velocityConverged == 1) {
          if (newVelocity > maxTurnVelocity) {
             tempVel = maxTurnVelocity;
          }
          tempVel = newVelocity;
          if (targetHeading-heading > 0) {
             dir = 1;
          } else {
             dir = -1;
          }
          //  change wheel angles to move robot towards target
          Ackermann.changeWheelAngles(Ackermann.getCorrRadius(),
                                      shaftLength,
                                      shaftDistance);

          double arcLen = Ackermann.arcLength(targetHeading,
                                      Ackermann.getCorrRadius());
          auto turnTime = Ackermann.turnTime(arcLen, newVelocity);
          clock_t tic = clock();

          //  loop until heading is converged towards target
          while ((outTime < turnTime) && (targetHeading != heading)) {
                errorValue = setPoint - currentVelocity;
                propOutput = kp_ * errorValue;

                integralVal += errorValue * diffTime_;
                intOutput = ki_ * integralVal;

                derivativeVal = ((errorValue - previousError_) / diffTime_);
                derOutput = kd_ * derivativeVal;

                newVelocity = currentVelocity +
                                     (propOutput + intOutput + derOutput);
                previousError_ = errorValue;
                currentVelocity = newVelocity;

                clock_t toc = clock();
                outTime = (static_cast<double> (toc - tic)) / CLOCKS_PER_SEC;
                double newArcLen = tempVel * outTime;
                heading = (newArcLen * targetHeading / arcLen);

                //  store the current values in a vector for plotting
                points.push_back(std::make_pair(
                  (static_cast<double> (clock())/CLOCKS_PER_SEC),
                    heading));
                if (flag == 2) {
                display(2, currentVelocity, newVelocity, heading, targetHeading);
                }
          }
        targetHeading = 0;
        headingConverged = 1;
        Ackermann.resetWheel();
        }
}
if (flag == 2) {
drawGraph(points, pointsVelocity, newVelocity, tempHeading);
return 0;
} else if (flag == 1) {
  return newVelocity;
} else {
  return heading;
}
errorValue = 0;
propOutput = 0;
integralVal = 0;
intOutput = 0;
derivativeVal = 0;
derOutput = 0;
return newVelocity;
}

bool Navigation::setupGraph() {
//  call object and intialise variables for Graph in GNUPLOT
Gnuplot gnu;
Gnuplot gnup;

//  set the graph on gnuplot for the respective coordinates
gnu << "set xrange [0:2]\nset yrange [0:100]\n";
gnu << "set title \"Steering angle Convergence\"\n";
gnu << "set pointsize 1\n";
gnu << "set xlabel \"Time\"\n";
gnu << "set ylabel \"Heading Angle\"\n";
gnu << "set key outside\n";

gnup << "set xrange [0:0.17]\nset yrange [0:45]\n";
gnup << "set title \"Velocity Convergence\"\n";
gnup << "set pointsize 1\n";
gnup << "set xlabel \"Time\"\n";
gnup << "set ylabel \"Current Velocity\"\n";
gnup << "set key outside\n";
return true;
}

bool Navigation::display(int loc, double currentVelocity, double newVelocity, double heading, double targetHeading) {
if(loc == 1) {
std::cout << "Current Velocity: " << currentVelocity
                  << " Setpoint: " << newVelocity << std::endl;
} else if (loc == 2)
std::cout << "Current Velocity: " << currentVelocity
          << " Setpoint: " << newVelocity << std::endl;
std::cout << "Current Heading: " << heading
          << " Target: " << targetHeading << std::endl;
return true;
}

bool Navigation::drawGraph(std::vector<std::pair<double, double>> points,
std::vector<std::pair<double, double>> pointsVelocity, double newVelocity, double tempHeading) {
//  call object and intialise variables for Graph in GNUPLOT
Gnuplot gnu;
Gnuplot gnup;

  //  Plot the graph on gnuplot by calling the below line
  gnu << "plot" << gnu.file1d(points) << "with points title 'Heading' lc 3, "
      << tempHeading << " title 'Target Heading' lt 1 lc 4" << std::endl;
  gnup << "plot" << gnup.file1d(pointsVelocity)
       << "with lp title 'Current Velocity' lc 3, "
       << newVelocity << " title 'Set Point' lt 1 lc 4" << std::endl;
return true;
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
kp_ = kp;
if (kp_ != kp) {
    flag = false;
}
return flag;
}

bool Navigation::setKi_(double ki) {
bool flag = true;
ki_ = ki;
if (ki_ != ki) {
    flag = false;
}
return flag;
}

bool Navigation::setKd_(double kd) {
bool flag = true;
kd_ = kd;
if (kd_ != kd) {
    flag = false;
}
return flag;
}
