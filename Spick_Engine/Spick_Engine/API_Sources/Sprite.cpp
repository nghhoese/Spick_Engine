#include "..\API_Headers\Sprite.hpp"


spic::Sprite::Sprite()
{
	imageFacade = std::make_unique<spic::ImageFacade>();
	imageFacade->setScale(1);
	imageFacade->setRotation(1);
	
}

void spic::Sprite::SetSprite(const std::string& sprite)
{
	this->sprite = sprite;
	imageFacade->setPath(sprite);
	rendered = true;
	imageFacade->Createtexture();
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
	if (GetGameObject()->getScene()->GetActiveCamera() != nullptr) {
		if (player) {
			imageFacade->setPosition(transform.position.x - GetGameObject()->getScene()->GetActiveCamera()->getX(), transform.position.y - GetGameObject()->getScene()->GetActiveCamera()->getY());
		}
		else {
			int x, y, w, h;
			x = GetGameObject()->getScene()->GetActiveCamera()->getX();
			y = GetGameObject()->getScene()->GetActiveCamera()->getY();
			w = GetGameObject()->getScene()->GetActiveCamera()->getAspectWidth();
			h = GetGameObject()->getScene()->GetActiveCamera()->getAspectHeight();

			if (x < 0) {
				GetGameObject()->getScene()->GetActiveCamera()->setX(0);
			}
			if (y < 0) {
				GetGameObject()->getScene()->GetActiveCamera()->setY(0);
			}
			if (x > w) {
				GetGameObject()->getScene()->GetActiveCamera()->setX(w);
			}
			if (y > h) {
				GetGameObject()->getScene()->GetActiveCamera()->setY(h);
			}

			imageFacade->setPosition(transform.position.x - GetGameObject()->getScene()->GetActiveCamera()->getX(), transform.position.y - GetGameObject()->getScene()->GetActiveCamera()->getY());
		}
	}
	else {
		imageFacade->setPosition(transform.position.x, transform.position.y);
	}
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

void spic::Sprite::SetPlayerBool(bool value)
{
	this->player = value;
}

void spic::Sprite::OnClick() {

}
