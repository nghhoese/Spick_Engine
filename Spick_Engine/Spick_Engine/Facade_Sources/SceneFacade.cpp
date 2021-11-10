#include "../Facade_Headers/SceneFacade.hpp"
#include "../Facade_Headers/Exceptions/GraphicsExceptions.hpp"

WindowFacade::WindowFacade() : _window(nullptr, SDL_DestroyWindow), _renderer(nullptr, SDL_DestroyRenderer) {}

int WindowFacade::create_renderer() {
	try {
		_renderer.reset(SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED));

		if (_renderer == NULL)
		{
			throw Exceptions::CannotCreateRenderer();
		}

		SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);

		return 1;
	}
	catch (Exceptions::CannotCreateRenderer e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
}

uint32_t WindowFacade::get_ticks() {
	return SDL_GetTicks();
}

int WindowFacade::create_window(const std::string& title, float height, float width) {
	_window_height = height;
	_window_width = width;
	set_scene_size(height, width);
	try {
		if (SDL_Init(SDL_INIT_VIDEO) < NULL) {
			throw Exceptions::SDLInitFailed();
		}

		//Initialize SDL_ttf -> text font
		//if (TTF_Init() == -1)
		//{
		//	throw Exceptions::TTFInitFailed();
		//}

		_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));

		if (_window == NULL) {
			throw Exceptions::CannotCreateWindow();
		}

		// Animator of hier?
		//_fps = std::make_unique<Fps>();
		// ?
		//_timer = std::make_shared<Timer>();
		return 1;
	}
	catch (Exceptions::SDLInitFailed& e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
	catch (Exceptions::TTFInitFailed& e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
	catch (Exceptions::CannotCreateWindow& e) {
		std::cout << e.get() << std::endl;
		return NULL;
	}
}

void WindowFacade::destroy() {
	//Quit SDL subsystems
	SDL_Quit();
	//TTF_Quit(); text font
}

int WindowFacade::get_fps() {
	//return _fps->get();
	return 0;
}

void WindowFacade::set_camera_pos(float x, float y) {
}

std::tuple<float, float> WindowFacade::get_camera_pos() const {
	return std::tuple<float, float>();
}

void WindowFacade::set_scene_size(float height, float width) {
	std::get<1>(_scene_size) = height;
	std::get<0>(_scene_size) = width;

	std::get<0>(_camera_pos) = 0;
	std::get<1>(_camera_pos) = height - _window_height;
}

std::tuple<float, float> WindowFacade::get_scene_size() const {
	return std::tuple<float, float>();
}
