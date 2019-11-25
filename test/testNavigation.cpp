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
 *  @file    testNavigation.cpp
 *  @author  Sprint-1 Raj Shinde- driver and Prasheel Renkuntla- navigator
 *  @author  Sprint-2 Prasheel Renkuntla- driver and Raj Shinde- navigator
 *  @date    10/10/2019
 *  @version 6.0
 *  @brief   Mid Term Project
 *  @section Tests functionality of Navigation code
 */

#include <gtest/gtest.h>

#include <cstdlib>
#include <memory>

#include "Navigation.hpp"

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
 *  @brief Test to check the output of calculate
 *  function converges with the setPoint and
 *  Heading
 */
TEST(Navigation, testConvergence) {
Navigation testn;
ASSERT_NEAR(testn.calculate(0, 10, 40, 1), 40, 2);
ASSERT_NEAR(testn.calculate(120, 10, 40, 0), 120, 1);
}

/**
 *  @brief Test to check the functions arclength 
 *  and turnTime provide right length and time values
 */
TEST(Navigation, graphs) {
Navigation tests;
std::vector<std::pair<double, double>> points;
std::vector<std::pair<double, double>> pointsVelocity;
pointsVelocity.push_back(std::make_pair((
                          static_cast<double> (clock())/CLOCKS_PER_SEC),
                          10));
points.push_back(std::make_pair((
                          static_cast<double> (clock())/CLOCKS_PER_SEC),
                          10));
EXPECT_TRUE(tests.drawGraph(points, pointsVelocity, 20, 30));
EXPECT_TRUE(tests.display(0, 0, 10, 20, 7));
EXPECT_TRUE(tests.setupGraph());
}
