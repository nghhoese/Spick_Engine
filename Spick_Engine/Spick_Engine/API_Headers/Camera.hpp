#ifndef CAMERA_H_
#define CAMERA_H_

#include "GameObject.hpp"
#include "Color.hpp"
#include "../Facade_Headers/Rectangle/Rectangle.hpp"

namespace spic {

    /**
     * @brief Class representing a point of view towards the game scene.
     */
    class Camera : public GameObject {
    public:
        Camera(const std::string& name);

        void createRectangle(const int& aspectWidth, const int& aspectHeight);
        const Rectangle& getRectangle();

        void setAspectWidth(const int& aspectWidth);
        const double& getAspectWidth();
        void setAspectHeight(const int& aspectHeight);
        const double& getAspectHeight();
        void setColor(const Color& color);
        const Color& getColor();

        private:
            Color backgroundColor;
            double aspectWidth;
            double aspectHeight;
    };
}

#endif // CAMERA_H_
