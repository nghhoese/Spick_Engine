#include "..\API_Headers\Sprite.hpp"

std::unique_ptr<spic::ImageFacade> imageFacade = std::make_unique<spic::ImageFacade>();

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
	Transform transform = *GetGameObject()->getTransform();

	imageFacade->setPosition(transform.position.x, transform.position.y);
}

void spic::Sprite::OnRender()
{
	imageFacade->setPath(sprite);
	imageFacade->Createtexture(GetGameObject()->getScene()->GetSceneFacade()->_renderer.get());
	imageFacade->Render(GetGameObject()->getScene()->GetSceneFacade()->_renderer.get());

}
