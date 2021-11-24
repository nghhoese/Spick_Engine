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
		//std::vector<std::vector<int, int>> Edge;
		//std::vector<unsigned char> visited;
	public:
		
		BFS();
		SPIC_API void AddEdge(Point node, Point neighbour);
		SPIC_API void Search(Point start);

	private:
	};
}