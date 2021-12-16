#pragma once

#include "../API_Headers/GameObject.hpp"
#include "../API_Headers/BoxCollider.hpp"

class SPIC_API Collision
{
public:
    /**
	* @brief Check if there is a collison between colliders.
	* @return a collider or nullptr.
	*/
	static std::shared_ptr<spic::BoxCollider> AABB(spic::GameObject* obj1, std::string tag);

private:
	static  std::vector<std::shared_ptr<spic::BoxCollider>> AABB(spic::GameObject* obj1, std::string tag);
};
