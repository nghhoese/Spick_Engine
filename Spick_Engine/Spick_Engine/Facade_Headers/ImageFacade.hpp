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
        SPIC_API ImageFacade();
        void Createtexture(SDL_Renderer* renderer);
        void Render(SDL_Renderer* renderer);
        void setPosition(int x, int y);
        void setSize(int width, int height);
        void setPath(std::string path);
        void setRotation(double rotation);
    private:
        SDL_Texture* _texture;
        SDL_Rect srcR, destR;
        double rotation;
        std::string _path;
    };

}


