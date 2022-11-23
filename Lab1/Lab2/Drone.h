#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Framework
{

};

class Engine
{

};

class SpeedLimiter
{

};

class Accumulator
{

};

template<typename T>
class Drone: Framework, Engine, SpeedLimiter, Accumulator
{

};

