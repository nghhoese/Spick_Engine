#include "../Facade_Headers/SceneFacade.hpp"
#include "../Facade_Headers/Exceptions/GraphicsExceptions.hpp"

using namespace spic;
WindowFacade::WindowFacade() : _window(nullptr, SDL_DestroyWindow), _renderer(nullptr, SDL_DestroyRenderer) {}

SDL_Texture* _texture;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* PlayerTex;
SDL_Rect srcR, destR;
int WindowFacade::create_renderer() {
	try {
		_renderer.reset(SDL_CreateRenderer(_window.get(), -1, 0));

		if (_renderer == NULL)
		{
			throw Exceptions::CannotCreateRenderer();
		}

		SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
		SDL_SetRenderDrawBlendMode(_renderer.get(), SDL_BLENDMODE_BLEND);
		SDL_Surface* tmpSurface = SDL_LoadBMP("C:\\Users\\Gebruiker\\Downloads\\player_sub-machinegun.bmp");
		_texture = SDL_CreateTextureFromSurface(_renderer.get(), tmpSurface);
		SDL_FreeSurface(tmpSurface);
		SDL_RenderCopy(_renderer.get(), _texture, NULL, &destR);
		SDL_RenderPresent(_renderer.get());
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
	//_window_height = height;
	//_window_width = width;
	//set_scene_size(height, width);
	//try {
	//	if (SDL_Init(SDL_INIT_VIDEO) < NULL) {
	//		throw Exceptions::SDLInitFailed();
	//	}

	//	_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0));

	//	if (_window == NULL) {
	//		throw Exceptions::CannotCreateWindow();
	//	}

	//	return 1;
	//}
	//catch (Exceptions::SDLInitFailed& e) {
	//	std::cout << e.get() << std::endl;
	//	return NULL;
	//}
	//catch (Exceptions::TTFInitFailed& e) {
	//	std::cout << e.get() << std::endl;
	//	return NULL;
	//}
	//catch (Exceptions::CannotCreateWindow& e) {
	//	std::cout << e.get() << std::endl;
	//	return NULL;
	//}
	int flags = 0;



	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow("testgame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		}


	}
	destR.h = 50;
	destR.w = 50;

	SDL_Surface* tmpSurface = SDL_LoadBMP("C:\\Users\\Gebruiker\\Downloads\\player_sub-machinegun.bmp");
	PlayerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, PlayerTex, NULL, &destR);

	SDL_RenderPresent(renderer);
	while (true) {

	}
}

void WindowFacade::destroy() {
	//Quit SDL subsystems
	SDL_Quit();
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

void spic::WindowFacade::ClearRender()
{
	SDL_RenderClear(_renderer.get());
}

void spic::WindowFacade::Render()
{
	SDL_RenderPresent(_renderer.get());
}
