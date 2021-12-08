#pragma once

#include "Component.hpp"
#include "SpicHeader.hpp"
#include "Sprite.hpp"
#include "../Facade_Headers/AnimatorFacade.hpp"
#include <vector>

namespace spic {

    /**
     * @brief A component which can play animated sequences of sprites.
     */
    class SPIC_API Animator : public Component {
        public:
            Animator();
            /**
             * @brief Get fps.
             * @return fps.
             */
            const int GetFps() const { return fps; }

            /**
             * @brief Set amountOfSprites.
             */
            void SetFps(int fps) { this->fps = fps; }

            /**
             * @brief Get amountOfSprites.
             * @return amountOfSprites.
             */
            const int GetAmountOfSprites() const { return amountOfSprites; }

            /**
             * @brief Set fps.
             */
            void SetAmountOfSprites(int amountOfSprites) { this->amountOfSprites = amountOfSprites, animatorFacade->setAmountOfSprites(amountOfSprites); }

            /**
             * @brief Get sprites.
             * @return sprites.
             */
            const std::vector<std::shared_ptr<Sprite>>& GetSprites() const { return sprites; }

            /**
             * @brief Set sprites.
             */
            void SetSprites(const std::vector<std::shared_ptr<Sprite>>& sprites) { this->sprites = sprites; }

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
            /**
             * @brief sprites per spritesheet
            */
            int amountOfSprites; 
            bool looping;
            std::vector<std::shared_ptr<Sprite>> sprites;
            std::unique_ptr<spic::AnimatorFacade> animatorFacade;
    };

}