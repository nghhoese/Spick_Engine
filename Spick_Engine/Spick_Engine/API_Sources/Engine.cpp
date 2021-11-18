#include "../API_Headers/Engine.hpp"

spic::Engine::Engine() {
	running = false;
	playing = false;
}

SPIC_API void spic::Engine::StartGameLoop()
{
	running = true;
	playing = true;

	while (running) {
		if (playing) {
			activeScene->Render();
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
