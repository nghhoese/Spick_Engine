#pragma once

#include <SDL.h>
#include "../API_Headers/Input.hpp"
using namespace spic;

class MouseFacade {
private:
	SDL_Event sdlEvent;
public:
	MouseFacade();
	Input::MouseButton pollEvent();
};