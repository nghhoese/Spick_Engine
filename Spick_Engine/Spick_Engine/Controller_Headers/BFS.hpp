#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "../API_Headers/SpicHeader.hpp"
#include "../API_Headers/Point.hpp"


namespace spic
{
	class BFS
	{
		std::vector<std::vector<struct spic::Point, struct spic::Point>> Edge;
		std::vector<unsigned char> visited;
	public:
		
		BFS();
		SPIC_API void AddEdge(struct spic::Point node, struct spic::Point neighbour);
		SPIC_API void Search(int start);

	private:
	};
}