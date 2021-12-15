
#include "../API_Headers/Animator.hpp"

spic::Animator::Animator()
{
	imageFacade = std::make_unique<spic::ImageFacade>();
	imageFacade->setScale(1);
	imageFacade->setRotation(1);
	spriteIndex = 0;
	ticks = 0;
	fps = 0;
}

void spic::Animator::Play(bool looping)
{
	spriteIndex = 0;
	loop = looping;
	running = true;
	if (GetGameObject()->GetComponent<Sprite>()) {
		GetGameObject()->GetComponent<Sprite>()->DestroyImage();

	}
}

void spic::Animator::Stop()
{
	running = false;
	spriteIndex = 0;
	GetGameObject()->GetComponent<Sprite>()->SetRendered(false);
	for (std::shared_ptr<Sprite> s : sprites) {
		s->DestroyImage();
	}
}

void spic::Animator::OnClick()
{
}
void spic::Animator::OnAwake()
{
}
void spic::Animator::OnRender()
{
	if (!sprites.empty()) {
		if (running) {
			sprites[spriteIndex]->OnRender();
		}
	}
}
void spic::Animator::OnStart()
{
}
void spic::Animator::OnUpdate()
{
	if (!sprites.empty()) {
		if (running) {
			ticks++;
			if (ticks > fps) {
				ticks = 0;
				if (spriteIndex < (sprites.size() - 1)) {
					auto u = sprites;
					sprites[spriteIndex]->DestroyImage();
					sprites[spriteIndex]->SetRendered(false);
					spriteIndex++;
				}
				else {
					sprites[spriteIndex]->DestroyImage();
					sprites[spriteIndex]->SetRendered(false);
					if (!loop) {
						Stop();
					}

					spriteIndex = 0;
				}

			}
			sprites[spriteIndex]->OnUpdate();
		}
	}

}
