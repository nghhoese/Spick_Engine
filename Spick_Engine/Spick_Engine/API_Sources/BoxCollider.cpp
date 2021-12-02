#include "../API_Headers/BoxCollider.hpp"

spic::BoxCollider::BoxCollider()
{
	rectangleFacade = std::make_unique<spic::RectangleFacade>();
}

void spic::BoxCollider::OnAwake()
{
}

void spic::BoxCollider::OnStart()
{
}

void spic::BoxCollider::OnUpdate()
{
	if (showBox) {
		rectangleFacade->setSize(Width(), Height());
		auto transform = *GetGameObject()->getTransform();
		if (GetGameObject()->getScene()->GetActiveCamera() != nullptr) {
			if (player) {
				rectangleFacade->setPosition(transform.position.x - GetGameObject()->getScene()->GetActiveCamera()->getX(), transform.position.y - GetGameObject()->getScene()->GetActiveCamera()->getY());
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

				rectangleFacade->setPosition(transform.position.x - GetGameObject()->getScene()->GetActiveCamera()->getX(), transform.position.y - GetGameObject()->getScene()->GetActiveCamera()->getY());
			}
		}
		else {
			rectangleFacade->setPosition(transform.position.x, transform.position.y);
		}
	}
}

void spic::BoxCollider::OnRender()
{
	if (showBox) {
		rectangleFacade->Render();
	}
}

void spic::BoxCollider::OnClick()
{
}
