#include "..\API_Headers\Sprite.hpp"

spic::Sprite::Sprite()
{
}

void spic::Sprite::OnAwake()
{
}

void spic::Sprite::OnStart()
{
}

void spic::Sprite::OnUpdate()
{
}

void spic::Sprite::OnRender()
{
	ImageFacade* imageFacade = new ImageFacade(sprite,100,100);
	imageFacade->Createtexture(GetGameObject()->getScene()->GetSceneFacade()->_renderer.get());
	imageFacade->Render(GetGameObject()->getScene()->GetSceneFacade()->_renderer.get());

}
