#pragma once

#include <SDL.h>
#include "../API_Headers/Sprite.hpp"

namespace spic {

	class AnimatorFacade {
	private:
		int amountOfSprites;
	public:
		AnimatorFacade();
		Uint32 GetTicks();
		Uint32 GetSeconds();
		Uint32 Getsprite();
		void ReplaceSprite(std::shared_ptr<Sprite> sprite);
		void setAmountOfSprites(int value) { this->amountOfSprites = value; };
		int getAmountOfSprites() { return this->amountOfSprites; };
	};
}