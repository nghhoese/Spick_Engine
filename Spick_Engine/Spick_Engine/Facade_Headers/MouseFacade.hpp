#pragma once

#include <SDL.h>
#include "../API_Headers/Input.hpp"
#include <tuple>
using namespace spic;

class MouseFacade {
private:
	SDL_Event sdlEvent;
public:
	MouseFacade();
	Input::MouseButton PollEvent();
	bool PollContinousEvent();
	std::tuple<int, int> PollMousePosition() const;
	bool AnyKeyPressed();
};