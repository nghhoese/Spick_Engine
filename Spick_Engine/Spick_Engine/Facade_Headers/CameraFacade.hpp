#pragma once

#include <SDL.h>
#include "Rectangle/Rectangle.hpp"

class CameraFacade {
public:
	SDL_Rect camera;
	void createRectangle(const int& width, const int& height);
	const Rectangle& getRectangle();
};