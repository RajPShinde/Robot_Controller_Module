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
 *  @file    SteerAlgorithm.hpp
 *  @author  Sprint-1 Raj Shinde- driver and Prasheel Renkuntla- navigator
 *  @author  Sprint-2 Prasheel Renkuntla- driver and Raj Shinde- navigator
 *  @date    11/25/2019
 *  @version 6.0
 *  @brief   Mid Term Project
 *  @section Ackermann Steering Control Header file
 */

#ifndef INCLUDE_STEERALGORITHM_HPP_
#define INCLUDE_STEERALGORITHM_HPP_

/**
 *  @brief Class SteerAlgorithm
 *  contains the methods of the Steering Algorithm.
 */
class SteerAlgorithm {
 private:
  const double wheelCircumference_ = 2;
  double lWheelAngle_, rWheelAngle_, corrRadius_;

 public:
    const double shaftLength = 4;
    const double shaftDistance = 8;
    const double maxTurnVelocity = 20;
    double heading;
    double targetHeading;
    int dir;
   /**
    *  @brief Constructor of class SteerAlgorithm
    */
    SteerAlgorithm();

   /**
    *  @brief Destructor of class SteerAlgorithm
    */
    ~SteerAlgorithm();

   /**
    *  @brief Function to get corresponding radius in meters
    *  @param none
    *  @return double corresponding radius
    */
    double getCorrRadius();

   /**
    *  @brief Function to set corresponding radius in meters
    *  @param double radius
    *  @return bool true
    */
    bool setCorrRadius(double r);

   /**
    *  @brief Function to calculate the length of arc in meters
    *  to be traced in order to head in target direction
    *  @param double diffAngle, difference in current and 
    *  target heading
    *  @param double corrRadius, corresponding radius
    *  @return double arclength
    */
    double arcLength(double diffAngle, double corrRadius);

   /**
    *  @brief Function to calculate the angles in degrees for left and
    *  right wheels as per ackermann model, and then feed them
    *  to corresponding servo
    *  @param double corrRadius, corresponding radius
    *  @param double shaftLength, length between wheels
    *  @param double shafDistance, distance between rear and
    *  front shaft
    *  @return double maxWheelAngle
    */
    double changeWheelAngles(double corrRadius, double shaftLength,
                             double shaftDistance);

  /**
    *  @brief Function to set wheel angles to 0
    *  @param none
    *  @return bool true
    */
    bool resetWheel();

   /**
    *  @brief Function to calculate time in seconds required to
    *  turn or keep wheels at the an angle
    *  @param double arcLength, length of arc to be traced
    *  @param double newVelocity, velocity
    *  @return double time
    */
    double turnTime(double arclength, double newVelocity);
};
#endif  // INCLUDE_STEERALGORITHM_HPP_
