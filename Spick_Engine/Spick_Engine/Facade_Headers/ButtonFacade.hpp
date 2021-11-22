#pragma once

#include <SDL.h>
#include <string>
#include <iostream>
#include "../API_Headers/SpicHeader.hpp"
#include "../Facade_Headers/MouseFacade.hpp"
#include "../API_Headers/Point.hpp"
#include "../API_Headers/Importation.hpp"
#include <SDL_image.h>

namespace spic {
	
	enum ButtonState {NORMAL=0, HOVER=1, PRESSED=2};
	
	/**
	 * @brief Button represents a clickeable gameobject
	 */
	class ButtonFacade {
	public:
		SPIC_API ButtonFacade(int x, int y, int w, int h, std::string asset);
		void Render(SDL_Renderer* renderer);
		void handle_events();
		void CreateTexture(SDL_Renderer* renderer);
	private:
		SDL_Rect box;
		SDL_Rect* clip;
		SDL_Texture* _texture;
		std::string _asset;
	};
}