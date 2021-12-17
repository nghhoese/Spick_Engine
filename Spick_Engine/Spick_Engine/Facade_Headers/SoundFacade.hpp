#pragma once

#define SDL_MAIN_HANDLED
#include "../API_Headers/SpicHeader.hpp"
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>

namespace spic {

    class SoundFacade {
    public:
        SPIC_API SoundFacade();
        void CreateMusic();
        void CreateSoundEffect();
        void PlayMusic();
        void PlaySoundEffect();
        void PauseMusic();
        void StopMusic();
        void setPath(std::string path);
        void SetVolume(int volume) { this->volume = volume; };
    private:
        int volume = 30;
        Mix_Music* Music;
        Mix_Chunk* SoundEffect;
        std::string _path;
    };

}