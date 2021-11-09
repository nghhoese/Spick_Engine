#ifndef COLLIDER2D_H_
#define COLLIDER2D_H_

#include "Component.hpp"

namespace spic {

    /**
     * @brief The base class for all colliders.
     */
    class Collider : public Component {

        /**
         * @brief Getter for isTrigger status.
         * @return true if isTrigger, false otherwise.
         */
        bool IsTrigger() const { return isTrigger; }

        /**
         * @brief flag New isTrigger status.
         */
        void IsTrigger(bool flag) { isTrigger = flag; }
        
    private:
        /**
         * @brief isTrigger status
         */
        bool isTrigger;

    };

}

#endif // COLLIDER2D_H_
