#include "..\Facade_Headers\AnimatorFacade.hpp"

spic::AnimatorFacade::AnimatorFacade()
{
}

Uint32 spic::AnimatorFacade::GetTicks()
{
	return SDL_GetTicks();
}

Uint32 spic::AnimatorFacade::GetSeconds()
{
	return (GetTicks() / 1000);
}

Uint32 spic::AnimatorFacade::Getsprite()
{
	return (GetSeconds() % getAmountOfSprites());
}

void spic::AnimatorFacade::ReplaceSprite(std::shared_ptr<Sprite> sprite)
{
	SDL_Rect srcrect = { Getsprite() * sprite->GetWidth(), 0, sprite->GetWidth(), (sprite->GetWidth() * 2) };
	Rectangle rectangle = sprite->GetRectangle();
	rectangle.x = srcrect.x;
	rectangle.y = srcrect.y;
	rectangle.width = srcrect.w;
	rectangle.height = srcrect.h;
	sprite->SetRectangle(rectangle);
}
