#include "../../include//utils/Timer.hpp"

void SDIZO::Timer::start()
{
	this->startPoint = std::chrono::high_resolution_clock::now();
}

void SDIZO::Timer::stop()
{
	this->endPoint = std::chrono::high_resolution_clock::now();
}

long long SDIZO::Timer::getTime(TimerPrecision precision)
{
	long long result;

	switch (precision)
	{
	case TimerPrecision::Nanoseconds:
		result = std::chrono::duration_cast<std::chrono::nanoseconds>(endPoint - startPoint).count();
		break;
	case TimerPrecision::Microseconds:
		result = std::chrono::duration_cast<std::chrono::microseconds>(endPoint - startPoint).count();
		break;
	case TimerPrecision::Milliseconds:
		result = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - startPoint).count();
		break;
	case TimerPrecision::Seconds:
		result = std::chrono::duration_cast<std::chrono::seconds>(endPoint - startPoint).count();
		break;
	}

	return result;
}