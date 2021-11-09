#include "../Facade_Headers/MouseFacade.hpp"

MouseFacade::MouseFacade() {

}

Input::MouseButton MouseFacade::pollEvent() {
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
