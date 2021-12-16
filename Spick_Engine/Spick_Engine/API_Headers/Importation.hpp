#pragma once

#include <iostream>
#include "SpicHeader.hpp"
#include "Point.hpp"
#include "KeyCode.hpp"
#include "MouseButton.hpp"

namespace spic {

    /**
    * @brief Instance of the importation class (Input).
    */
    class Importation {
    public:
        /**
        * @brief Default constructor of Importation (Input).
        */
        SPIC_API Importation();

        /**
        * @brief Is any key or mouse button currently held down? (Read Only)
        */
        SPIC_API bool AnyKey();

        /**
        * @brief Returns true the first frame the user hits any key or mouse button. (Read Only)
        */
        SPIC_API bool AnyKeyDown();

        /**
        * @brief The current mouse position in pixel coordinates. (Read Only)
        */
        SPIC_API const Point MousePosition();

        /**
        * @brief Returns the value of the virtual axis identified by axisName.
        */
        double GetAxis(); 

         /**
        * @brief Returns true while the user holds down the key identified by keycode.
        */
        SPIC_API bool GetKey(KeyCode key);

        /**
        * @brief Returns true during the frame the user starts pressing down the key identified by keycode.
        */
        SPIC_API bool GetKeyDown(KeyCode key);

        /**
        * @brief Returns true during the frame the user releases the key identified by keycode.
        */
        SPIC_API bool GetKeyUp(KeyCode key);

        /**
        * @brief Returns whether the given mouse button is held down.
        */
        SPIC_API bool GetMouseButton(MouseButton which);

        /**
        * @brief Returns true during the frame the user pressed the given mouse button.
        */
        SPIC_API bool GetMouseButtonDown(MouseButton which);

        /**
        * @brief Returns true during the frame the user releases the given mouse button.
        */
        SPIC_API bool GetMouseButtonUp(MouseButton which);

        /**
        * @brief Returns the mouse position.
        * @return the mouse position (Point).
        */
        SPIC_API Point GetMousePosition();
       
    private:
        
    };
}