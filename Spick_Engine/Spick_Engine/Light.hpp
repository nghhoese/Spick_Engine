#ifndef LIGHT_H_
#define LIGHT_H_

#include "Component.hpp"
#include "Color.hpp"

namespace spic {

    /**
     * @brief The base class for all lights.
     */
    class Light : public Component {

    public:
        /**
         * @brief Get color.
         * @return color.
         */
        const Color& GetColor() const { return color; }

        /**
         * @brief Set color.
         */
        void SetColor(const Color& color) { this->color = color; }

    private:
        /**
         * @brief color
         */
        Color color;

    };

}

#endif // LIGHT_H_
