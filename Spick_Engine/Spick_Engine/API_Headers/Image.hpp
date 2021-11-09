#ifndef IMAGE_H_
#define IMAGE_H_

#include "UIObject.hpp"
#include "Color.hpp"
#include "Sprite.hpp"

namespace spic {

    /**
     * @brief Class representing an image which can be rendered.
     */
    class Image : public UIObject {
    
    public:
        /**
         * @brief Get sprite.
         * @return sprite.
         */
        const Sprite& GetSprite() const { return sprite; }

        /**
         * @brief Set sprite.
         */
        void SetSprite(const Sprite& sprite) { this->sprite = sprite; }

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
        Sprite sprite;
        Color color;

    };

}

#endif // IMAGE_H_