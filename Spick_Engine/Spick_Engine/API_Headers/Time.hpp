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
            SPIC_API static double TimeScale();

            /**
            * @brief The scale at which time passes.
            * @param The new value for the time scale.
            */
            SPIC_API static void TimeScale(double newTimeScale);

            /**
            * @brief The scale at which time passes.
            * @param The new value for the time scale.
            */
            static void SetFrameStart(uint32_t newFrameStart);

            /**
            * @brief Get the frame start.
            * @param The time framestart.
            */
            static uint32_t GetFrameStart() { return Time::frameStart; }

            /**
            * @brief The scale at which time passes.
            * @param The new value for the time scale.
            */
            static uint32_t GetTicks();

            /**
            * @brief Set the delta time.
            * @param float time.
            */
            SPIC_API void SetDeltaTime(float time) { deltaTime = time; }

            /**
            * @brief Get the delta time
            * @return deltatime (float).
            */
            SPIC_API float GetDeltaTime() { return deltaTime; }

            /**
            * @brief Calculate the delta time
            * @return deltatime (float).
            */
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
