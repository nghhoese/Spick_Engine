#ifndef TIME_H_
#define TIME_H_

#include <cstdint>
#include <ctime>
#include <ratio>
#include <chrono>

namespace spic {

    /**
     * @brief Class representing game time.
     */
    class Time {
        public:
            /**
             * @brief The interval in seconds from the last frame to the current one (Read Only)
             */
            static double DeltaTime();

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

        private:
            static double deltaTime;
            static double timeScale;
            static std::chrono::steady_clock::time_point applicationStart;
            static uint32_t frameStart;
    };
}

#endif // TIME_H_
