#pragma once

#define SDL_MAIN_HANDLED
#include "../API_Headers/SpicHeader.hpp"
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>

namespace spic {

    /**
     * @brief Color represents a red-green-blue color with alpha.
     */
    class SoundFacade {
    public:
        /**
         * @brief Default constructor representing a white color.
         */
        SPIC_API SoundFacade();
        void CreateMusic();
        void CreateSoundEffect();
        void PlayMusic();
        void PlaySoundEffect();
        void PauseMusic();
        void StopMusic();
        void setPath(std::string path);
    private:
        Mix_Music* Music;
        Mix_Chunk* SoundEffect;
        std::string _path;
    };

}