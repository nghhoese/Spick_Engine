#ifndef TIME_H_
#define TIME_H_

#include <cstdint>
#include <ctime>
#include <ratio>
#include <chrono>
#include "SpicHeader.hpp"

namespace spic {

    /**
     * @brief Class representing game time.
     */
    class Time {
        public:
            /**
             * @brief The interval in seconds from the last frame to the current one (Read Only)
             */
            SPIC_API float DeltaTime();

            /**
             * @brief The scale at which time passes.
             * @return time scale value
             */
            static double TimeScale();

            /**
             * @brief The scale at which time passes.
             * @param The new value for the time scale.
             */
            static void TimeScale(double newTimeScale);

            /**
             * @brief The scale at which time passes.
             * @param The new value for the time scale.
             */
            static void SetFrameStart(uint32_t newFrameStart);

            static uint32_t GetFrameStart() { return Time::frameStart; }

            /**
             * @brief The scale at which time passes.
             * @param The new value for the time scale.
             */
            static uint32_t GetTicks();

            SPIC_API void SetDeltaTime(float time) { deltaTime = time; }
            SPIC_API float GetDeltaTime() { return deltaTime; }

            SPIC_API float CalculateDeltaTime();

        private:
            float deltaTime;
            static double timeScale;
            static std::chrono::steady_clock::time_point applicationStart;
            static uint32_t frameStart;
            float m_lastTime = 0.0f;
    };
}

#endif // TIME_H_
