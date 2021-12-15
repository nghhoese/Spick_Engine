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

        void Sub(Point num) { x = x - (num.x); y = y - (num.y); };
        void Sub(int num) { x = x - (num); y = y - (num); };
        void Sub(Point point1, Point point2) {
            x = (point1.x - point2.x);
            y = (point1.y - point2.y);
        };

        void Mult(Point scalair) { x = scalair.x * x; y = scalair.y * y; };
        void Mult(int scalair) { x = scalair * x; y = scalair * y; };

        void Add(Point num) { x = x + (num.x); y = y + (num.y); };
        void Add(int num) { x = x + (num); y = y + (num); };

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
            x = x / max;
            y = y / max;
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
