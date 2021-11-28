#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>
#include "SpicHeader.hpp"


struct Transform;

namespace spic {
    class GameObject;//TODO: Check voor verdere ambiguous forward declarations.
    /**
     * @brief Base class for all components.
     */
    class Component {
        public:
            /**
             * @brief Getter for active status.
             * @return true if active, false otherwise.
             */
            bool Active() const { return active; }

            /**
             * @brief flag New active status.
             */
            void Active(bool flag) { active = flag; }

            /**
            * @brief Getter for component name.
            * @return string with name.
            */
            std::string Name() const { return name; }

            /**
             * @brief Setter for component name.
             */
            void Name(std::string newName) { name = newName; }

            /**
            * @brief Called when component is created even if component is disabled. View as constructor.
            */
             virtual void OnAwake() = 0;

            /**
             * @brief Called right before first frame draw.
             */
            virtual void OnStart() = 0;

            /**
             * @brief Called every frame draw.
             */
            virtual void OnUpdate() = 0;

            /**
             * @brief Called every frame draw after update.
             */
            virtual void OnRender() = 0;
            void SetGameObject(GameObject* _gameObject) { gameobject = _gameObject; }
            GameObject* GetGameObject() { return gameobject; }

        private:
            /**
             * @brief Active status.
             */
            bool active;
            GameObject* gameobject;
            std::string name;
            std::string tag;
    };

}

#endif // COMPONENT_H_
