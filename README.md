# Robot Controller Module
[![Build Status](https://travis-ci.org/RajPShinde/Robot_Controller_Module.svg?branch=master)](https://travis-ci.org/RajPShinde/Robot_Controller_Module)
[![Coverage Status](https://coveralls.io/repos/github/RajPShinde/Robot_Controller_Module/badge.svg?branch=master)](https://coveralls.io/github/RajPShinde/Robot_Controller_Module?branch=master)
[![License MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/RajPShinde/Robot_Controller_Module/blob/master/LICENSE.md)
[![Documentation](https://img.shields.io/badge/docs-generated-brightgreen.svg)]()
---

## Authors

* **Raj Prakash Shinde** - *Sprint 1- Driver & Sprint 2- Navigator* - [GitHub](https://github.com/RajPShinde)
<br>I am a Masters in Robotics Engineering student at the University of Maryland, College Park.
* **Prasheel Renkuntla** - *Sprint 1- Navigator & Sprint 2- Driver* - [GitHub](https://github.com/Prasheel24)
<br>To be added

## Overview
This is a controller module for a robot that uses an Ackermann Steering Model, This controller is to be implemented in a four wheeled Robot made by ACME Robotics.

## Description
<br>A controller is build for a 4 wheeled robot with an Ackermann steering to navigate through its environment. The controller consist of a PID algorithm which  ensures that the velocity converges to the set point, and a Steer Algorithm that helps the robot turn.
<br>The PID Algorithm is a control loop mechanism that calculates the error and applies correction through proportional, integral and derivative gains. The Steer Algorithm is developed to turn the robot, which is done by calculating the length of an arc inscribed between the current robot heading and target heading, the length when divided by the robot velocity gives the time for which the wheels need to be kept at angles given by Ackermann steering Model.
<br>The input to the controller will be provided by the perception model developed by the ACME Robotics.
<br>The Demonstration of the controller will be given by plotting a graph that shows convergence of velocity & Heading angle to the targets with respect to time.

## Agile Iterative Process Log
Log- https://docs.google.com/spreadsheets/d/1LFQMKbuGeusgmI7IMbjiw-RJrt9jNgej0F8SvvfyJjY/edit?usp=sharing

## Dependencies
1. C++ 11
2. GNUplot
Download gnuplot
```
git clone https://github.com/dstahlke/gnuplot-iostream.git
```

## TODO
* Update the AIP spreadsheet.
* Implementation of the Functions.
* Display Output on Graph.
* Make sure that all the Test are passed.
* Update UML Diagrams.
* Check for cpplint and cppcheck errors and paste output in results.

## Build
```
git clone --recursive https://github.com/RajPShinde/Robot_Controller_Module.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
```
## Run
#### Run Program
```
./app/shell-app
```
#### Run Test
```
./test/cpp-test
```
## Demo
To Be Added

## Result
To Be Added

## Bugs
None

## References
* Ackermann Steering- https://www.sciencedirect.com/topics/engineering/ackermann
* PID Controller- https://en.wikipedia.org/wiki/PID_controller
