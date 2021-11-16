#include "..\Facade_Headers\ImageFacade.hpp"
#include <SDL_image.h>
#pragma warning(disable : 4996)
spic::ImageFacade::ImageFacade(std::string path, int width, int height)
{
	destR.h = width;
	destR.w = height;
	_path = path;
}

void spic::ImageFacade::Createtexture(SDL_Renderer* renderer)
{
	char* a = new char[_path.size() + 1];
	strcpy(a, _path.c_str());
	SDL_Surface* tmpSurface = SDL_LoadBMP(a);
	_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void spic::ImageFacade::Render(SDL_Renderer* renderer)
{

	SDL_RenderCopy(renderer, _texture, NULL, &destR);


}

void spic::ImageFacade::setPosition(int x, int y)
{
	destR.x = x;
	destR.y = y;
}

void spic::ImageFacade::setSize(int width, int height)
{
	destR.h = height;
	destR.w = width;
}
