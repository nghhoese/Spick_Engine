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

        SPIC_API Text(const std::string& text, const std::string& font, const int& size, const Color& color, int x, int y);
        /**
         * @brief Get text.
         * @return text.
         */
        const std::string& GetText() const { return _text; }

        /**
         * @brief Set text.
         */
        void SetText(const std::string& text) { this->_text = text; }

        /**
         * @brief Get font.
         * @return font.
         */
        const std::string& GetFont() const { return _font; }

        /**
         * @brief Set font.
         */
        void SetFont(const std::string& font) { this->_font = font; }

        /**
         * @brief Get size.
         * @return size.
         */
        int GetSize() const { return _size; }

        /**
         * @brief Set size.
         */
        void SetSize(int size) { this->_size = size; }

        /**
         * @brief Get alignment.
         * @return alignment.
         */
        const Alignment& GetAlignment() const { return _alignment; }

        /**
         * @brief Set alignment.
         */
        void SetAlignment(const Alignment& alignment) { this->_alignment = alignment; }

        /**
         * @brief Get color.
         * @return color.
         */
        const Color& GetColor() const { return _color; }

        /**
         * @brief Set color.
         */
        void SetColor(const Color& color) { this->_color = color; }

        void Render();

    private:
        std::string _text;
        std::string _font;
        int _size;
        Alignment _alignment;
        Color _color;
        int _x;
        int _y;

    };

}

#endif // TEXT_H_
