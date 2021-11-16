#pragma once
#include "../Facade_Headers/TextureFacade.hpp"
#include "../API_Headers/Color.hpp"
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

struct SDL_Renderer

namespace spic {
	class TextFacade : public TextureFacade {
	private:
		/**
		* \brief The text of the TextFacade
		*/
		const std::string _text;

		/**
		* \brief The Color of the TextFacade
		*/
		const Color& _color;

		/**
		* \brief The height of the TextFacade
		*/
		float _height;
	public:
		TextFacade(const std::string& path, const std::string& text, const Color& color, float height, int opacity);

		/**
		* \brief Creates a SDL_Texture
		*/
		void create_texture(std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>& renderer);
	};
}