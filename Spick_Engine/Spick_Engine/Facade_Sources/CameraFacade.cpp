#include "../Facade_Headers/CameraFacade.hpp"

void CameraFacade::CreateRectangle(const double& x, const double& y, const double& width, const double& height)
{
	this->sdl_rectangle = { (int)x, (int)y, (int)width, (int)height };
}

void CameraFacade::ConvertToRectangle(spic::Rectangle* rectangle)
{
	rectangle->x = this->sdl_rectangle.x;
	rectangle->y = this->sdl_rectangle.y;
	rectangle->width = this->sdl_rectangle.w;
	rectangle->height = this->sdl_rectangle.h;
}

void CameraFacade::UpdateCamera(const double& x, const double& y)
{
	this->sdl_rectangle.x = x;
	this->sdl_rectangle.y = y;
}