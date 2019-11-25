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
 *  @file    Navigation.hpp
 *  @author  Sprint-1 Raj Shinde- driver and Prasheel Renkuntla- navigator
 *  @author  Sprint-2 Prasheel Renkuntla- driver and Raj Shinde- navigator
 *  @date    11/24/2019
 *  @version 6.0
 *  @brief   Mid Term Project
 *  @section Header file for Navigation through PID control
 */

#ifndef INCLUDE_NAVIGATION_HPP_
#define INCLUDE_NAVIGATION_HPP_

#include <vector>

#include <SteerAlgorithm.hpp>

/**
 *  @brief Class Navigation 
 *  Contains the methods of steer Algorithm
 */
class Navigation : public SteerAlgorithm {
 private:
    double kp_, ki_, kd_, diffTime_, error_, previousError_;
    const double maxMotorSpeed_ = 60;

 public:
    bool motorDirection = true;

   /**
    *  @brief Constructor of class Navigation
    */
    Navigation();

   /**
    *  @brief Destructor of class Navigation
    */
    ~Navigation();

   /**
    *  @brief Function to calculate new velocity in m/s with a PID 
    *  Algorithm using kp, ki & kd
    *  @param double targetHeading, Target heading of the robot
    *  @param double currentVelocity, current velocity of robot
    *  @param double setPoint, Target Velocity
    *  @param int flag, to enable while
    *  @return double newVelocity
   */
    double calculate(double targetHeading, double currentVelocity,
                     double setPoint, int flag);

   /**
    *  @brief Function to set graph parameters
    *  @param none
    *  @return none
    */
    bool setupGraph();

   /**
    *  @brief Function to display on Terminal
    *  @param int loc
    *  @param double currentVelocity
    *  @param double newVelocity
    *  @param double heading
    *  @param double targetHeading
    *  @return none
    */
    bool display(int loc, double currentVelocity, double newVelocity,
                 double heading, double targetHeading);

     /**
    *  @brief Function to draw graphs in gnuplot
    *  @param vector<pair<double, double>> points
    *  @param vector<pair<double, double>> pointsVelocity
    *  @param double newVelocity
    *  @param double tempHeading
    *  @return none
    */
    bool drawGraph(std::vector<std::pair<double, double>> points,
std::vector<std::pair<double, double>> pointsVelocity, double newVelocity,
double tempHeading);

   /**
    *  @brief Function to get kp_
    *  @param none
    *  @return double
    */
     double getKp_();

   /**
    *  @brief Function to get ki_
    *  @param none
    *  @return double 
    */
     double getKi_();

   /**
    *  @brief Function to get kd_
    *  @param none
    *  @return double 
    */
     double getKd_();

   /**
    *  @brief Function to set kp_
    *  @param double kp
    *  @return boolean true
    */
     bool setKp_(double kp);

   /**
    *  @brief Function to set ki_
    *  @param double ki
    *  @return boolean true
    */
     bool setKi_(double ki);

   /**
    *  @brief Function to set kd_
    *  @param double kd
    *  @return boolean true
    */
     bool setKd_(double kd);
};

#endif  // INCLUDE_NAVIGATION_HPP_
