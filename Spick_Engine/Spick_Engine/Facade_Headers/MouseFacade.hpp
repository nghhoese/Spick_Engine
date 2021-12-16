#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "../API_Headers/MouseButton.hpp"
#include <tuple>

using namespace spic;

class MouseFacade {
private:
	SDL_Event sdlEvent;
public:
	MouseFacade();
	MouseButton PollEvent();
	bool PollContinousEvent();
	std::tuple<int, int> PollMousePosition() const;
	bool AnyKeyPressed();
	bool GetMouseButton(int which);
	bool GetMouseButtonDown(int which);
	bool GetMouseButtonUp(int which);
};