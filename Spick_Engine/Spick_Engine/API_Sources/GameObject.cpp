#include "../API_Headers/GameObject.hpp"
#include "../API_Headers/BehaviourScript.hpp"
#include "../API_Headers/Scene.hpp"


using namespace spic;
std::vector<GameObject> GameObject::children;
GameObject::GameObject(const std::string& name) {
	this->name = name;

}

spic::GameObject::GameObject()
{
}

SPIC_API void GameObject::SetScene(std::shared_ptr<Scene> _scene)
{
	scene = _scene;
}

SPIC_API std::shared_ptr<Scene> GameObject::getScene()
{
	return scene;
}

const void spic::GameObject::SetName(const std::string& newName)
{
	this->name = newName;
	this->getScene();
	
}

std::shared_ptr<GameObject> GameObject::Find(const std::string& name) {
	for (GameObject c : children) {
		if (c.GetName() == name) {
			return std::make_shared<GameObject>(c);
		}
	}
	return nullptr;
}

std::vector<std::shared_ptr<GameObject>> GameObject::FindGameObjectsWithTag(const std::string& tag) {
	std::vector<std::shared_ptr<GameObject>> gameObjectsWithTag;
	for (GameObject c : children) {
		std::vector<std::string> gameobjectTags = c.GetTags();
		if (std::find(gameobjectTags.begin(), gameobjectTags.end(), tag) != gameobjectTags.end())
		{
			gameObjectsWithTag.push_back(std::make_shared<GameObject>(c));
		}
	}
	return gameObjectsWithTag;
}

std::shared_ptr<GameObject> GameObject::FindWithTag(const std::string& tag) {
	for (GameObject c : children) {
		std::vector<std::string> gameobjectTags = c.GetTags();
		if (std::find(gameobjectTags.begin(), gameobjectTags.end(), tag) != gameobjectTags.end())
		{
			return std::make_shared<GameObject>(c);
		}
	}
	return nullptr;
}	

void GameObject::Destroy(std::shared_ptr<GameObject> obj) {

}

void GameObject::Destroy(Component* obj) {

}

void GameObject::Render() {
	for (std::shared_ptr<Component> c : components) {
		c->OnRender();
	}
}

void GameObject::Update() {
	for (std::shared_ptr<Component> c : components) {
		c->OnUpdate();
	}
}

SPIC_API const spic::Transform* spic::GameObject::getTransform()
{
	return &transform;
}

SPIC_API std::shared_ptr<spic::Component> GameObject::GetComponentByName(const std::string& name) {
	for (std::shared_ptr<Component> c : components) {
		std::string cName = c->Name();
		if (cName == name)
		{
			return c;
		}
	}
	return nullptr;
}

SPIC_API void GameObject::AddScene(std::shared_ptr<Scene> _scene)
{
	this->scenes.push_back(_scene);
}

SPIC_API void GameObject::SetActiveScene(std::shared_ptr<spic::Scene> scene)
{
	for (std::shared_ptr<Scene> s : scenes) {
		if (s.get() == scene.get()) {
			this->scene = s;
		}
	}
}