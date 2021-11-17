#ifndef TEXT_H_
#define TEXT_H_

#include "UIObject.hpp"
#include "Color.hpp"
#include <string>
#include "Scene.hpp"
#include "../Facade_Headers/TextFacade.hpp"

namespace spic {

    /**
     * @brief Enumeration for different text alignments.
     */
    enum class Alignment {
        left,
        center,
        right
    };

    /**
     * @brief Class representing a piece of text which can be rendered.
     */
    class Text : public UIObject {

    public:

        SPIC_API Text();
        /**
         * @brief Get text.
         * @return text.
         */
        const std::string& GetText() const { return text; }

        /**
         * @brief Set text.
         */
        void SetText(const std::string& text) { this->text = text; }

        /**
         * @brief Get font.
         * @return font.
         */
        const std::string& GetFont() const { return font; }

        /**
         * @brief Set font.
         */
        void SetFont(const std::string& font) { this->font = font; }

        /**
         * @brief Get size.
         * @return size.
         */
        int GetSize() const { return size; }

        /**
         * @brief Set size.
         */
        void SetSize(int size) { this->size = size; }

        /**
         * @brief Get alignment.
         * @return alignment.
         */
        const Alignment& GetAlignment() const { return alignment; }

        /**
         * @brief Set alignment.
         */
        void SetAlignment(const Alignment& alignment) { this->alignment = alignment; }

        /**
         * @brief Get color.
         * @return color.
         */
        const Color& GetColor() const { return color; }

        /**
         * @brief Set color.
         */
        void SetColor(const Color& color) { this->color = color; }

        void OnRender();
        void Render();

    private:
        std::string text;
        std::string font;
        int size;
        Alignment alignment;
        Color color;

    };

}

#endif // TEXT_H_
