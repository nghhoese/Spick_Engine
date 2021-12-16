#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <tuple>
#include <map>
#include <iostream>

struct SDL_Window;
struct SDL_Renderer;

namespace spic {

	class WindowFacade {
	private:
		std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;
		float _window_height;
		float _window_width;
		std::tuple<float, float> _camera_pos;
		std::tuple<float, float> _scene_size;
		WindowFacade() : _window(nullptr, SDL_DestroyWindow), _renderer(nullptr, SDL_DestroyRenderer) {};
	public:
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;
		static WindowFacade* GetInstance();
		int create_renderer();
		uint32_t get_ticks();
		int create_window(const std::string& title, float height, float width);
		void destroy();
		void set_camera_pos(float x, float y);
		std::tuple<float, float> get_camera_pos() const;
		void set_scene_size(float height, float width);
		std::tuple<float, float> get_scene_size() const;
		void ClearRender();
		void Render();
		void SetDelay(const int ms);
	};
}