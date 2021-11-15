#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>
#include "SpicHeader.hpp"
#include "Transform.hpp"
#include "Component.hpp"

namespace spic {
    class Scene;
    /**
     * @brief Any object which should be represented on screen.
     */
    class GameObject {
        public:
            /**
             * @brief Get name.
             * @return name.
             */
            const std::string& GetName() const { return name; }

            /**
             * @brief Get tag.
             * @return tag.
             */
            const std::vector<std::string>& GetTags() const { return tags; }

            /**
             * @brief Add tag.
             */
            const void AddTag(const std::string& tag) { tags.push_back(tag); }

            /**
             * @brief Remove tag.
             */
            const void RemoveTag(const std::string& tag) { remove(tags.begin(), tags.end(), tag); };

            /**
             * @brief Finds a GameObject by name and returns it.
             * @param name The name of the GameObject you want to find.
             * @return Pointer to GameObject, or nullptr if not found.
             */
            static std::shared_ptr<GameObject> Find(const std::string& name);

            /**
             * @brief Returns a vector of active GameObjects tagged tag. Returns empty
             *        vector if no GameObject was found.
             * @param tag The tag to find.
             * @return std::vector of GameObject pointers. No ownership.
             */
            static std::vector<std::shared_ptr<GameObject>> FindGameObjectsWithTag(const std::string& tag);

            /**
             * @brief Returns one active GameObject tagged tag. Returns nullptr if no GameObject was found.
             * @param tag The tag to find.
             * @return Pointer to GameObject, or nullptr if not found.
             */
            static std::shared_ptr<GameObject> FindWithTag(const std::string& tag);

            /**
             * @brief Returns the first active loaded object of Type type.
             */
            template<class T>
            static std::shared_ptr<GameObject> FindObjectOfType(bool includeInactive = false) {
                // ... implementation here
            }

            /**
             * @brief Gets a list of all loaded objects of Type type.
             */
            template<class T>
            static std::shared_ptr<GameObject> FindObjectsOfType(bool includeInactive = false) {
                // ...implementation here
            }

            /**
             * @brief Removes a GameObject from the administration.
             * @details TODO What happens if this GameObject is a parent to others? What happens
             *          to the Components it possesses?
             * @param obj The GameObject to be destroyed. Must be a valid pointer to existing Game Object.
             * @exception A std::runtime_exception is thrown when the pointer is not valid.
             */
            static void Destroy(std::shared_ptr<GameObject> obj);

            /**
             * @brief Removes a Component.
             * @details Will search for the Component among the GameObjects.
             * @param obj The Component to be removed.
             */
            static void Destroy(Component* obj);

            /**
             * @brief Constructor.
             * @details The new GameObject will also be added to a statically
             *          available collection, the administration.  This makes the
             *          Find()-functions possible.
             * @param name The name for the game object.
             */
           GameObject(const std::string& name);

            /**
             * @brief Does the object exist? TODO wat wordt hiermee bedoeld?
             */
            operator bool();

            /**
             * @brief Compare two GameObjects.
             * @param other The other object to compare this one with.
             * @return true if not equal, false otherwise.
             */
            bool operator!=(const GameObject& other);

            /**
             * @brief Compare two GameObjects
             * @param other The other object to compare this one with.
             * @return true if equal, false otherwise.
             */
            bool operator==(const GameObject& other);

            /**
             * @brief Add a Component of the specified type. Must be a valid
             *        subclass of Component. The GameObject assumes ownership of
             *        the Component.
             * @details This function places a pointer to the component in
             *          a suitable container.
             * @param component Reference to the component.
             */
            template<class T>
            void AddComponent(std::shared_ptr<T> component) {
                // ... implementation here
            }

            /**
             * @brief Get the first component of the specified type. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             */
            template<class T>
            std::shared_ptr<Component> GetComponent() const {
                // ... implementation here
            }

            /**
             * @brief Get the first component of the specified type from
             *        contained game objects. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             */
            template<class T>
            std::shared_ptr<spic::Component> GetComponentInChildren() const {
                // ... implementation here
            }

            /**
             * @brief Get the first component of the specified type from
             *        the parent game object. Must be
             *        a valid subclass of Component.
             * @return Pointer to Component instance.
             */
            template<class T>
            std::shared_ptr<spic::Component> GetComponentInParent() const {
                // ... implementation here
            }

            /**
             * @brief Get all components of the specified type. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             */
            template<class T>
            std::vector<std::shared_ptr<spic::Component>> GetComponents() const {
                // ... implementation here
            }

            /**
             * @brief Get all components of the specified type from
             *        contained game objects. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             */
            template<class T>
            std::vector<std::shared_ptr<spic::Component>> GetComponentsInChildren() const {
                // ... implementation here
            }

            /**
             * @brief Get all components op the specified type from
             *        the parent game object. Must be
             *        a valid subclass of Component.
             * @return Vector with pointers to Component instances.
             */
            template<class T>
            std::vector<std::shared_ptr<spic::Component>> GetComponentsInParent() const {
                // ... implementation here
            }

            /**
             * @brief Activates/Deactivates the GameObject, depending on the given true or false value.
             * @param active Desired value.
             */
            void SetActive(bool flag) { active = flag; }

            /**
             * @brief Returns whether this game object is itself active.
             * @return true if active, false if not.
             */
            bool IsActiveSelf() const { return active; }

            /**
             * @brief Returns whether this game component is active, taking its parents
             *        into consideration as well.
             * @return true if game object and all of its parents are active,
             *        false otherwise.
             */
            bool IsActiveInWorld() const;

            /**
             * @brief This function is called by the engine to update the scene on the engine.
             */
            void Update();

            /**
             * @brief This function is called by the engine to render the scene on the engine.
             */
            void Render();

        private:
            std::string name;
            std::vector<std::string> tags;
            bool active;
            int layer;
            Transform transform;
            std::shared_ptr<Scene> scene;
            std::shared_ptr<GameObject> parent;
            static std::vector<GameObject> children;
            std::vector<std::shared_ptr<spic::Component>> components;
    };

}

#endif // GAMEOBJECT_H_
