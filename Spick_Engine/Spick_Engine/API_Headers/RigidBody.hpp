#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_

#include "Component.hpp"
#include "Point.hpp"

namespace spic {

    /**
     * @brief Enumeration for different rigid body types
     */
    enum class BodyType {
        staticBody,
        kinematicBody,
        dynamicBody
    };

    /**
     * @brief A component representing a rigid body.
     */
    class RigidBody : public Component {
        public:
            /**
             * @brief Get mass.
             * @return mass.
             */
            double GetMass() const { return mass; }

            /**
             * @brief Set mass.
             */
            void SetMass(double mass) { this->mass = mass; }

            /**
             * @brief Get gravity scale.
             * @return gravity scale.
             */
            double GetGravityScale() const { return gravityScale; }

            /**
             * @brief Set gravity scale.
             */
            void SetGravityScale(double gravityScale) { this->gravityScale = gravityScale; }

            /**
             * @brief Get body type.
             * @return body type.
             */
            const BodyType& GetBodyType() const { return bodyType; }

            /**
             * @brief Set body type.
             */
            void SetBodyType(const BodyType& bodyType) { this->bodyType = bodyType; }

            /**
             * @brief Apply force to this rigid body.
             * @param forceDirection A point, used as a vector to indicate direction
             *        and magnitude of the force to be applied.
             */
            void AddForce(const Point& forceDirection);

        private:
            double mass;
            double gravityScale;
            BodyType bodyType;
    };

}

#endif // RIGIDBODY_H_
