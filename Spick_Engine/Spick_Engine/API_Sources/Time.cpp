#include "Time.hpp"

using namespace spic;

double Time::deltaTime {0.0};
double Time::timeScale {0.0};
std::chrono::steady_clock::time_point Time::applicationStart = std::chrono::steady_clock::now();
uint32_t Time::frameStart {0};

double Time::DeltaTime() {
	return Time::deltaTime;
}

double Time::TimeScale() {
	return Time::timeScale;
}

void Time::TimeScale(double newTimeScale) {}

void Time::SetFrameStart(uint32_t newFrameStart) {
	Time::frameStart = newFrameStart;
}

uint32_t Time::GetTicks() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - applicationStart).count();
}