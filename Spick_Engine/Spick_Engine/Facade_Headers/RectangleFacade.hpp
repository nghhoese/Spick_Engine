#pragma once

#define SDL_MAIN_HANDLED
#include "../API_Headers/SpicHeader.hpp"
#include "SceneFacade.hpp"
#include <string>
#include <SDL.h>

namespace spic {

    /**
     * @brief Color represents a red-green-blue color with alpha.
     */
    class RectangleFacade {
    public:
        /**
         * @brief Default constructor representing a white color.
         */
        SPIC_API RectangleFacade();
        void Render();
        void setPosition(int x, int y);
        void setSize(int width, int height);
    private:
        SDL_Rect srcR, destR;
    };

}


