#ifndef POINT_H_
#define POINT_H_

#include "SpicHeader.hpp"
#include <math.h>


namespace spic {

    /**
    * @brief Struct representing both a 2D point and a 2D vector.
    */
    struct SPIC_API Point {
    public:

        double x;
        double y;

        /**
        * @brief Substract x and y with a point.
        */
        void Sub(Point num) { x = x - (num.x); y = y - (num.y); };

        /**
        * @brief Substract x and y with a integer.
        */
        void Sub(int num) { x = x - (num); y = y - (num); };

        /**
        * @brief Substract two points.
        */
        void Sub(Point point1, Point point2) {
            x = (point1.x - point2.x);
            y = (point1.y - point2.y);
        };

        /**
        * @brief Multiply x and y with a point.
        */
        void Mult(Point scalair) { x = scalair.x * x; y = scalair.y * y; };

        /**
        * @brief Multiply x and y with a integer.
        */
        void Mult(int scalair) { x = scalair * x; y = scalair * y; };

        /**
        * @brief Add to x and y with a point.
        */
        void Add(Point num) { x = x + (num.x); y = y + (num.y); };

        /**
        * @brief Add to x and y with a integer.
        */
        void Add(int num) { x = x + (num); y = y + (num); };

        /**
        * @brief Get magnitude.
        */
        double Mag() {
            return sqrt(x * x + y * y);
        };

        /**
        * @brief Calculates the product of two vectors.
        */
        double Dot(Point p) {
            return (p.x * x + p.y + y);
        }

        /**
        * @brief Set magnitude.
        */
        void SetMag(double newMag) {
            double magnitude = Mag();
            x = x * newMag / magnitude;
            y = y * newMag / magnitude;
        }

        /**
        * @brief Limit the magnitude of this vector to the max value.
        */
        void Limit(double max) {
            x = x / max;
            y = y / max;
        }

        /**
        * @brief Normalize X and Y.
        */
        Point Normalize() {
            double magnitude = Mag();
            Point normalized;
            normalized.x = x / magnitude;
            normalized.y = y / magnitude;
            return normalized;
        }

    private:

    };
}

#endif // POINT_H_
