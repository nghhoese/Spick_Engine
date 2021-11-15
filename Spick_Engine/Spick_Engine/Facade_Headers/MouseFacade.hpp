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

	/**
	* @brief Returns bool depending on if mouse is pressed down.
	*/
	MouseButton PollEvent();

	/**
	* @brief Returns bool depending on if mouse is hold down.
	*/
	bool PollContinousEvent();

	/**
	* @brief Returns tuple with mouse coordinates
	*/
	std::tuple<int, int> PollMousePosition() const;

	/**
	* @brief Returns true if any key is pressed
	*/
	bool AnyKeyPressed();

	/**
	 * @brief Returns whether the given mouse button is held down.
	 */
	bool GetMouseButton(int which);

	/**
	* @brief Returns true if given mousebutton is pressed
	*/
	bool GetMouseButtonDown(int which);

	/**
	* @brief Returns true if given mousebutton is released
	*/
	bool GetMouseButtonUp(int which);

};