#pragma once
#include <SDL.h>
//#include <SDL_ttf.h>
#include <SDL_image.h>
//#include "../Models/Sprite.h"
//#include "../Models/Text.h"
//#include "../Adapters/FlipEnumAdapter.h"
//#include <src/Time/Fps.h>
//#include <src/Time/Timer.h>
#include <tuple>
#include <map>
#include <iostream>

struct SDL_Window;
struct SDL_Renderer;

using namespace spic;

class WindowFacade {
private:
	/**
	* \brief Contains the fps of the Window
	*/
	//std::unique_ptr<Fps> _fps;

	/**
	* \brief Contains a timer object
	*/
	//std::shared_ptr<Timer> _timer;

	/**
	* \brief An instance of SDL_Window with a custom destructor
	*/
	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;

	/**
	* \brief An instance of SDL_Renderer with a custom destructor
	*/
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;

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

public:
	WindowFacade();

	/**
	* \brief Creates the instance of SDL_Renderer
	*/
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
	* \brief Creates a TextureFacade or adds an already created TextureFacade if Texture matches
	*/
	// Texture == Sprite?
	//void create_texture(const std::shared_ptr<Texture> texture, const std::shared_ptr<Texture> matching_texture);

	/**
	* brief Destroys the SDL_Window
	*/
	void destroy();

	/**
	* \brief Updates the window with all the sprites in the given list
	*/
	// Texture == Sprite?
	//void update_window(const std::vector<std::shared_ptr<Texture>> textures);

	/**
	* \brief Returns the fps of the Window
	*/
	int get_fps();

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

	/**
	* \brief Returns the timer
	*/
	//const std::shared_ptr<Time> get_timer() const;
};