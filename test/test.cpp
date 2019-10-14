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
 *  @file    test.cpp
 *  @author  Sprint-1 Raj Shinde- driver and Prasheel Renkuntla- navigator
 *  @author  Sprint-2 Prasheel Renkuntla- driver and Raj Shinde- navigator
 *  @date    10/10/2019
 *  @version 1.0
 *  @brief   Mid Term Project
 *  @section
 */
#include <gtest/gtest.h>

#include <cstdlib>
#include <memory>

#include "Navigation.hpp"
#include "SteerAlgorithm.hpp"

/**
 *  @brief Test to check the set functions
 *  for kp_,ki_ and kd_
 */
TEST(Navigation, testSetPid) {
Navigation testn;
EXPECT_TRUE(testn.setKp_(1));
EXPECT_TRUE(testn.setKi_(1));
EXPECT_TRUE(testn.setKd_(1));
}

/**
 *  @brief Test to check that values of
 *  kp_,ki_ and kd_ are below 1 or not
 */
TEST(Navigation, testGetPid) {
Navigation testn;
EXPECT_LT(testn.getKp_(), 1);
EXPECT_LT(testn.getKi_(), 1);
EXPECT_LT(testn.getKd_(), 1);
}

/**
 *  @brief Test to check the output of PID
 *  Controller in the first cycle is within the set
 *  bound
 */
TEST(Navigation, testVelocity) {
Navigation testn;
ASSERT_NEAR(testn.calculate(10, 30, 0), 30, 10);
}

/**
 *  @brief Tests to check that the set functions works 
 *  and the value of corrRadius in below setlimit
 */
TEST(SteerAlgorithm, testCorrRadius) {
SteerAlgorithm tests;
EXPECT_TRUE(tests.setCorrRadius_(10));
EXPECT_LT(tests.getCorrRadius_(), 20);
}

/**
 *  @brief Tests to check if the wheel angles get 
 *  resetted and the Ackeermann kinematic model is
 *  is properly implemented
 */
TEST(SteerAlgorithm, testwheel) {
SteerAlgorithm tests;
EXPECT_TRUE(tests.resetWheel());
EXPECT_LT(tests.changeWheelAngles(10, 4, 8), 46);
}

/**
 *  @brief Test to check the functions arclength 
 *  and turnTime provide right length and time values
 */
TEST(SteerAlgorithm, testCalculations) {
SteerAlgorithm tests;
EXPECT_LT(tests.arcLength(360, 10), 70);
EXPECT_GT(tests.turnTime(3, 10), 0);
}

