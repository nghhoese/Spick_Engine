#pragma once
#include "GameObject.hpp"
#include "Point.hpp"
#include "Collision.hpp"
#include "SpicHeader.hpp"

namespace spic {

	class SPIC_API AI {
		public:
			AI(spic::GameObject persuerGameObject, spic::GameObject escapeeGameObject, double speed, bool wallAvoidanceActivated, bool forceActivated);
			spic::Point Wander();
			spic::Point Persue();
			spic::Point Seek(spic::Point target);
			spic::Point WallAvoidance(spic::Point target);
			spic::Point GetSight() { return this->sight; };
			void Update(spic::GameObject persuerGameObject, spic::GameObject escapeeGameObject);

		private:
			spic::Point vel;
			spic::Point acc;
			std::unique_ptr<spic::GameObject> persuer;
			std::unique_ptr<spic::GameObject> escapee;
			spic::Point sight;
			double wandertheta;
			double speed;
			bool wallAvoidanceActivated;
			bool forceActivated;
	};
}

