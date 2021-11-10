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
