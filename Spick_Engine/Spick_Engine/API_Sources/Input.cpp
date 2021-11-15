#include "../API_Headers/Input.hpp"
#include "../Facade_Headers/KeyFacade.hpp"
#include "../Facade_Headers/MouseFacade.hpp"
using namespace spic;

std::unique_ptr<KeyFacade> keyfacade_ptr = std::make_unique<KeyFacade>();;
std::unique_ptr<MouseFacade> mousefacade_ptr = std::make_unique<MouseFacade>();

Input::Input() {

}

bool Input::AnyKey() {
	bool keyboard = keyfacade_ptr->PollContinousEvent();
	bool mouse = mousefacade_ptr->PollContinousEvent();

	if (keyboard || mouse)
	{
		return true;
	}
	else
	{
		return false;
	}
}

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
	return keyfacade_ptr->PollContinousEvent(key);
}

bool Input::GetKeyDown(KeyCode key) {
	KeyCode keycode = keyfacade_ptr->PollEvent();

	if (key == keycode) {
		return true;
	}
	else {
		return false;
	}
}

bool Input::GetKeyUp(KeyCode key) {
	KeyCode keycode = keyfacade_ptr->PollEvent();

	if (key == keycode) {
		return true;
	}
	else {
		return false;
	}

}

bool Input::GetMouseButton(MouseButton which) {
	return mousefacade_ptr->GetMouseButton((int)which);
}

bool Input::GetMouseButtonDown(MouseButton which) {
	return mousefacade_ptr->GetMouseButtonDown((int)which);
}

bool Input::GetMouseButtonUp(MouseButton which) {
	return mousefacade_ptr->GetMouseButtonUp((int)which);
}