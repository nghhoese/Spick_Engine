#include "../Facade_Headers/SoundFacade.hpp"
#pragma warning(disable : 4996)
spic::SoundFacade::SoundFacade()
{
}

void spic::SoundFacade::CreateMusic()
{
	Mix_FreeMusic(Music);
	char* a = new char[_path.size() + 1];
	strcpy(a, _path.c_str());
	Music = Mix_LoadMUS(a);
	delete[] a;
}

void spic::SoundFacade::CreateSoundEffect()
{
	Mix_FreeChunk(SoundEffect);
	char* a = new char[_path.size() + 1];
	strcpy(a, _path.c_str());
	SoundEffect = Mix_LoadWAV(a);
	delete[] a;
}

void spic::SoundFacade::PlayMusic()
{
	if (!Mix_PlayingMusic()) {
		Mix_PlayMusic(Music, -1);
	}
	else if (Mix_PausedMusic()) {
		Mix_ResumeMusic();
	}
	
}

void spic::SoundFacade::PlaySoundEffect()
{
	Mix_PlayChannel(-1, SoundEffect, 0);
}

void spic::SoundFacade::PauseMusic()
{
	Mix_PauseMusic();
}

void spic::SoundFacade::StopMusic()
{
	Mix_HaltMusic();
}

void spic::SoundFacade::setPath(std::string path)
{
	_path = path;
}
