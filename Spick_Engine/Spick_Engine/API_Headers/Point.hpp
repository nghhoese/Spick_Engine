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

        void Sub(Point num) { x -= num.x; y -= num.y; };
        void Sub(int num) { x -= num; y -= num; };
        void Sub(Point point1, Point point2) {
            x = (point1.x - point2.x);
            y = (point1.y - point2.y);
        };

        void Mult(Point scalair) { x *= scalair.x; y *= scalair.y; };
        void Mult(int scalair) { x *= scalair; y *= scalair; };

        void Add(Point num) { x += num.x; y += num.y; };
        void Add(int num) { x += num; y += num; };

        double Mag() {
            return sqrt(x * x + y * y);
        };

        double Dot(Point p) {
            return (p.x * x + p.y + y);
        }

        void SetMag(double newMag) {
            double magnitude = Mag();
            x = x * newMag / magnitude;
            y = y * newMag / magnitude;
        }

        void Limit(double max) {
            auto normalized = Normalize();
            auto magnitude = Mag();
            normalized.Mult((magnitude - max));
            x = normalized.x;
            y = normalized.y;
        }

        Point Normalize() {
            double magnitude = Mag();
            Point normalized;
            normalized.x = x / magnitude;
            normalized.y = y / magnitude;
            return normalized;
        }
    };
}

#endif // POINT_H_
