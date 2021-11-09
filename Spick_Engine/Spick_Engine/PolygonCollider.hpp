#ifndef POLYGONCOLLIDER_H_
#define POLYGONCOLLIDER_H_

#include "Collider.hpp"

namespace spic {

    /**
     * @brief A collider which represents a polygon collision area.
     */
    class PolygonCollider : public Collider {
    public:
        /**
         * @brief Getter of the points where the collider is made of.
         * @return The polygon points
         */
        const std::vector<Point>& GetPoints() const { return points; }

        /**
         * @brief Setter for the points where the collider is made of.
         * @param points where the collider is made of.
         */
        void SetPoints(std::vector<Point>& points) { this->points = points; }

    private:
        std::vector<Point> points;
    };

}

#endif // POLYGONCOLLIDER_H_
