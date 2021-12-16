#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include "../API_Headers/KeyCode.hpp"

using namespace spic;

class KeyFacade {
private:
	SDL_Event sdlEvent;
public:
	KeyFacade();
	KeyCode PollEvent();
	KeyCode PollEvent1();
	bool PollContinousEvent(const KeyCode& key);
	bool PollContinousEvent();
	bool AnyKeyPressed();
	KeyCode TranslateToEnum(const SDL_Event& sdlEvent) const;
};