#pragma once

#include <SDL.h>
#include "../API_Headers/Rectangle.hpp"

class CameraFacade {
private:
	
public:
	SDL_Rect sdl_rectangle;
	void CreateRectangle(const double& x, const double& y, const double& width, const double& height);
	void ConvertToRectangle(spic::Rectangle* rectangle);
	void UpdateCamera(const double& x, const double& y);
};