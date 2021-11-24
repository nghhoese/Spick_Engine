#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "../API_Headers/SpicHeader.hpp"
#include "../API_Headers/Point.hpp"
#include <map>


namespace spic
{
	class BFS
	{
		std::map<Point, std::vector<Point>> Edge;
		std::map<Point, std::vector<Point>> startingTuple;
		std::vector<std::map<Point, std::vector<Point>>> queue;

		//std::vector<std::vector<Point>> Edge;
		std::map<Point, bool> visited;

	public:
		
		BFS();
		SPIC_API void AddEdge(Point node, Point neighbour);
		SPIC_API void Search(Point start, Point end);
			
	private:
	};
}