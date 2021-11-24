#pragma once

#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <limits>

namespace spic 
{
	class Dijkstra 
	{
		int AmountOfVertices;

		std::list<std::pair<int, int>>* adj;

	public:
		Dijkstra(int AmountOfVertices);

		/**
		 * @brief Function to add an edge to graph
		 */
		void AddEdge(int u, int v, int w);

		/**
		 * @brief Function to add an edge to graphprints shortest path from s
		 */
		void shortestPath(int s);

	private:

	};
}
