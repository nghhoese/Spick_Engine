#ifndef UIOBJECT_H_
#define UIOBJECT_H_

#include "GameObject.hpp"

namespace spic {

    /**
     * @brief Base class for a user interface object like Button or Text.
     */
    class UIObject : public GameObject {

    public:
        /**
         * @brief Get width.
         * @return width.
         */
        double GetWidth() const { return width; }

        /**
         * @brief Set width.
         */
        void SetWidth(double width) { this->width = width; }

        /**
         * @brief Get height.
         * @return height.
         */
        double GetHeight() const { return height; }

        /**
         * @brief Set height.
         */
        void SetWidth(double height) { this->height = height; }

    private:
        double width;
        double height;

    };

}

#endif // UIOBJECT_H_
