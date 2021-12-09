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
	Uint32 value = (GetSeconds() % getAmountOfSprites());
	return value;
}

void spic::AnimatorFacade::ReplaceSprite(std::shared_ptr<Sprite> sprite)
{
	SDL_Rect srcrect = { Getsprite() * 32, 0, 32, 64 };
	Rectangle rectangle = sprite->GetRectangle();
	rectangle.x = srcrect.x;
	rectangle.y = srcrect.y;
	rectangle.width = srcrect.w;
	rectangle.height = srcrect.h;
	sprite->SetRectangle(rectangle);
}
