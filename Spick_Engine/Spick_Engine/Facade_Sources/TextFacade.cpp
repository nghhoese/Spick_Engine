#include "../Facade_Headers/TextFacade.hpp"
#include "../Facade_Headers/Exceptions/GraphicsExceptions.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace spic;

TextFacade::TextFacade(const std::string& path, const std::string& text, const Color& color, const float height, int opacity) :
	ImageFacade(path, opacity), _text{ text }, _color{ color }, _height{ height } {}

void TextFacade::create_texture(std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>& renderer)
{
	try {
		//Open the font
		std::unique_ptr<TTF_Font, void(*)(TTF_Font*)> gFont = { TTF_OpenFont(_path.c_str(), _height), TTF_CloseFont };

		if (gFont == NULL)
		{
			throw Exceptions::CannotLoadFont();
		}

		//Render text surface
		std::unique_ptr<SDL_Surface, void(*)(SDL_Surface*)> loadedSurface = { TTF_RenderText_Solid(gFont.get(), _text.c_str(), { _color.red, _color.green, _color.blue }), SDL_FreeSurface };
		if (loadedSurface == NULL)
		{
			throw Exceptions::CannotLoadImage();
		}

		SDL_Texture* t = SDL_CreateTextureFromSurface(renderer.get(), loadedSurface.get());
		SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(t, _opacity);
		_texture.reset(t);

		if (_texture == NULL)
		{
			throw Exceptions::CannotCreateTexture();
		}
	}
	catch (Exceptions::TTFInitFailed& e) {
		std::cout << e.get() << std::endl;
	}
	catch (Exceptions::CannotLoadImage& e) {
		std::cout << e.get() << ": " << _path << std::endl;
	}
	catch (Exceptions::CannotCreateTexture& e) {
		std::cout << e.get();
	}
}