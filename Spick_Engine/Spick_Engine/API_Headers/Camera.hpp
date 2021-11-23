#ifndef CAMERA_H_
#define CAMERA_H_

#include "GameObject.hpp"
#include "Color.hpp"
#include "Rectangle.hpp"
#include "SpicHeader.hpp"

namespace spic {

    /**
     * @brief Class representing a point of view towards the game scene.
     */
    class SPIC_API Camera : public GameObject {
    public:
        Camera(const std::string& name);

        void CreateCamera();
        void SetCamera();
        Rectangle* GetCamera();
        void UpdateCamera();
        void Render();

        void setAspectWidth(const int& aspectWidth);
        const double& getAspectWidth();
        void setAspectHeight(const int& aspectHeight);
        const double& getAspectHeight();
        void setColor(const Color& color);
        const Color& getColor();
        void setX(const double& x);
        const double& getX();
        void setY(const double& y);
        const double& getY();
        void setCameraName(const std::string& name);
        const std::string& getCameraName();

    private:
        Rectangle* camera;
        std::string name;
        Color backgroundColor;
        double x;
        double y;
        double aspectWidth;
        double aspectHeight;
    };
}

#endif // CAMERA_H_
