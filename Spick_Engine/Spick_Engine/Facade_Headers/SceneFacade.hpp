#pragma once
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
		/**
		* \brief An instance of SDL_Window with a custom destructor
		*/
		std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;

		/**
		* \brief An instance of SDL_Renderer with a custom destructor
		*/
		

		/**
		* \brief The height of the Window
		*/
		float _window_height;

		/**
		* \brief The width of the Window
		*/
		float _window_width;

		/**
		* \brief The camera position of the Window
		* The standard position of the camera is 0,0
		* \return std::tuple<width, height>
		*/
		std::tuple<float, float> _camera_pos;


		/**
		* \brief The width and height of the Scene
		* \return std::tuple<width, height>
		*/
		std::tuple<float, float> _scene_size;
		WindowFacade() : _window(nullptr, SDL_DestroyWindow), _renderer(nullptr, SDL_DestroyRenderer) {};

	public:
		
		std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;
		/**
		* \brief Creates the instance of SDL_Renderer
		*/
		static WindowFacade* GetInstance();
		int create_renderer();

		/**
		* \brief Returns the timer ticks
		*/
		uint32_t get_ticks();

		/**
		* \brief Creates the instance of SDL_Window
		*/
		int create_window(const std::string& title, float height, float width);

		/**
		* brief Destroys the SDL_Window
		*/
		void destroy();

		/**
		* brief Updates camera position
		*/
		void set_camera_pos(float x, float y);

		/**
		* brief Returns camera position
		*/
		std::tuple<float, float> get_camera_pos() const;

		/**
		* brief Sets scene size
		*/
		void set_scene_size(float height, float width);

		/**
		* brief Returns scene size
		*/
		std::tuple<float, float> get_scene_size() const;
		void ClearRender();
		void Render();

		/**
		* @brief Set delay to limit the gamespeed to specific maxFPS
		*/
		void SetDelay(const int ms);
	};
}