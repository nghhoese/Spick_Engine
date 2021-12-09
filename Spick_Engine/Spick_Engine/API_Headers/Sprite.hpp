#pragma once

#include "SpicHeader.hpp"
#include "Component.hpp"
#include "Color.hpp"
#include <string>
#include "../Facade_Headers/ImageFacade.hpp"
#include "../Facade_Headers/SceneFacade.hpp"
#include "GameObject.hpp"
#include "Scene.hpp"

namespace spic {

    /**
     * @brief A component representing a sprite (small image)
     */
    class SPIC_API Sprite : public Component {
    public:
        /**
         * @brief Constructor.
         */
         Sprite();

        /**
         * @brief Get sprite.
         * @return sprite.
         */
        const std::string& GetSprite() const { return sprite; }

        /**
         * @brief Set sprite.
         */
        void SetSprite(const std::string& sprite);

        /**
         * @brief Get color.
         * @return color.
         */
        const Color& GetColor() const { return color; }

        /**
         * @brief Set color.
         */
        void SetColor(Color& color) { this->color = color; }

        /**
         * @brief Get flipX.
         * @return flipX.
         */
        const bool GetFlipX() const { return flipX; }

        /**
         * @brief Set flipX.
         */
        void SetFlipX(bool flipX) { this->flipX = flipX; }

        /**
         * @brief Get flipY.
         * @return flipY.
         */
        const bool GetFlipY() const { return flipY; }

        /**
         * @brief Set flipY.
         */
        void SetFlipY(bool flipY) { this->flipY = flipY; }

        /**
         * @brief Get sortingLayer.
         * @return sortingLayer.
         */
        const int GetSortingLayer() const { return sortingLayer; }

        /**
         * @brief Set sortingLayer.
         */
        void SetSortingLayer(int sortingLayer) { this->sortingLayer = sortingLayer; }

        /**
         * @brief Get orderInLayer.
         * @return orderInLayer.
         */
        const int GetOrderInLayer() const { return orderInLayer; }

        /**
         * @brief Set orderInLayer.
         */
        void SetOrderInLayer(int orderInLayer) { this->orderInLayer = orderInLayer; }

        /**
         * @brief Get width.
         * @return width.
         */
        const int GetWidth() const { return width; }

        /**
         * @brief Set width.
         */
        void SetWidth(int width) { this->width = width; }

        /**
         * @brief Get height.
         * @return height.
         */
        const int GetHeight() const { return height; }

        /**
         * @brief Set height.
         */
        void SetHeight(int height) { this->height = height; }

        /**
         * @brief Get offsetX.
         * @return offsetX.
         */
        const int GetOffsetX() const { return offsetX; }

        /**
         * @brief Set offsetX.
         */
        void SetOffsetX(int offsetX) { this->offsetX = offsetX; }

        /**
         * @brief Get offsetY.
         * @return offsetY.
         */
        const int GetOffsetY() const { return offsetY; }

        /**
         * @brief Set offsetY.
         */
        void SetOffsetY(int offsetY) { this->offsetY = offsetY; }

        /**
        * @brief Called when component is created even if component is disabled. View as constructor.
        */
        void OnAwake();

        /**
         * @brief Called right before first frame draw.
         */
        void OnStart();

        /**
         * @brief Called every frame draw.
         */
        void OnUpdate();

        /**
         * @brief Called every frame draw after update.
         */
         void OnRender();
         void setStill(bool still) { this->still = still; }
         void OnClick();

         void SetPlayerBool(bool value);
         void DestroyImage();
         void SetRendered(bool rendered) { this->rendered = rendered; };

    private:
        Transform transform;
        std::string sprite;
        Color color;
        bool flipX;
        bool flipY;
        int sortingLayer;
        int orderInLayer;
        int width;
        int height;
        int offsetX;
        int offsetY;
        bool still = true;
        bool rendered = false;
        bool player = false;
        std::unique_ptr<spic::ImageFacade> imageFacade;
    };

}
