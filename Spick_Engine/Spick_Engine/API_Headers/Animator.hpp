#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "Component.hpp"
#include "Sprite.hpp"
#include <vector>

namespace spic {

    /**
     * @brief A component which can play animated sequences of sprites.
     */
    class Animator : public Component {
        public:
            /**
             * @brief Get fps.
             * @return fps.
             */
            const int GetFps() const { return fps; }

            /**
             * @brief Set fps.
             */
            void SetFps(int fps) { this->fps = fps; }

            /**
             * @brief Get sprites.
             * @return sprites.
             */
            const std::vector<Sprite>& GetSprites() const { return sprites; }

            /**
             * @brief Set sprites.
             */
            void SetSprites(const std::vector<Sprite>& sprites) { this->sprites = sprites; }

            /**
             * @brief Start playing the image sequence.
             * @param looping If true, will automatically start again when done.
             */
            void Play(bool looping);

            /**
             * @brief Stop playing the image sequence. Whatever sprite was displayed
             *        last will remain shown.
             */
            void Stop();
            void OnClick() = 0;

        private:
            /**
             * @brief frames per second (playing speed)
             */
            int fps;
            std::vector<Sprite> sprites;
    };

}

#endif // ANIMATOR_H_
