#include "../API_Headers/Scene.hpp"

using namespace spic;

std::string Scene::name;

/**
 * @brief Constructor.
 * @param name The name for the scene.
 */
SPIC_API Scene::Scene(const std::string& name) {

}

/**
 * @brief Get name.
 * @return name.
 */
const std::string& Scene::GetName() const {
    return name; 
}

/**
 * @brief This function is called by the engine to update the scene on the engine.
 */
void Scene::Update() {

}

/**
 * @brief This function is called by the engine to render the scene on the engine.
 */
void Scene::Render() {

}

/**
 * @brief Add camera.
 */
void Scene::AddCamera(const Camera& camera) {

}

/**
 * @brief Set active camera to use for update and rendering.
 */
void Scene::SetActiveCamera(const Camera& camera) {

}

/**
 * @brief Set active camera to use for update and rendering.
 */
void Scene::SetActiveCamera(const std::string& cameraName) {

}

/**
 * @brief Get active camera to use for update and rendering.
 */
Camera& Scene::GetActiveCamera() const {

}

/**
 * @brief Get camera by name.
 */
Camera& Scene::GetCameraByName(const std::string& cameraName) const {

}

/**
 * @brief Get game objects by name.
 */
SPIC_API std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjectsByName(const std::string& gameObjectName) {

}

/**
 * @brief Get game objects by tag.
 */
SPIC_API std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjectsByTag(const std::string& gameObjectTag) {

}

/**
 * @brief Get game objects.
 */
SPIC_API const std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjects() const {

}

/**
 * @brief Get game objects by type.
 */
template<class T>
SPIC_API std::vector<std::shared_ptr<T>> Scene::GetGameObjectsByType() const
{
    // ... implementation here
}

/**
 * @brief Add game object.
 */
SPIC_API void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject) {

}