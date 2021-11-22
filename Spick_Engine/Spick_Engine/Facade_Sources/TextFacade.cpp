#include "..\Facade_Headers\TextFacade.hpp"

spic::TextFacade::TextFacade(std::string text, std::string font, int size, Color color, int x, int y) {
	std::string fp = "Fonts/" + font + ".ttf";
	_font = TTF_OpenFont(fp.c_str(), size);
	_text = "Banaan";
	_color.r = color.GetR() * 255;
	_color.g = color.GetG() * 255;
	_color.b = color.GetB() * 255;
	_color.a = color.GetA() * 255;
	_x = x;
	_y = y;
}

void spic::TextFacade::Createtexture(SDL_Renderer* renderer) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(_font, _text.c_str(), _color);
	_texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	destRectangle.x = _x;
	destRectangle.y = _y;
	SDL_QueryTexture(_texture, NULL, NULL, &destRectangle.w, &destRectangle.h);
	SDL_FreeSurface(textSurface);
}

void spic::TextFacade::Render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, _texture, NULL, &destRectangle);
	SDL_DestroyTexture(_texture);
	TTF_CloseFont(_font);
}

void spic::TextFacade::setValues(std::string& text, std::string& font, int& size, Color& color, int& x, int& y) {
	std::string fp = "Fonts/" + font + ".ttf";
	_font = TTF_OpenFont(fp.c_str(), size);
	_text = text;
	_color.r = color.GetR() * 255;
	_color.g = color.GetG() * 255;
	_color.b = color.GetB() * 255;
	_color.a = color.GetA() * 255;
	_x = x;
	_y = y;
}