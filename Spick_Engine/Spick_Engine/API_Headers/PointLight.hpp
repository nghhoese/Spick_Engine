#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "Light.hpp"

namespace spic {

    /**
     * @brief The point light.
     */
    class PointLight : public Light {

    public:
        /**
         * @brief Get innerRadius.
         * @return innerRadius.
         */
        int GetInnerRadius() const { return innerRadius; }

        /**
         * @brief Set innerRadius.
         */
        void SetInnerRadius(int innerRadius) { this->innerRadius = innerRadius; }

        /**
         * @brief Get outerRadius.
         * @return outerRadius.
         */
        int GetOuterRadius() const { return outerRadius; }

        /**
         * @brief Set outerRadius.
         */
        void SetOuterRadius(int outerRadius) { this->outerRadius = outerRadius; }

        /**
         * @brief Get innerAngle.
         * @return innerAngle.
         */
        int GetInnerAngle() const { return innerAngle; }

        /**
         * @brief Set innerAngle.
         */
        void SetInnerAngle(int innerAngle) { this->innerAngle = innerAngle; }

        /**
         * @brief Get outerAngle.
         * @return outerAngle.
         */
        int GetOuterAngle() const { return outerAngle; }

        /**
         * @brief Set outerAngle.
         */
        void SetOuterAngle(int outerAngle) { this->outerAngle = outerAngle; }

    private:
        int innerRadius;
        int outerRadius;
        int innerAngle;
        int outerAngle;

    };

}

#endif // POINTLIGHT_H_
