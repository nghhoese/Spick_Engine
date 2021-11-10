#include "../Facade_Headers/MouseFacade.hpp"

MouseFacade::MouseFacade() {

}

Input::MouseButton MouseFacade::PollEvent() {
    if (SDL_PollEvent(&sdlEvent) != 0)
    {
		switch (sdlEvent.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
					return Input::MouseButton::LEFT;
				}
				else if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
					return Input::MouseButton::RIGHT;
				}
				else {
					return Input::MouseButton::MIDDLE;
				}
		}
    }
}

bool MouseFacade::PollContinousEvent()
{
	if (SDL_GetMouseState(NULL, NULL))
	{
		if (SDL_BUTTON(1) != NULL)
		{
			return true;
		}
		else if (SDL_BUTTON(2) != NULL)
		{
			return true;
		} 
		else if(SDL_BUTTON(3) != NULL)
		{
			return true;
		}
		return false;
	}
}

std::tuple<int, int> MouseFacade::PollMousePosition() const
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return std::make_tuple(x, y);
}

bool MouseFacade::AnyKeyPressed()
{
	if (SDL_PollEvent(&sdlEvent) != 0)
	{
		if (sdlEvent.type != NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
