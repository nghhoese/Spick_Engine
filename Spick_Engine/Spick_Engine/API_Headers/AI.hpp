#pragma once
#include "GameObject.hpp"
#include "Point.hpp"
#include "Collision.hpp"
#include "SpicHeader.hpp"

namespace spic {

	/**
	* @brief Contains force driven entity methods with optional objectavoidance.
	*/
	class SPIC_API AI {
		public:
			/**
            * @brief Constructor.
            */
			AI(spic::GameObject persuerGameObject, spic::GameObject escapeeGameObject, double speed, bool gameObjectAvoidanceActivated);
			
			/**
			* @brief Calculate random wander target for persuerGameObject.
			* @return Point target.
			*/
			spic::Point Wander();

			/**
			* @brief Calculate persuer target.
			* @return Point prediction
			*/
			spic::Point Persue();

			/**
			* @brief Get the heading Point.
			* @return Point sight
			*/
			spic::Point GetSight() { return this->sight; };

			/**
			* @brief Updates the persuer and escapee game objects.
			*/
			void Update(spic::GameObject persuerGameObject, spic::GameObject escapeeGameObject);

			/**
			* @brief Set the name of the collision object. If not set, collision will not work.
			*/
			void SetCollisionObjectName(const std::string& objectName) { this->collisionObjectName = objectName; };
		private:
			spic::Point vel;
			spic::Point acc;
			std::unique_ptr<spic::GameObject> persuer;
			std::unique_ptr<spic::GameObject> escapee;
			spic::Point sight;
			double wandertheta;
			double speed;
			bool gameObjectAvoidanceActivated;
			bool forceActivated;
			std::string collisionObjectName;
			spic::Point GameObjectAvoidance(spic::Point target);
			spic::Point Seek(spic::Point target);
	};
}

