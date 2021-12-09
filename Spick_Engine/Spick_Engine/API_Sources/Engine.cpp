#include "../API_Headers/Engine.hpp"


spic::Engine::Engine() {
	running = false;
	playing = false;
	tiledFacade = std::make_shared<TiledFacade>();
}

SPIC_API void spic::Engine::CreateNewWindow(const std::string& windowName, int width, int height)
{
	spic::WindowFacade::GetInstance()->create_window(windowName, height, width);
	spic::WindowFacade::GetInstance()->create_renderer();
}

SPIC_API void spic::Engine::StartGameLoop()
{
	using namespace std::this_thread;     // sleep_for, sleep_until
	using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
	using std::chrono::system_clock;
	running = true;
	playing = true;
	frames = 0;
	lastTime = time.GetTicks();
	timer = time.GetTicks();
	float accumulatedDelta = 0;
	float RenderAccumulatedDelta = 0;


	while (running) {
		m_lastTime = time.CalculateDeltaTime();
		accumulatedDelta += m_lastTime;
		float TargetFrameRate = 17;
		//timescale tickrate
		TimeScale = time.TimeScale();
		if (TimeScale == 0) {
			playing = false;
		}
		else if (TimeScale < 1 && TimeScale > 0) {
			playing = true;
			TargetFrameRate = TargetFrameRate + ((10*(1 - TimeScale))*TargetFrameRate);
		}
		else if (TimeScale == 1) {
			playing = true;
		}
		else if (TimeScale > 1) {
			playing = true;
			TargetFrameRate = TargetFrameRate - (TargetFrameRate * (TimeScale - 1));
		}

		//check update
		if (accumulatedDelta >= TargetFrameRate)
		{
			accumulatedDelta -= TargetFrameRate;
			if (playing) {
				activeScene->Update();
			}
		}

		//check render
		m_lastTime = time.CalculateDeltaTime();
		float RenderTargetFrameRate = 0.5;
		RenderAccumulatedDelta += m_lastTime;
		if (RenderAccumulatedDelta >= RenderTargetFrameRate)
		{
			RenderAccumulatedDelta -= RenderTargetFrameRate;
			_startTicks = time.GetTicks();
			activeScene->Render();
			CalculateFPS();
		}
	}
}

SPIC_API void spic::Engine::SetGameLoopTimeScale(double newTimeScale)
{
	time.TimeScale(newTimeScale);
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

SPIC_API std::shared_ptr<spic::Scene> spic::Engine::GetSceneByName(const std::string& sceneName)
{
	for (std::shared_ptr<Scene> s : scenes) {
		std::string sName = s->GetName();
		if (sName == sceneName)
		{
			return s;
		}
	}
	return nullptr;
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
		}
	}
}

SPIC_API bool spic::Engine::getGameOver() {
	return gameOver;
}

SPIC_API void spic::Engine::setGameOver(bool gameOverBool) {
	gameOver = gameOverBool;
}

SPIC_API int spic::Engine::getCurrentLevel()
{
	return currentLevel;
}

SPIC_API void spic::Engine::setCurrentLevel(int currentLevelNumber) {
	currentLevel = currentLevelNumber;
}

SPIC_API bool spic::Engine::getCheatsEnabled() {
	return cheatsEnabled;
}

SPIC_API void spic::Engine::setCheatsEnabled(bool cheatsBool) {
	cheatsEnabled = cheatsBool;
}

SPIC_API bool spic::Engine::getIsInLevelTransition()
{
	return isInLevelTransition;
}

SPIC_API void spic::Engine::setIsInLevelTransition(bool transitionBool)
{
	isInLevelTransition = transitionBool;
}

SPIC_API void spic::Engine::EndGameLoop() {
	running = false;
	playing = false;
}

