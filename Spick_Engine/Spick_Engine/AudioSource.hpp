#ifndef AUDIOSOURCE_H_
#define AUDIOSOURCE_H_

#include "Component.hpp"
#include <string>

namespace spic {

    /**
     * @brief Component which can play audio.
     */
    class AudioSource : public Component {
        public:
            /**
             * @brief Getter for audio clip.
             * @return audio clip.
             */
            const std::string& GetAudioClip() const { return audioClip; }

            /**
             * @brief Set audio clip.
             */
            void SetAudioClip(const std::string& audioClip) { this->audioClip = audioClip; }

            /**
             * @brief Getter for play on awake.
             * @return true if play on wake, false otherwise.
             */
            bool GetPlayOnAwake() const { return playOnAwake; }

            /**
             * @brief Set play on wake.
             */
            void SetPlayOnAwake(bool playOnAwake) { this->playOnAwake = playOnAwake; }

            /**
             * @brief Getter for loop.
             * @return true if loop, false otherwise.
             */
            bool GetLoop() const { return loop; }

            /**
             * @brief Set loop.
             */
            void SetLoop(bool loop) { this->loop = loop; }

            /**
             * @brief Getter for volume.
             * @return volume.
             */
            double GetVolume() const { return volume; }

            /**
             * @brief Set volume, must be between 0.0 and 1.0.
             */
            void SetVolume(double volume) { this->volume = volume; }

            /**
             * @brief Getter for is music.
             * @return true if is music, false otherwise.
             */
            double GetIsMusic() const { return isMusic; }

            /**
             * @brief Set is music.
             */
            void SetIsMusic(bool isMusic) { this->isMusic = isMusic; }

            /**
             * @brief Call this method to start playing audio.
             * @param looping Automatically start over when done.
             */
            void Play(bool looping);

            /**
            * @brief Call this method to pause playing audio.
            */
            void Pause();

            /**
            * @brief Call this method to unpause playing audio.
            */
            void UnPause();

            /**
             * @brief Call this method to stop playing audio.
             */
            void Stop();

        private:
            /**
             * @brief Path to a locally stored audio file.
             */
            std::string audioClip;

            /**
             * @brief When true, the component will start playing automatically.
             */
            bool playOnAwake;

            /**
             * @brief When true, the audio will play indefinitely.
             */
            bool loop;

            /**
             * @brief Audio volume, between 0.0 and 1.0.
             */
            double volume;

            /**
            * @brief Playback position in seconds.
            */
            int time;

            /**
            * @brief is music.
            */
            bool isMusic;
    };

}

#endif // AUDIOSOURCE_H_
