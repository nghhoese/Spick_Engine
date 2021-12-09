#ifndef ENGINE_H_
#define ENGINE_H_
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <any>
#include <filesystem>
#include "SpicHeader.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Time.hpp"
#include "../Facade_Headers/SceneFacade.hpp"
#include "../Facade_Headers/TiledFacade.hpp"
#include <chrono>
#include <thread>


namespace spic {

    /**
     * @brief Any object which should be represented on screen.
     */
    class Engine {
        
    public:
        
        SPIC_API void Init() const;
        SPIC_API Engine();

        SPIC_API void CreateNewWindow(const std::string& windowName, int width, int height);
        
        /**
         * @brief Add a Camera.
         * @details This function places a pointer to the Camera in
         *          a suitable container.
         * @param camera Reference to the Camera.
         */
        void AddCamera(std::shared_ptr<Camera> camera);

        /**
        * @brief Starts the Gameloop.
        * @details This function will initialize and start the Gameloop. This will run until stopped.
        */
        SPIC_API void StartGameLoop();

        /**
        * @brief Pauzes the Gameloop.
        * @details This function will pause the Gameloop. This will pause game until restarted with StartGameLoop().
        */
        void PauseGameLoop();

        /**
        * @brief Quits the Gameloop.
        * @details This function will quit the Gameloop and clean all objects before closing game.
        */
        void QuitGameLoop();

        /**
        * @brief Sets the timescale of the Gameloop.
        * @details This function will change the timescale of the Gameloop in the Time class.
         * @param newTimeScale Double describing the timescale. 0 for pause and 1 for normal speed or inbetween for slowmotion and bigger than 1 for superspeed.
        */
        SPIC_API void SetGameLoopTimeScale(double newTimeScale);
        /**
         * @brief Add scene.
         */

        SPIC_API void AddScene(std::shared_ptr<spic::Scene> scene);

        /**
         * @brief Set active scene to use for update and rendering.
         */
        SPIC_API void SetActiveScene(std::shared_ptr<spic::Scene> scene);

        /**
         * @brief Set active scene to use for update and rendering.
         */
        SPIC_API void SetActiveScene(const std::string& sceneName);

        /**
         * @brief Get active scene to use for update and rendering.
         */
        SPIC_API std::shared_ptr<spic::Scene> GetActiveScene() { return this->activeScene; };

        /**
         * @brief Get scene by name.
         */
        SPIC_API std::shared_ptr<spic::Scene> GetSceneByName(const std::string& sceneName);

        /**
        * @brief Return current FPS.
        */
        SPIC_API int GetFPS();

        /**
        * @brief Set max FPS
        */
        SPIC_API void SetMaxFPS(const int maxfps);

        /**
        * @brief Returns Tiled map data.
        */
        SPIC_API std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> GetLevel(const std::filesystem::path& path);

        SPIC_API bool getGameOver();

        SPIC_API void setGameOver(bool gameOverBool);

        SPIC_API int getCurrentLevel();

        SPIC_API void setCurrentLevel(int currentLevelNumber);

        SPIC_API bool getCheatsEnabled();

        SPIC_API void setCheatsEnabled(bool cheatsBool);

        SPIC_API bool getIsInLevelTransition();

        SPIC_API void setIsInLevelTransition(bool transitionBool);

        /**
        * @brief Ends the gameloop
        */
        SPIC_API void EndGameLoop();


        float TimeScale;
        float TargetFrameRate;
    private:
   
        bool running = false;
        bool playing = false;
      
        std::vector<std::shared_ptr<Scene>> scenes;
        std::shared_ptr<Scene> activeScene;
        std::shared_ptr<TiledFacade> tiledFacade;

        int _fps = 0;
        int _maxFPS = 1000;
        int _startTicks;
        Time time;
        int frames = 0;
        long timer;
        long lastTime;
        void CalculateFPS();

        bool gameOver = false;
        bool cheatsEnabled = false;
        bool isInLevelTransition = false;
        int currentLevel = 1;
        float m_lastTime;
    };

}

#endif // ENGINE_H_
