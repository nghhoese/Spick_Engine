#ifndef BUTTON_H_
#define BUTTON_H_

#include "UIObject.hpp"
#include <functional>
#include "../Facade_Headers/ButtonFacade.hpp"
#include "Scene.hpp"

namespace spic {

    /**
     * @brief Instances of this class are clickable user interface items.
     */
    class Button : public UIObject {
    public:

        SPIC_API Button(const std::string& asset, const int& x, const int& y, const int& h, const int& w, const std::string& behaviourscript);
        /**
         * @brief Get interactable.
         * @return true if interactable, false otherwise.
         */
        bool GetInteractable() const { return interactable; }

        /**
         * @brief Set interactable.
         */
        void SetInteractable(bool interactable) { this->interactable = interactable; }

        /**
         * @brief This function is called when the button is clicked, which
         *        will trigger a call to the registered onClick member.
         */
        void Click();

        /**
         * @brief Register the onClick handler to be used when the button is clicked.
         * @param callback The function to register, usually a lambda. But this can be
         *        any kind of callable.
         */
        void OnClick(std::function<void()> callback) { onClick = callback; }

        void Render();

    private:
        /**
         * @brief When false, the button will not react to clicks.
         */
        bool interactable;
        bool rendered = false;
        /**
         * @brief The registered click handler.
         */
        std::function<void()> onClick;
        std::unique_ptr<spic::ButtonFacade> buttonFacade;
        std::string _behaviourscript;
    };

}

#endif // BUTTON_H_
