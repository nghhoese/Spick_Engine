#include "../API_Headers/Time.hpp"

using namespace spic;


double Time::timeScale {1.0};
std::chrono::steady_clock::time_point Time::applicationStart = std::chrono::steady_clock::now();
uint32_t Time::frameStart {0};

SPIC_API float Time::DeltaTime() {
	return deltaTime;
}

double Time::TimeScale() {
	return Time::timeScale;
}

SPIC_API void Time::TimeScale(double newTimeScale) {
	Time::timeScale = newTimeScale;
}

void Time::SetFrameStart(uint32_t newFrameStart) {
	Time::frameStart = newFrameStart;
}

uint32_t Time::GetTicks() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - applicationStart).count();
}

SPIC_API float spic::Time::CalculateDeltaTime()
{
		float duration = (float)GetTicks();
		SetDeltaTime(duration - m_lastTime);
		m_lastTime = duration;

		return GetDeltaTime();
}
