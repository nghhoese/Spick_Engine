#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Point.hpp"

namespace spic {

    /**
    * @brief Instances of this class represent specific 2D transformations.
    */
    struct SPIC_API Transform {
        Point position; 
        double rotation;
        double scale; 
    };
}

#endif // TRANSFORM_H_
