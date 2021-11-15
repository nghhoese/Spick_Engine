#ifndef POINT_H_
#define POINT_H_

#include "SpicHeader.hpp"

namespace spic {

    /**
     * @brief Struct representing both a 2D point and a 2D vector.
     */
    struct SPIC_API Point {
        double x;
        double y;
    };

}

#endif // POINT_H_
