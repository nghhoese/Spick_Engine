#include "../API_Headers/Scene.hpp"

using namespace spic;



SPIC_API Scene::Scene(const std::string& name) {
    gameObjects = std::vector<std::shared_ptr<GameObject>>{};
    cameras = std::vector<std::shared_ptr<Camera>>{};

}

void Scene::Update() {
    for (std::shared_ptr<GameObject> x : gameObjects) {
        x->Update();
    }
}

void Scene::Render() {

    for (std::shared_ptr<GameObject> x : gameObjects) {
        x->Render();
    }

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
    std::vector<std::shared_ptr<GameObject>> objects = std::vector<std::shared_ptr<GameObject>>{};
    for (std::shared_ptr<GameObject> x : gameObjects) {
        if (gameObjectName == x->GetName()) {
            objects.push_back(x);
       }
    }
    return objects;
}

SPIC_API std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjectsByTag(const std::string& gameObjectTag) {
    std::vector<std::shared_ptr<GameObject>> objects = std::vector<std::shared_ptr<GameObject>>{};
    for (std::shared_ptr<GameObject> x : gameObjects) {
        for (std::string tag : x->GetTags()) {
            if (gameObjectTag == tag) {
                objects.push_back(x);
            }
        }

    }
    return objects;
}

SPIC_API const std::vector<std::shared_ptr<GameObject>> Scene::GetGameObjects() const {
    return gameObjects;
}

template<class T>
SPIC_API std::vector<std::shared_ptr<T>> Scene::GetGameObjectsByType() const{
    // ... implementation here
}

SPIC_API void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject) {
    gameObjects.push_back(gameObject);
}