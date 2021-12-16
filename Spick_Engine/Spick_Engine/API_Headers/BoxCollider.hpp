#pragma once

#include "SpicHeader.hpp"
#include "Component.hpp"
#include "Color.hpp"
#include <string>
#include "../Facade_Headers/ImageFacade.hpp"
#include "../Facade_Headers/SceneFacade.hpp"
#include "GameObject.hpp"
#include "Scene.hpp"
#include "Collider.hpp"
#include "../Facade_Headers/RectangleFacade.hpp"


namespace spic {

    /**
    * @brief A collider which represents a rectangular collision area.
    */
    class SPIC_API BoxCollider : public Collider {
        public:
            BoxCollider();
            /**
             * @brief The collider's width
             * @return The current width
             */
            double Width() const { return width; }

            /**
             * @brief The collider's width
             * @param newWidth The desired width
             */
            void Width(double newWidth) { width = newWidth; }

            /**
             * @brief The collider's height
             * @return The current height
             */
            double Height() const { return height; }

            /**
             * @brief The collider's height
             * @param newHeight The desired height
             */
            void Height(double newHeight) { height = newHeight; }
            void ShowBoxBool(bool newHeight) { showBox = newHeight; }
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
            void OnClick();
            void SetPlayerBool(bool value) { player = value;  }
           
        private:
            double width;
            double height;
            bool showBox = true;
            bool player = false;
            std::unique_ptr<spic::RectangleFacade> rectangleFacade;

    };

}


