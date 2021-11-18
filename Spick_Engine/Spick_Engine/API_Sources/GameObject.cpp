#include "../API_Headers/GameObject.hpp"

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

void GameObject::Update() {

}

void GameObject::Render() {
	for (std::shared_ptr<Component> c : components) {
		c->OnUpdate();
		c->OnRender();
	}
}

SPIC_API const spic::Transform* spic::GameObject::getTransform()
{
	return &transform;
}

// Template classes implementatie nog vullen in header file