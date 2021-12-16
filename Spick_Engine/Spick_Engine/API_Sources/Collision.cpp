#include "../API_Headers/Collision.hpp"
#include "../API_Headers/Scene.hpp"


std::vector<std::shared_ptr<spic::BoxCollider>> Collision::AABB(spic::GameObject* obj1, std::string tag)
{
    std::vector<std::shared_ptr<spic::BoxCollider>> lijstje = {};
    std::shared_ptr<spic::BoxCollider> collider = std::dynamic_pointer_cast<spic::BoxCollider>(obj1->GetComponent <spic::BoxCollider>());
    if (collider != nullptr) {
        int obj1ColliderWidth = collider->Width();
        int obj1ColliderHeight = collider->Height();
        int obj2ColliderWidth = 1;
        int obj2ColliderHeight = 1;
        auto tranform = obj1->getTransform();
        for (std::shared_ptr<spic::GameObject> obj2 : obj1->getScene().get()->GetGameObjectsByName(tag)) {
                        std::shared_ptr<spic::BoxCollider> collider2 = std::dynamic_pointer_cast<spic::BoxCollider>(obj2->GetComponent <spic::BoxCollider>());
                        if (collider2 != nullptr) {
                            obj2ColliderWidth = collider2->Width();
                            obj2ColliderHeight = collider2->Height();
                            auto tranform2 = obj2->getTransform();
                            if (tranform->position.x + obj1ColliderWidth >= tranform2->position.x &&
                                tranform2->position.x + obj2ColliderWidth >= tranform->position.x &&
                                tranform->position.y + obj1ColliderWidth >= tranform2->position.y &&
                                tranform2->position.y + obj2ColliderHeight >= tranform->position.y
                                ) {
                                lijstje.push_back(collider2);
                            }                                         
                }
            

        }
        return lijstje;
    }

    return lijstje;
}
