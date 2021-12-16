#pragma once

#define SDL_MAIN_HANDLED
#include "../API_Headers/SpicHeader.hpp"
#include "SceneFacade.hpp"
#include <string>
#include <SDL.h>

namespace spic {

    class RectangleFacade {
    public:
        SPIC_API RectangleFacade();
        void Render();
        void setPosition(int x, int y);
        void setSize(int width, int height);
    private:
        SDL_Rect srcR, destR;
    };

}


