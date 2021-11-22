#include "../Facade_Headers/CameraFacade.hpp"

void CameraFacade::createRectangle(const double& x, const double& y, const double& width, const double& height)
{
	this->camera = { (int)x, (int)y, (int)width, (int)height };
}

const spic::Rectangle& CameraFacade::getRectangle()
{
	spic::Rectangle rectangle;

	rectangle.x = this->camera.x;
	rectangle.y = this->camera.y;
	rectangle.width = this->camera.w;
	rectangle.height = this->camera.h;

	return rectangle;
}
