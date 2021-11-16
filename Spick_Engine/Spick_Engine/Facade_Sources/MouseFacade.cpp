#include "../Facade_Headers/MouseFacade.hpp"

MouseFacade::MouseFacade() {

}

MouseButton MouseFacade::PollEvent() {
    if (SDL_PollEvent(&sdlEvent) != 0)
    {
		switch (sdlEvent.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
					return MouseButton::LEFT;
				}
				else if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
					return MouseButton::RIGHT;
				}
				else {
					return MouseButton::MIDDLE;
				}
		}
    }
}

bool MouseFacade::PollContinousEvent()
{
	int x, y;
	Uint32 buttons;

	SDL_PumpEvents();  // make sure we have the latest mouse state.

	buttons = SDL_GetMouseState(&x, &y);

	if (buttons)
	{
		if ((buttons & SDL_BUTTON_LMASK) != 0 || (buttons & SDL_BUTTON_RMASK) != 0 || (buttons & SDL_BUTTON_MMASK) != 0)
		{
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}

std::tuple<int, int> MouseFacade::PollMousePosition() const
{
	int x, y;
	Uint32 buttons;

	SDL_PumpEvents();  // make sure we have the latest mouse state.

	buttons = SDL_GetMouseState(&x, &y);
	return std::make_tuple(x, y);
}

bool MouseFacade::AnyKeyPressed()
{
	if (SDL_PollEvent(&sdlEvent) != 0)
	{
		if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
		{
			return true;
		}
	}
	return false;
}

bool MouseFacade::GetMouseButton(int which)
{
	int x, y;
	Uint32 buttons;

	SDL_PumpEvents();  // make sure we have the latest mouse state.

	buttons = SDL_GetMouseState(&x, &y);

	if ((buttons & SDL_BUTTON_LMASK) != 0 && which == 1)
	{
		return true;
	}
	else if ((buttons & SDL_BUTTON_RMASK) != 0 && which == 3)
	{
		return true;
	}
	else {
		return false;
	}
}

bool MouseFacade::GetMouseButtonDown(int which)
{
	if (SDL_PollEvent(&sdlEvent) != 0)
	{
		if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
		{
			if (which == 1 && sdlEvent.button.button == SDL_BUTTON_LEFT)
			{
				return true;
			}
			else if (which == 3 && sdlEvent.button.button == SDL_BUTTON_RIGHT)
			{
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

bool MouseFacade::GetMouseButtonUp(int which)
{
	if (SDL_PollEvent(&sdlEvent) != 0)
	{
		if (sdlEvent.type == SDL_MOUSEBUTTONUP)
		{
			if (which == 1 && sdlEvent.button.button == SDL_BUTTON_LEFT) 
			{
				return true;
			}
			else if (which == 3 && sdlEvent.button.button == SDL_BUTTON_RIGHT) 
			{
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}
