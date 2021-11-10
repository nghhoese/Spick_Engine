#include "../API_Headers/GameObject.hpp"

using namespace spic;

SPIC_API GameObject::GameObject(const std::string& name) {
	this->name = name;
}

SPIC_API const void GameObject::RemoveTag(const std::string& tag) {
	remove(tags.begin(), tags.end(), tag);
}

std::shared_ptr<GameObject> GameObject::Find(const std::string& name) {
	auto i = children.begin();
}

std::vector<std::shared_ptr<GameObject>> GameObject::FindGameObjectsWithTag(const std::string& tag) {

}

std::shared_ptr<GameObject> GameObject::FindWithTag(const std::string& tag) {

}

template<class T>
std::shared_ptr<GameObject> GameObject::FindObjectOfType(bool includeInactive) {

}

template<class T>
std::shared_ptr<GameObject> GameObject::FindObjectsOfType(bool includeInactive) {

}

void GameObject::Destroy(std::shared_ptr<GameObject> obj) {

}

void GameObject::Destroy(Component* obj) {

}

template<class T>
void GameObject::AddComponent(std::shared_ptr<T> component) {

}

template<class T>
std::shared_ptr<Component> GameObject::GetComponent() const {

}

template<class T>
std::shared_ptr<spic::Component> GameObject::GetComponentInChildren() const {

}

template<class T>
std::shared_ptr<spic::Component> GameObject::GetComponentInParent() const {

}

template<class T>
std::vector<std::shared_ptr<spic::Component>> GameObject::GetComponents() const {

}

template<class T>
std::vector<std::shared_ptr<spic::Component>> GameObject::GetComponentsInChildren() const {

}

template<class T>
std::vector<std::shared_ptr<spic::Component>> GameObject::GetComponentsInParent() const {

}

bool GameObject::IsActiveInWorld() const {

}

void GameObject::Update() {

}

void GameObject::Render() {

}