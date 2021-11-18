#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../API_Headers/SpicHeader.hpp"
#include "../API_Headers/Color.hpp"

namespace spic {

	/**
	 * @brief Text represents an image with a text(string) in a font
	 */
	class TextFacade {
	public:
		SPIC_API TextFacade(std::string text, std::string font, int size, Color color, int x, int y);
		void Render(SDL_Renderer* renderer);
		void Createtexture(SDL_Renderer* renderer);
		void setPosition(int x, int y);
		void setValues(std::string& text, std::string& font, int& size, Color& color, int& x, int& y);

	private:  
		TTF_Font* _font;
		std::string _text;
		SDL_Texture* _texture;
		SDL_Rect destRectangle;
		SDL_Color _color;
		int _x;
		int _y;

	};
}