#include "../Facade_Headers/SceneFacade.hpp"
#include "../Facade_Headers/Exceptions/GraphicsExceptions.hpp"

using namespace spic;
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

		//Initialize SDL_ttf
		if (TTF_Init() == -1)
		{
			throw Exceptions::TTFInitFailed();
		}

		_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN));

		if (_window == NULL) {
			throw Exceptions::CannotCreateWindow();
		}

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
	TTF_Quit();
}

void WindowFacade::set_camera_pos(float x, float y) {
	float _scene_width = std::get<0>(_scene_size);
	float _scene_height = std::get<1>(_scene_size);
	if (x + _window_width < _scene_width && x >= 0) {

		std::get<0>(_camera_pos) = x;
	}
	else if (x + _window_width > _scene_width) {
		std::get<0>(_camera_pos) = _scene_width - _window_width;
	}
	else if (x < 0) {
		std::get<0>(_camera_pos) = 0;
	}

	int converted_y = _scene_height - (_window_height + y);
	if (converted_y + _window_height < _scene_height && converted_y >= 0) {
		std::get<1>(_camera_pos) = converted_y;
	}
	else if (converted_y + _window_height > _scene_height) {
		std::get<1>(_camera_pos) = _scene_height - _window_height;
	}
	else if (converted_y < 0) {
		std::get<1>(_camera_pos) = 0;
	}
}

std::tuple<float, float> WindowFacade::get_camera_pos() const {
	std::tuple<int, int> converted_camera_pos = _camera_pos;
	std::get<1>(converted_camera_pos) = std::get<1>(_scene_size) - std::get<1>(converted_camera_pos) - _window_height;
	return converted_camera_pos;
}

void WindowFacade::set_scene_size(float height, float width) {
	std::get<1>(_scene_size) = height;
	std::get<0>(_scene_size) = width;

	std::get<0>(_camera_pos) = 0;
	std::get<1>(_camera_pos) = height - _window_height;
}

std::tuple<float, float> WindowFacade::get_scene_size() const {
	return _scene_size;
}