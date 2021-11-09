#include "../API_Headers/Scene.hpp"

using namespace spic;

std::string Scene::name;

SPIC_API Scene::Scene(const std::string& name) {

}

const std::string& Scene::GetName() const {
    return name; 
}

void Scene::Update() {

}

void Scene::Render() {

}

void Scene::AddCamera(const Camera& camera) {

}

void Scene::SetActiveCamera(const Camera& camera) {

}

void Scene::SetActiveCamera(const std::string& cameraName) {

}

Camera& Scene::GetActiveCamera() const {

}

Camera& Scene::GetCameraByName(const std::string& cameraName) const {

}

SPIC_API std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjectsByName(const std::string& gameObjectName) {

}

SPIC_API std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjectsByTag(const std::string& gameObjectTag) {

}

SPIC_API const std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjects() const {

}

template<class T>
SPIC_API std::vector<std::shared_ptr<T>> Scene::GetGameObjectsByType() const
{
    // ... implementation here
}

SPIC_API void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject) {

}