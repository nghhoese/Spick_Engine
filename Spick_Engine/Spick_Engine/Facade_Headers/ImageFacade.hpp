#pragma once

#include "../API_Headers/SpicHeader.hpp"
#include "SceneFacade.hpp"
#include <string>
#include <SDL.h>
#include "../API_Headers/Rectangle.hpp"

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
        void Createtexture();
        void Render();
        void setPosition(int x, int y);
        void setSize(int width, int height);
        void setPath(std::string path);
        void setRotation(double rotation);
        void setScale(double scale);
        const Rectangle& GetRectangle();
        void SetRectangle(const Rectangle& rec);
    private:
        SDL_Surface* tmpSurface;
        SDL_Texture* _texture;
        SDL_Rect srcR, destR;
        double rotation;
        double scale = 1;
        std::string _path;
    };

}


