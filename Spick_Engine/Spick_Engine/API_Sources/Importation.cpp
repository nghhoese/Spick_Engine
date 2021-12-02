#include "..\API_Headers\Importation.hpp"
#include "../Facade_Headers/KeyFacade.hpp"
#include "../Facade_Headers/MouseFacade.hpp"

std::unique_ptr<KeyFacade> keyfacade_ptr = std::make_unique<KeyFacade>();;
std::unique_ptr<MouseFacade> mousefacade_ptr = std::make_unique<MouseFacade>();

spic::Importation::Importation()
{
}

SPIC_API bool spic::Importation::AnyKey() // werkt gedeeltelijk
{
	bool keyboard = keyfacade_ptr->PollContinousEvent(); // werkt niet continous
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

SPIC_API bool spic::Importation::AnyKeyDown() // getest
{
	 bool keyboard = keyfacade_ptr->AnyKeyPressed();
	 bool mouse = mousefacade_ptr->AnyKeyPressed();

	 if (keyboard || mouse)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
}

SPIC_API const spic::Point spic::Importation::MousePosition() // getest
{
	Point point;

	std::tuple<int, int> coords = mousefacade_ptr->PollMousePosition();
	point.x = std::get<0>(coords);
	point.y = std::get<1>(coords);

	return point;
}

SPIC_API double spic::Importation::GetAxis() // kan nog niet
{
	return true;
}

SPIC_API bool spic::Importation::GetKey(KeyCode key) // Getest
{
	return keyfacade_ptr->PollContinousEvent(key);
}

SPIC_API bool spic::Importation::GetKeyDown(KeyCode key) // getest
{
	KeyCode keycode = keyfacade_ptr->PollEvent();

	if (key == keycode) {
		return true;
	}
	else {
		return false;
	}
}

SPIC_API bool spic::Importation::GetKeyUp(KeyCode key) // getest
{
	KeyCode keycode = keyfacade_ptr->PollEvent1();

	if (key == keycode) {
		return true;
	}
	else {
		return false;
	}
}

SPIC_API bool spic::Importation::GetMouseButton(MouseButton which) // getest
{
	return mousefacade_ptr->GetMouseButton((int)which);
}

SPIC_API bool spic::Importation::GetMouseButtonDown(MouseButton which) // getest
{
	return mousefacade_ptr->GetMouseButtonDown((int)which);
}

SPIC_API bool spic::Importation::GetMouseButtonUp(MouseButton which) // getest
{
	return mousefacade_ptr->GetMouseButtonUp((int)which);
}

SPIC_API Point spic::Importation::GetMousePosition() {
	Point point;
	std::tuple<int, int> coords = mousefacade_ptr->PollMousePosition();
	point.x = std::get<0>(coords);
	point.y = std::get<1>(coords);
	return point;
}
