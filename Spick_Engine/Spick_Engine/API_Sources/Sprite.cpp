#include "..\API_Headers\Sprite.hpp"


spic::Sprite::Sprite()
{
	imageFacade = std::make_unique<spic::ImageFacade>();
	imageFacade->setScale(1);
	imageFacade->setRotation(1);
	
}

void spic::Sprite::OnAwake()
{
}

void spic::Sprite::OnStart()
{
}

void spic::Sprite::OnUpdate()
{
	transform = *GetGameObject()->getTransform();
	imageFacade->setPosition(transform.position.x, transform.position.y);
	imageFacade->setRotation(transform.rotation);
	imageFacade->setScale(transform.scale);
	
}

void spic::Sprite::OnRender()
{
	if (!rendered) {
		rendered = true;
		imageFacade->setPath(sprite);

		imageFacade->Createtexture();
	}
	imageFacade->Render();
}
