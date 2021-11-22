#include "../API_Headers/Camera.hpp"
#include "../Facade_Headers/CameraFacade.hpp"

using namespace spic;

std::unique_ptr<CameraFacade> cameraFacade_ptr = std::make_unique<CameraFacade>();

spic::Camera::Camera(const std::string& name)
{
	this->name = name;
}

void spic::Camera::createRectangle()
{
	cameraFacade_ptr->createRectangle(this->x, this->y, this->aspectWidth, this->aspectHeight);
}

const Rectangle& spic::Camera::getRectangle()
{
	return cameraFacade_ptr->getRectangle();
}

void spic::Camera::Render()
{
}

void spic::Camera::setAspectWidth(const int& aspectWidth)
{
	this->aspectWidth = aspectWidth;
}

const double& spic::Camera::getAspectWidth()
{
	return this->aspectWidth;
}

void spic::Camera::setAspectHeight(const int& aspectHeight)
{
	this->aspectHeight = aspectHeight;
}

const double& spic::Camera::getAspectHeight()
{
	return this->aspectHeight;
}

void spic::Camera::setColor(const Color& color)
{
	this->backgroundColor = color;
}

const Color& spic::Camera::getColor()
{
	return this->backgroundColor;
}

void spic::Camera::setX(const int& x)
{
	this->x = x;
}

const double& spic::Camera::getX()
{
	return this->x;
}

void spic::Camera::setY(const int& aspectWidth)
{
	this->y = y;
}

const double& spic::Camera::getY()
{
	return this->y;
}
