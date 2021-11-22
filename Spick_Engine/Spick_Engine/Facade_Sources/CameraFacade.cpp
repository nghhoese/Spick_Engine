#include "../Facade_Headers/CameraFacade.hpp"

void CameraFacade::createRectangle(const int& width, const int& height)
{
	this->camera = { 0, 0, width, height };
}

const Rectangle& CameraFacade::getRectangle()
{
	Rectangle rectangle;

	rectangle.x = this->camera.x;
	rectangle.y = this->camera.y;
	rectangle.width = this->camera.w;
	rectangle.height = this->camera.h;

	return rectangle;
}
