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

	/**
	* @brief Returns KeyCode if any key is SDL_KEYDOWN or SDL_KEYUP
	*/
	KeyCode PollEvent();
	KeyCode PollEvent1();

	/**
	* @brief Returns bool depending on key parameter if key is hold down.
	*/
	bool PollContinousEvent(const KeyCode& key);

	/**
	* @brief Returns bool depending on if key is hold down.
	*/
	bool PollContinousEvent();

	/**
	* @brief Returns true if any key is pressed
	*/
	bool AnyKeyPressed();

	/**
	* @brief Returns KeyCode translated from SDL
	*/
	KeyCode TranslateToEnum(const SDL_Event& sdlEvent) const;

};