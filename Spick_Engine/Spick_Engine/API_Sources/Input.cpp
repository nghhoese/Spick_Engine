#include "../API_Headers/Input.hpp"
#include "../Facade_Headers/KeyFacade.hpp"
#include "../Facade_Headers/MouseFacade.hpp"
#include <iostream>
using namespace spic;

std::unique_ptr<KeyFacade> keyfacade_ptr = std::make_unique<KeyFacade>();
std::unique_ptr<MouseFacade> mousefacade_ptr = std::make_unique<MouseFacade>();

// !!!!!!!!!!!
bool Input::AnyKey() {
	return mousefacade_ptr->AnyKeyPressed();
}

// !!!!!!!!!!!
bool Input::AnyKeyDown() {
	return mousefacade_ptr->AnyKeyPressed();
}

const Point Input::MousePosition() {
	Point point;

	std::tuple<int, int> coords = mousefacade_ptr->PollMousePosition();
	point.x = std::get<0>(coords);
	point.y = std::get<1>(coords);

	return point;
}

double Input::GetAxis() {

}

bool Input::GetKey(KeyCode key) {
	KeyCode keycode = keyfacade_ptr->PollEvent();
	
	if (key == keycode) {
		return true;
	}
	else {
		return false;
	}
}

bool Input::GetKeyDown(KeyCode key) {

}

bool Input::GetKeyUp(KeyCode key) {

}

bool Input::GetMouseButton(MouseButton which) {

}

bool Input::GetMouseButtonDown(MouseButton which) {

}

bool Input::GetMouseButtonUp(MouseButton which) {

}