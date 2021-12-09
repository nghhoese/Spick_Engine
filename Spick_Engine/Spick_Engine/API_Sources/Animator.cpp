#include "..\API_Headers\Animator.hpp"

spic::Animator::Animator()
{
	animatorFacade = std::make_unique<spic::AnimatorFacade>();
}

void spic::Animator::Play(bool looping)
{
	this->looping = looping;
	if (this->looping) {
		for (std::shared_ptr<Sprite> sprite : sprites )
		{
			animatorFacade->ReplaceSprite(sprite);
		}
	}
}

void spic::Animator::Stop()
{
	this->looping = false;
}

void spic::Animator::OnClick() {

}

void spic::Animator::OnAwake()
{
}

void spic::Animator::OnStart()
{
}

void spic::Animator::OnUpdate()
{
}

void spic::Animator::OnRender()
{
}