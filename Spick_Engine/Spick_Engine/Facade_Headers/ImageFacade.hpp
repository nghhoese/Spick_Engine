#pragma once

#include "../API_Headers/SpicHeader.hpp"
#include <string>
#include <SDL.h>

namespace spic {

    /**
     * @brief Color represents a red-green-blue color with alpha.
     */
    class ImageFacade {
    public:
        /**
         * @brief Default constructor representing a white color.
         */
        SPIC_API ImageFacade(std::string path, int width,int height);
        void Createtexture(SDL_Renderer* renderer);
        void Render(SDL_Renderer* renderer);



    private:
        SDL_Texture* _texture;
        SDL_Rect srcR, destR;
        std::string _path;
    };

}


