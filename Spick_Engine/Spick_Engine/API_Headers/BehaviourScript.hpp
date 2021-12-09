#ifndef BEHAVIOURSCRIPT_H_
#define BEHAVIOURSCRIPT_H_

#include "SpicHeader.hpp"
#include "Component.hpp"

namespace spic {

    class Collider;

    class SPIC_API BehaviourScript : public Component {
        public:
            /**
             * @brief Sent when another object enters a trigger collider
             *        attached to this object (2D physics only).
             */
            virtual void OnTriggerEnter2D(const Collider& collider) = 0;

            /**
             * @brief Sent when another object leaves a trigger collider
             *        attached to this object (2D physics only).
             */
            virtual void OnTriggerExit2D(const Collider& collider) = 0;

            /**
             * @brief Sent each frame where another object is within a trigger
             *        collider attached to this object (2D physics only).
             */
            virtual void OnTriggerStay2D(const Collider& collider) = 0;
    

            /**
             * @brief the action that has te be performed when a click event takes place
             */
            virtual void OnClick() = 0;
    };

}

#endif // BEHAVIOURSCRIPT_H_
