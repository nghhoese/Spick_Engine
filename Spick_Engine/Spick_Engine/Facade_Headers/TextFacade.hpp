#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "../API_Headers/SpicHeader.hpp"

namespace spic {

	/**
	 * @brief Text represents an image with a text(string) in a font
	 */
	class TextFacade {
	public:
		SPIC_API TextFacade(std::string text, std::string fontPath);
		void Render(SDL_Renderer* renderer);
		void Createtexture(SDL_Renderer* renderer);
		void setPosition(int x, int y);
		

	private:  
		TTF_Font* _font;
		std::string _text;
		SDL_Texture* _texture;
		SDL_Rect destRectangle;

	};
}