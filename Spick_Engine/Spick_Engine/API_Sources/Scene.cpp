#include "../API_Headers/Scene.hpp"
#include "../API_Headers/UIObject.hpp"
#include "../API_Headers/Text.hpp"
#include "../API_Headers/Collision.hpp"

using namespace spic;

SPIC_API Scene::Scene(const std::string& name) {
    gameObjects = std::vector<std::shared_ptr<GameObject>>{};
    cameras = std::vector<std::shared_ptr<Camera>>{};
    this->name = name;


}
void spic::Scene::CheckCollisions()
{
    for (std::shared_ptr<GameObject> x : gameObjects) {
        x->GetComponent <spic::BehaviourScript>();
        std::shared_ptr<spic::BehaviourScript> script = std::dynamic_pointer_cast<spic::BehaviourScript>(x->GetComponent <spic::BehaviourScript>());
        if (script != nullptr) {
            std::shared_ptr<spic::BoxCollider> collider = Collision::AABB(x.get(),"");
            if (collider != nullptr) {

               script->OnTriggerStay2D(collider->GetGameObject());
            }

        }

    }
}
SPIC_API void spic::Scene::DeleteGameObject(std::shared_ptr<GameObject> obj)
{

    for (std::shared_ptr<GameObject> c : gameObjects) {
        if (c.get() == obj.get()) {
            for (std::shared_ptr<Component> c1 : obj->GetComponents()) {
                c1.reset();
            }
            remove(gameObjects.begin(), gameObjects.end(), obj);
            obj.reset();
        }
    }
}
void Scene::Update() {
    for (std::shared_ptr<GameObject> x : gameObjects) {
        x->Update();
    }
}

void Scene::Render() {
    spic::WindowFacade::GetInstance()->ClearRender();
    for (std::shared_ptr<GameObject> x : gameObjects) {
        x->Render();
    }
    spic::WindowFacade::GetInstance()->Render();
}

SPIC_API void Scene::AddCamera(const Camera& camera) {
    std::shared_ptr<Camera> camera_ptr = std::make_shared<Camera>(camera);
    this->cameras.push_back(camera_ptr);
}

SPIC_API void Scene::SetActiveCamera(const Camera& camera) {
    std::shared_ptr<Camera> camera_ptr = std::make_shared<Camera>(camera);
    for (std::shared_ptr<Camera> c : cameras) {
        if (c.get() == camera_ptr.get()) {
            this->activeCamera = c;
        }
    }
}

SPIC_API void Scene::SetActiveCamera(const std::string& cameraName) {
    for (std::shared_ptr<Camera> c : cameras) {
        if (c.get()->getCameraName() == cameraName) {
            this->activeCamera = c;
        }
    }
}

SPIC_API std::shared_ptr<Camera> spic::Scene::GetActiveCamera() const
{
    return this->activeCamera;
}

SPIC_API Camera& spic::Scene::GetCameraByName(const std::string& cameraName) const
{
    for (std::shared_ptr<Camera> c : cameras) {
        if (c.get()->getCameraName() == cameraName) {
            return *c;
        }
    }
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

SPIC_API void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject) {
    gameObjects.push_back(gameObject);
    std::shared_ptr<Scene> scene;
    scene.reset(this);
    gameObject->SetScene(scene);
}

void spic::Scene::SetDelay(const int ms) const
{
    sceneFacade->SetDelay(ms);
}





// Template classes implementatie nog vullen in header file
