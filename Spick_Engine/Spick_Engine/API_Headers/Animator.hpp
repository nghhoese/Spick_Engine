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
    class Animator : public Component {
        public:

            /**
            * @brief Constructor.
            */
            SPIC_API Animator();

            /**
            * @brief Get fps.
            * @return fps.
            */
            SPIC_API const int GetFps() const { return fps; }

            /**
             * @brief Set fps.
             */
            SPIC_API void SetFps(int fps) { this->fps = fps; }

            /**
             * @brief Get sprites.
             * @return sprites.
             */
            SPIC_API const std::vector<std::shared_ptr<Sprite>> GetSprites() const { return sprites; }

            /**
             * @brief Set sprites.
             */
            SPIC_API void SetSprites(std::vector<std::shared_ptr<Sprite>> sprites) { this->sprites = sprites; }

            /**
             * @brief Start playing the image sequence.
             * @param looping If true, will automatically start again when done.
             */
            SPIC_API void Play(bool looping);

            /**
             * @brief Stop playing the image sequence. Whatever sprite was displayed
             *        last will remain shown.
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
             * @brief Called every frame draw after update.
             */
            SPIC_API void OnRender();

            /**
            * @brief Called right before first frame draw.
            */
            SPIC_API void OnStart();

            /**
            * @brief Called every frame draw.
            */
            SPIC_API void OnUpdate();

        private:
            bool running = false;
            int ticks;
            int spriteIndex;
            int fps;
            bool loop = false;
            std::vector<std::shared_ptr<Sprite>> sprites;
            std::unique_ptr<spic::ImageFacade> imageFacade;
    };

}

#endif // ANIMATOR_H_
