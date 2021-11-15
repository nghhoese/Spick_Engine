#include "..\API_Headers\Importation.hpp"

spic::Importation::Importation()
{
}

SPIC_API bool spic::Importation::AnyKey()
{
	return false;
}

SPIC_API bool spic::Importation::AnyKeyDown()
{
	return true;
}

SPIC_API const spic::Point spic::Importation::MousePosition()
{
	Point point;
	point.x = 0;
	point.y = 0;
	return point;
}

SPIC_API double spic::Importation::GetAxis()
{
	return true;
}

SPIC_API bool spic::Importation::GetKey(KeyCode key)
{
	return true;
}

SPIC_API bool spic::Importation::GetKeyDown(KeyCode key)
{
	return true;
}

SPIC_API bool spic::Importation::GetKeyUp(KeyCode key)
{
	return true;
}

SPIC_API bool spic::Importation::GetMouseButton(MouseButton which)
{
	return true;
}

SPIC_API bool spic::Importation::GetMouseButtonDown(MouseButton which)
{
	return true;
}

SPIC_API bool spic::Importation::GetMouseButtonUp(MouseButton which)
{
	return true;
}
