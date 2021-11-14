#include "../API_Headers/GameObject.hpp"

using namespace spic;

SPIC_API GameObject::GameObject(const std::string& name) {
	this->name = name;
}

std::shared_ptr<GameObject> GameObject::Find(const std::string& name) {
	for (GameObject c : children) {
		if (c.GetName() == name) {
			return std::make_shared<GameObject>(c);;
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

bool GameObject::IsActiveInWorld() const {

}

void GameObject::Update() {

}

void GameObject::Render() {

}

// Template classes implementatie nog vullen in header file