#include "..\Controller_Headers\Dijkstra.hpp"


/*
* @brief Allocates memory for adjacency list
*/
spic::Dijkstra::Dijkstra(int AmountOfVertices)
{
	this->AmountOfVertices = AmountOfVertices;
	adj = new std::list<std::pair<int, int>>[AmountOfVertices];
}

void spic::Dijkstra::AddEdge(int u, int v, int w)
{
	adj[u].push_back(std::make_pair(v, w));
	adj[v].push_back(std::make_pair(u, w));
}

void spic::Dijkstra::shortestPath(int src)
{
    // Create a set to store vertices that are being
    // processed
    std::set<std::pair<int, int> > setds;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    std::vector<int> dist(AmountOfVertices, INFINITY);
 
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(std::make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till all shortest distance are finalized
       then setds will become empty    */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        std::pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
 
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;
 
        // 'i' is used to get all adjacent vertices of a vertex
        std::list<std::pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
 
            //    If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance. 
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                if (dist[v] != INFINITY)
                    setds.erase(setds.find(std::make_pair(dist[v], v)));
 
                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(std::make_pair(dist[v], v));
            }
        }
    }
 
    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < AmountOfVertices; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

}
