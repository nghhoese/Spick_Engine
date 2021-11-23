#ifndef ENGINE_H_
#define ENGINE_H_
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include "SpicHeader.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Time.hpp"
#include "../Facade_Headers/SceneFacade.hpp"

namespace spic {

    /**
     * @brief Any object which should be represented on screen.
     */
    class Engine {
        
    public:

        
        SPIC_API void Init() const;
        SPIC_API Engine();

        SPIC_API void CreateNewWindow(const std::string& windowName);
        
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
        void SetGameLoopTimeScale(double newTimeScale);
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
        SPIC_API std::shared_ptr<spic::Scene> GetActiveScene();

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

    private:
   
        bool running = false;
        bool playing = false;
        /**
         * @brief Constructor.
         * @details This is the constructor for the Engine object
         */
      
        std::vector<Scene*> scenes;
        Scene* activeScene;

        int _fps = 0;
        int _maxFPS = 1000;
        int _startTicks;
        Time time;
        int frames = 0;
        long timer;
        long lastTime;
        void CalculateFPS();
    };

}

#endif // ENGINE_H_
