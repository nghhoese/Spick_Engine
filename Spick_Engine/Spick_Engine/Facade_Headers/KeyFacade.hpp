#pragma once

#include <SDL.h>
#include "../API_Headers/Input.hpp"
using namespace spic;

class KeyFacade {
private:
	SDL_Event sdlEvent;
public:
	KeyFacade();
	Input::KeyCode pollEvent();
	Input::KeyCode translate_to_enum(const SDL_Event& sdlEvent) const;
};