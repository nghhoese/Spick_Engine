#include "../API_Headers/Engine.hpp"

spic::Engine::Engine() {
	running = false;
	playing = false;
	tiledFacade = std::make_shared<TiledFacade>();
}

SPIC_API void spic::Engine::CreateNewWindow(const std::string& windowName)
{
	
	spic::WindowFacade::GetInstance()->create_window("yolo",1000,1000);
	spic::WindowFacade::GetInstance()->create_renderer();
}

SPIC_API void spic::Engine::StartGameLoop()
{
	running = true;
	playing = true;
	frames = 0;
	lastTime = time.GetTicks();
	timer = time.GetTicks();

	while (running) {
		if (playing) {
			// Used for frame time measuring
			_startTicks = time.GetTicks();
			activeScene->Render();
			CalculateFPS();
		}
	}
}

SPIC_API void spic::Engine::AddScene(std::shared_ptr<spic::Scene> scene)
{
	scenes.push_back(scene);
}

SPIC_API void spic::Engine::SetActiveScene(std::shared_ptr<spic::Scene> scene)
{
	for (std::shared_ptr<Scene> s : scenes) {
		if (s == scene) {
			activeScene = s;
		}
	}
}

SPIC_API int spic::Engine::GetFPS()
{
	return _fps;
}

SPIC_API void spic::Engine::SetMaxFPS(const int maxFPS)
{
	_maxFPS = maxFPS;
}

SPIC_API std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> spic::Engine::GetLevel(const std::filesystem::path& path)
{
	return tiledFacade->Read(path);
}

void spic::Engine::CalculateFPS()
{
	frames++;
	if (time.GetTicks() - timer > 1000)
	{
		timer += 1000;
		_fps = frames;
		std::cout << "fps: " << _fps << "   \r";
		frames = 0;
	}

	// Limit the FPS to the max FPS
	float frameTicks = time.GetTicks() - _startTicks;
	if (1000 / _maxFPS > frameTicks)
	{
		int milliseconds = 1000 / _maxFPS - frameTicks;
		activeScene->SetDelay(milliseconds);
	}

}

SPIC_API void spic::Engine::SetActiveScene(const std::string& sceneName)
{
	for (std::shared_ptr<Scene> s : scenes) {
		if (s->GetName() == sceneName) {
			activeScene = s;
			return;
		}
	}
}

