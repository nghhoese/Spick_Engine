#pragma once

#include <SDL.h>
#include "../API_Headers/Rectangle.hpp"

class CameraFacade {
public:
	SDL_Rect camera;
	void createRectangle(const double& x, const double& y, const double& width, const double& height);
	const spic::Rectangle& getRectangle();
};