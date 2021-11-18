#include "..\Facade_Headers\ImageFacade.hpp"
#include <SDL_image.h>
#include <iostream>
#pragma warning(disable : 4996)

spic::ImageFacade::ImageFacade()
{
	
}

void spic::ImageFacade::Createtexture(SDL_Renderer* renderer)
{
	char* a = new char[_path.size() + 1];
	strcpy(a, _path.c_str());
	tmpSurface = IMG_Load(a);
	_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	delete[] a;
}

void spic::ImageFacade::Render(SDL_Renderer* renderer)
{
	//SDL_RenderCopy(renderer, _texture, NULL, &destR);
	if (this->rotation < -361) {
		this->rotation = 0;
	}
	SDL_Point size;
	SDL_QueryTexture(_texture, NULL, NULL, &size.x, &size.y);
	if (this->scale <= 0) {
		destR.w = size.x;
		destR.h = size.y;
	}
	else {
		destR.w = size.x * scale;
		destR.h = size.y * scale;
	}
	SDL_RenderCopyEx(renderer, _texture, NULL, &destR, this->rotation, NULL, SDL_FLIP_NONE);
	SDL_DestroyTexture(_texture);


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

void spic::ImageFacade::setPath(std::string path)
{
	_path = path;
}

void spic::ImageFacade::setRotation(double rotation)
{
	this->rotation = rotation;
}

void spic::ImageFacade::setScale(double scale)
{
	this->scale = scale;
}
