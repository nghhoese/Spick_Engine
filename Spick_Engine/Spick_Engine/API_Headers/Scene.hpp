#pragma once

#include <algorithm>
#include <vector>
#include <string>
#include "SpicHeader.hpp"
#include "GameObject.hpp"
#include "../Facade_Headers/SceneFacade.hpp"

namespace spic {

    class Camera;

    /**
     * @brief Class representing a scene which can be rendered by the Camera.
     */
    class Scene {
        public:

            /**
             * @brief Constructor.
             * @param name The name for the scene.
             */
            SPIC_API Scene(const std::string& name);

            /**
             * @brief Get name.
             * @return name.
             */
            const std::string& GetName() const { return name; }

            /**
             * @brief This function is called by the engine to update the scene on the engine.
             */
            SPIC_API void Update();

            /**
             * @brief This function is called by the engine to render the scene on the engine.
             */
            SPIC_API void Render();

            /**
             * @brief Add camera.
             */
            void AddCamera(const Camera& camera);

            /**
             * @brief Set active camera to use for update and rendering.
             */
            void SetActiveCamera(const Camera& camera);

            /**
             * @brief Set active camera to use for update and rendering.
             */
            void SetActiveCamera(const std::string& cameraName);

            /**
             * @brief Get active camera to use for update and rendering.
             */
            Camera& GetActiveCamera() const;

            /**
             * @brief Get camera by name.
             */
            Camera& GetCameraByName(const std::string& cameraName) const;

            /**
             * @brief Get game objects by name.
             */
            SPIC_API std::vector<std::shared_ptr<GameObject>> GetGameObjectsByName(const std::string& gameObjectName);

            /**
             * @brief Get game objects by tag.
             */
            SPIC_API std::vector<std::shared_ptr<GameObject>> GetGameObjectsByTag(const std::string& gameObjectTag);

            /**
             * @brief Get game objects.
             */
            SPIC_API const std::vector<std::shared_ptr<GameObject>> GetGameObjects() const;

            /**
             * @brief Get game objects by type.
             */
            template<class T>
            SPIC_API std::vector<std::shared_ptr<T>> GetGameObjectsByType() const
            {
                // ... implementation here
            }

            /**
             * @brief Add game object.
             */
            SPIC_API void AddGameObject(std::shared_ptr<GameObject> gameObject);
            std::shared_ptr<WindowFacade> GetSceneFacade() { return sceneFacade; }

            /**
            * @brief Returns the timer ticks.
            */
            SPIC_API long CalculateFPS();

            SPIC_API long GetTicks();

    private:
        std::string name;
        std::vector<std::shared_ptr<GameObject>> gameObjects;
        std::vector<std::shared_ptr<Camera>> cameras;
        std::shared_ptr<WindowFacade> sceneFacade;
    };

}
