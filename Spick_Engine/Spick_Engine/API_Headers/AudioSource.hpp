#pragma once

#include "SpicHeader.hpp"
#include "Component.hpp"
#include "Color.hpp"
#include <string>
#include "../Facade_Headers/ImageFacade.hpp"
#include "../Facade_Headers/SceneFacade.hpp"
#include "GameObject.hpp"
#include "Scene.hpp"
#include "Component.hpp"
#include <string>
#include <memory>
#include "../Facade_Headers/SoundFacade.hpp"
namespace spic {

    /**
     * @brief Component which can play audio.
     */
    class AudioSource : public Component {
        public:

            /**
            * @brief Constructor.
            */
            SPIC_API AudioSource();

            /**
            * @brief Getter for audio clip.
            * @return audio clip.
            */
            SPIC_API const std::string& GetAudioClip() const { return audioClip; }

            /**
            * @brief Set audio clip.
            */
            SPIC_API void SetAudioClip(const std::string& audioClip) { this->audioClip = audioClip; }

            /**
            * @brief Getter for play on awake.
            * @return true if play on wake, false otherwise.
            */
            SPIC_API bool GetPlayOnAwake() const { return playOnAwake; }

            /**
            * @brief Set play on wake.
            */
            SPIC_API void SetPlayOnAwake(bool playOnAwake) { this->playOnAwake = playOnAwake; }

            /**
            * @brief Getter for loop.
            * @return true if loop, false otherwise.
            */
            SPIC_API bool GetLoop() const { return loop; }

            /**
            * @brief Set loop.
            */
            SPIC_API void SetLoop(bool loop) { this->loop = loop; }

            /**
            * @brief Getter for volume.
            * @return volume.
            */
            SPIC_API double GetVolume() const { return volume; }

            /**
            * @brief Set volume, must be between 0.0 and 1.0.
            */
            SPIC_API void SetVolume(double volume) { this->volume = volume; }

            /**
            * @brief Getter for is music.
            * @return true if is music, false otherwise.
            */
            SPIC_API double GetIsMusic() const { return isMusic; }

            /**
            * @brief Set is music.
            */
            SPIC_API void SetIsMusic(bool isMusic) { this->isMusic = isMusic; }

            /**
            * @brief Call this method to start playing audio.
            * @param looping Automatically start over when done.
            */
            SPIC_API void Play(bool looping);

            /**
            * @brief Call this method to pause playing audio.
            */
            SPIC_API void Pause();

            /**
            * @brief Call this method to unpause playing audio.
            */
            SPIC_API void UnPause();

            /**
            * @brief Call this method to stop playing audio.
            */
            SPIC_API void Stop();

            /**
            * @brief Called when clicked.
            */
            SPIC_API void OnClick();

            /**
            * @brief Called when component is created even if component is disabled. View as constructor.
            */
            SPIC_API void OnAwake();

            /**
            * @brief Call this method to see if audio source is playing.
            * @return isPlaying.
            */
            SPIC_API bool GetPlaying() { return this->isPlaying; };

            /**
            * @brief Called right before first frame draw.
            */
            SPIC_API void OnStart();

            /**
            * @brief Called every frame draw.
            */
            SPIC_API void OnUpdate();

            /**
            * @brief Called every frame draw after update.
            */
            SPIC_API void OnRender();

        private:
            std::string audioClip;
            bool playOnAwake;
            bool loop;
            double volume = 30;
            int time;
            bool isPlaying = false;
            bool isMusic;
            std::unique_ptr<spic::SoundFacade> soundFacade;
    };

}


