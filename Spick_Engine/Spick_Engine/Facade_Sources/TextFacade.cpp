#include "..\Facade_Headers\TextFacade.hpp"

spic::TextFacade::TextFacade(std::string text, std::string fontPath) {
	_font = TTF_OpenFont("Fonts/Capsmall.ttf", 20);
	_text = text;
	
}

void spic::TextFacade::Createtexture(SDL_Renderer* renderer) {
	SDL_Color color = { 144, 77, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(_font, "Potato", color);
	_texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	destRectangle.x = destRectangle.y = 0;
	SDL_QueryTexture(_texture, NULL, NULL, &destRectangle.w, &destRectangle.h);
	SDL_FreeSurface(textSurface);
}

void spic::TextFacade::Render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, _texture, NULL, &destRectangle);
	SDL_DestroyTexture(_texture);
}