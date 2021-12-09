#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "Component.hpp"
#include "Sprite.hpp"
#include <vector>
#include "../Facade_Headers/ImageFacade.hpp"

namespace spic {

    /**
     * @brief A component which can play animated sequences of sprites.
     */
    class SPIC_API Animator : public Component {
        public:
            /**
             * @brief Get fps.
             * @return fps.
             */
            Animator();
            const int GetFps() const { return fps; }

            /**
             * @brief Set fps.
             */
            void SetFps(int fps) { this->fps = fps; }

            /**
             * @brief Get sprites.
             * @return sprites.
             */
            const std::vector<std::shared_ptr<Sprite>> GetSprites() const { return sprites; }

            /**
             * @brief Set sprites.
             */
            void SetSprites(std::vector<std::shared_ptr<Sprite>> sprites) { this->sprites = sprites; }

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
            void OnClick();
            void OnAwake();
            void OnRender();

            /**
             * @brief Called right before first frame draw.
             */
            void OnStart();
            void OnUpdate();

        private:
            /**
             * @brief frames per second (playing speed)
             */
            bool running = false;
            int ticks;
            int spriteIndex;
            int fps;
            std::vector<std::shared_ptr<Sprite>> sprites;
            std::unique_ptr<spic::ImageFacade> imageFacade;
    };

}

#endif // ANIMATOR_H_
