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

		_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 800, 0));

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

void spic::WindowFacade::ClearRender()
{
	SDL_RenderClear(_renderer.get());
}

void spic::WindowFacade::Render()
{
	SDL_RenderPresent(_renderer.get());
}

int spic::WindowFacade::CalculateFPS()
{
	static const int NUM_SAMPLES = 10;
	static float frameTimes[NUM_SAMPLES];
	static int currentFrame = 0;

	static float prevTicks = get_ticks();

	float currentTicks;
	currentTicks = get_ticks();

	float frameTime = currentTicks - prevTicks;
	frameTimes[currentFrame % NUM_SAMPLES] = frameTime;

	prevTicks = currentTicks;

	int count;

	if (currentFrame < NUM_SAMPLES)
	{
		count = currentFrame;
	}
	else {
		count = NUM_SAMPLES;
	}

	float frameTimeAvarage = 0;
	for (int i = 0; i < count; i++)
	{
		frameTimeAvarage += frameTimes[i];
	}

	frameTimeAvarage /= count;
	float fps = 0;
	if (frameTimeAvarage > 0)
	{
		fps = 1000.0f / frameTimeAvarage;
	}
	else
	{
		fps = 60.0f;
	}
	currentFrame++;

	return fps;
}
