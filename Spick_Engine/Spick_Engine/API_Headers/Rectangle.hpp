#pragma once

#include "SpicHeader.hpp"

namespace spic {

	/**
	* @brief Struct representing a 2D rectangle.
	*/
	struct SPIC_API Rectangle {
		int x;
		int y;
		int width;
		int height;
	};
}