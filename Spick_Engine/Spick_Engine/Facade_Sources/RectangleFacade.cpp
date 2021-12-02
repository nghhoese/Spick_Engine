#include "../Facade_Headers/RectangleFacade.hpp"

spic::RectangleFacade::RectangleFacade()
{
}

void spic::RectangleFacade::Render()
{
	SDL_SetRenderDrawColor(spic::WindowFacade::GetInstance()->_renderer.get(),255,0,0,255);
SDL_RenderDrawRect(spic::WindowFacade::GetInstance()->_renderer.get(),&destR);
SDL_SetRenderDrawColor(spic::WindowFacade::GetInstance()->_renderer.get(), 0, 0, 0, 255);
}

void spic::RectangleFacade::setPosition(int x, int y)
{
	destR.x = x;
	destR.y = y;
}

void spic::RectangleFacade::setSize(int width, int height)
{
	destR.h = height;
	destR.w = width;
}
