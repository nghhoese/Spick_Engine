#include "../API_Headers/Engine.hpp"

spic::Engine::Engine() {
	running = false;
	playing = false;
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
			activeScene->CreateWindow();
			return;
		}
	}

}

SPIC_API std::shared_ptr<spic::Scene> spic::Engine::GetSceneByName(const std::string& sceneName)
{
	for (std::shared_ptr<Scene> s : scenes) {
		if (s->GetName() == sceneName) {
			return s;
		}
	}
	return nullptr;
}

SPIC_API void spic::Engine::SetActiveScene(const std::string& sceneName)
{
	for (std::shared_ptr<Scene> s : scenes) {
		if (s->GetName() == sceneName) {
			activeScene = s;
			activeScene->CreateWindow();
			return;
		}
	}
}

SPIC_API int spic::Engine::GetFPS()
{
	return _fps;
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
}

