#include "Timer.h"


Timer::Timer()
{
	startTimePoint = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	Stop();
}


void Timer::Stop()
{
	auto endTimePoint = std::chrono::high_resolution_clock::now();
	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
	auto duration = end - start;
	double elapsedSeconds = duration / 1000000.0;
	double fps = 1.0 / elapsedSeconds;
	std::cout <<"Current fps is " << fps << " fps" << std::endl;
}

