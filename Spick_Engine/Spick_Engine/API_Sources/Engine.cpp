#include "../API_Headers/Engine.hpp"

spic::Engine::Engine() {
	running = false;
	playing = false;
}

SPIC_API void spic::Engine::StartGameLoop()
{
	running = true;
	playing = true;
	int frames = 0;
	long lastTime = time.GetTicks();
	long timer = time.GetTicks();

	while (running) {
		if (playing) {
			activeScene->Render();

			frames++;
			if (time.GetTicks() - timer > 1000)
			{
				timer += 1000;
				_fps = frames;
				std::cout << "fps: " + _fps << "   \r";
				frames = 0;
			}

		}
	}
}

SPIC_API void spic::Engine::AddScene(std::shared_ptr<spic::Scene> scene)
{
	scenes.push_back(scene.get());
}

SPIC_API void spic::Engine::SetActiveScene(std::shared_ptr<spic::Scene> scene)
{
	for (Scene* s : scenes) {
		if (s == scene.get()) {
			activeScene = s;
		}
	}
}

SPIC_API int spic::Engine::GetFPS()
{
	return _fps;
}

void spic::Engine::CalculateFPS()
{

}

