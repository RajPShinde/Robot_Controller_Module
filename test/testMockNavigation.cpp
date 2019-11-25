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
 *  @file    testMockNavigation.cpp
 *  @author  Raj Shinde
 *  @date    11/24/2019
 *  @version 7.0
 *  @brief   Mid Term Project
 *  @section Test MockNavigation
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "MockNavigation.hpp"
#include "Navigation.hpp"

/**
 *  @brief Test Kp and calculate using gmock
 */
TEST(MockNavigation, testGetKp) {
MockNavigation o;
//  Expect a call to getkp_
  EXPECT_CALL(o, getKp_()).Times(1);
  o.getKp_();
}

TEST(MockNavigation, testCalculate) {
MockNavigation o;
//  Expect a call to compute method
EXPECT_CALL(o, calculate(120, 10, 0, 1)).Times(2);
o.calculate(120, 10, 0, 1);
// Check the returned value with expected value
EXPECT_EQ(o.calculate(120, 10, 0, 1), 0);
}
