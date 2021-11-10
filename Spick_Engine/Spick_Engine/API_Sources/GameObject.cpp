#include "../API_Headers/GameObject.hpp"

using namespace spic;

SPIC_API GameObject::GameObject(const std::string& name) {
	this->name = name;
}

std::shared_ptr<GameObject> GameObject::Find(const std::string& name) {
	// werkt nog niet
	std::shared_ptr<GameObject> found = (std::shared_ptr<GameObject>)std::find_if(children.begin(), children.end(), [name](std::shared_ptr<GameObject> const& i) {
		return i.get() == name;
		});
	return found;
}

std::vector<std::shared_ptr<GameObject>> GameObject::FindGameObjectsWithTag(const std::string& tag) {


}

std::shared_ptr<GameObject> GameObject::FindWithTag(const std::string& tag) {
	
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