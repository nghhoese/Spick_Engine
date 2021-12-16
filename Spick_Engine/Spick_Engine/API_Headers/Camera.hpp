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
    class Camera : public GameObject {
    public:

        /**
        * @brief Constructor.
        */
        SPIC_API Camera(const std::string& name);

        /**
        * @brief Create camera.
        */
        SPIC_API void CreateCamera();

        /**
        * @brief Set camera.
        */
        SPIC_API void SetCamera();

        /**
        * @brief Get the camera.
        * @return rectangle which represents the camera.
        */
        SPIC_API Rectangle* GetCamera();

        /**
        * @brief Update the camera.
        */
        SPIC_API void UpdateCamera();

        /**
        * @brief Calls the render.
        */
        SPIC_API void Render();

        /**
        * @brief Set aspect width.
        */
        SPIC_API void setAspectWidth(const int& aspectWidth);

        /**
        * @brief get aspect width.
        * @return the width (double).
        */
        SPIC_API const double& getAspectWidth();

        /**
        * @brief Set aspect height.
        */
        SPIC_API void setAspectHeight(const int& aspectHeight);

        /**
        * @brief Get aspect height.
        * @return the height (double).
        */
        SPIC_API const double& getAspectHeight();

        /**
        * @brief Set aspect height.
        */
        SPIC_API void setColor(const Color& color);

        /**
        * @brief Get color.
        * @return the color (Color).
        */
        SPIC_API const Color& getColor();

        /**
        * @brief Set X.
        */
        SPIC_API void setX(const double& x);

        /**
        * @brief Get X.
        * @return the X (double).
        */
        SPIC_API const double& getX();

        /**
        * @brief Set Y.
        */
        SPIC_API void setY(const double& y);

        /**
        * @brief Get Y.
        * @return the Y (double).
        */
        SPIC_API const double& getY();

        /**
        * @brief Set the camera name.
        */
        SPIC_API void setCameraName(const std::string& name);

        /**
        * @brief Get the camera name.
        * @return the camera name (string).
        */
        SPIC_API const std::string& getCameraName();

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
