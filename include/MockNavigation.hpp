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
 *  @file    MockNavigation.hpp
 *  @author  Raj Shinde
 *  @date    11/24/2019
 *  @version 7.0
 *  @brief   Mid Term Project
 *  @section Mocked navigation class
 */

#ifndef ROBOT_CONTROLLER_MODULE_INCLUDE_MOCKNAVIGATION_HPP_
#define ROBOT_CONTROLLER_MODULE_INCLUDE_MOCKNAVIGATION_HPP_

#include <gmock/gmock.h>
#include <vector>
#include <iostream>

#include "Navigation.hpp"

/**
 *  @brief Mock Navigation class 
 */
class MockNavigation: public Navigation{
 public :
   /**
    *  @brief Default constructor
    */
    MockNavigation() : Navigation() {}

   /**
    *  @brief Mock getKp_
    */
    MOCK_METHOD0(getKp_, double());

    /**
    *  @brief Mock calculate method
    */
    MOCK_METHOD4(calculate, double(double targetHeading,
                                    double currentVelocity,
                                    double setPoint,
                                    int flag));
};

#endif  // ROBOT_CONTROLLER_MODULE_INCLUDE_MOCKNAVIGATION_HPP_
