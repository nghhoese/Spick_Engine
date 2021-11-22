#include "../API_Headers/Camera.hpp"
#include "../Facade_Headers/CameraFacade.hpp"

using namespace spic;

std::unique_ptr<CameraFacade> cameraFacade_ptr = std::make_unique<CameraFacade>();

void spic::Camera::createRectangle(const int& aspectWidth, const int& aspectHeight)
{
	cameraFacade_ptr->createRectangle(aspectWidth, aspectHeight);
}

const Rectangle& spic::Camera::getRectangle()
{
	return cameraFacade_ptr->getRectangle();
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
