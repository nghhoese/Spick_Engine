#include "../API_Headers/AudioSource.hpp"

spic::AudioSource::AudioSource()
{
	soundFacade = std::make_unique<SoundFacade>();
}

void spic::AudioSource::Play(bool looping)
{
	soundFacade->setPath(audioClip);
	if (isMusic) {
		soundFacade->CreateMusic();
		soundFacade->PlayMusic();
	}
	else {
		soundFacade->CreateSoundEffect();
		soundFacade->PlaySoundEffect();
	}
}

void spic::AudioSource::Pause()
{
	soundFacade->PauseMusic();
}

void spic::AudioSource::UnPause()
{
	soundFacade->PlayMusic();
}

void spic::AudioSource::Stop()
{
	soundFacade->StopMusic();
}
void spic::AudioSource::OnClick() {

}

void spic::AudioSource::OnAwake()
{
}

void spic::AudioSource::OnStart()
{
}

void spic::AudioSource::OnUpdate()
{
}

void spic::AudioSource::OnRender()
{
}
