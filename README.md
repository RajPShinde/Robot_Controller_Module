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
<br>

## Overview
This is a controller module for a robot that uses an Ackermann Steering Model, for the Robot made by ACME Robotics.

## Description

## Agile Iterative Process Log
[Log- ](https://docs.google.com/spreadsheets/d/1LFQMKbuGeusgmI7IMbjiw-RJrt9jNgej0F8SvvfyJjY/edit?usp=sharing)

## Dependencies
1. C++ 11
2. GNUPplot
* Install GNUplot
```
sudo apt-get install GNUplot-iostream
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
