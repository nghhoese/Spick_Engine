#pragma once

#include <SDL.h>
#include "../API_Headers/Input.hpp"
#include <iostream>
using namespace spic;

class KeyFacade {
private:
	SDL_Event sdlEvent;
public:
	KeyFacade();
	Input::KeyCode PollEvent();
	bool PollContinousEvent(const Input::KeyCode& key);
	bool PollContinousEvent();
	Input::KeyCode TranslateToEnum(const SDL_Event& sdlEvent) const;
	bool GetKeyDown(const Input::KeyCode& key) const;
	bool GetKeyUp(const Input::KeyCode& key) const;


};