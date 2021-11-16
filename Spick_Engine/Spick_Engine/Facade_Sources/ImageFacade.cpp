#include "..\Facade_Headers\ImageFacade.hpp"
#include <SDL_image.h>

spic::ImageFacade::ImageFacade(std::string path, int width, int height)
{
	destR.h = 50;
	destR.w = 50;
	_path = path;
}

void spic::ImageFacade::Createtexture(SDL_Renderer* renderer)
{
	SDL_Surface* tmpSurface = IMG_Load("C:/Spic/player_sub-machinegun.png");
	_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void spic::ImageFacade::Render(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, _texture, NULL, &destR);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 240);

	SDL_RenderPresent(renderer);
}
