#include "..\API_Headers\Sprite.hpp"

std::unique_ptr<spic::ImageFacade> imageFacade = std::make_unique<spic::ImageFacade>();

spic::Sprite::Sprite()
{
	imageFacade->setSize(50, 50);
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
	std::cout << "halloooooo";
}

void spic::Sprite::OnRender()
{
	std::cout << "speciaal voor die homo jeroen";
	imageFacade->setPath(sprite);
	imageFacade->Createtexture(GetGameObject()->getScene()->GetSceneFacade()->_renderer.get());
	imageFacade->Render(GetGameObject()->getScene()->GetSceneFacade()->_renderer.get());

}
