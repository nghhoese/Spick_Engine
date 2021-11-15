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

	/**
	* @brief Returns KeyCode if any key is SDL_KEYDOWN or SDL_KEYUP
	*/
	KeyCode PollEvent();

	/**
	* @brief Returns bool depending on key parameter if key is hold down.
	*/
	bool PollContinousEvent(const KeyCode& key);

	/**
	* @brief Returns bool depending on if key is hold down.
	*/
	bool PollContinousEvent();

	/**
	* @brief Returns KeyCode translated from SDL
	*/
	KeyCode TranslateToEnum(const SDL_Event& sdlEvent) const;

};