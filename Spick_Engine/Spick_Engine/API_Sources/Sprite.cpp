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
	ImageFacade* imageFacade = new ImageFacade("lol",50,50);
	imageFacade->Createtexture(GetGameObject()->getScene()->GetSceneFacade()->_renderer.get());
	imageFacade->Render(GetGameObject()->getScene()->GetSceneFacade()->_renderer.get());

}
