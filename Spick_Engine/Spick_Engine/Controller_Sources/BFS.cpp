#include "..\Controller_Headers\BFS.hpp"
//
////spic::BFS::BFS(int size)
////{
////    Edge.resize(size);
////    visited.resize(size);
////}
//
spic::BFS::BFS()
{
}

SPIC_API void spic::BFS::AddEdge(Point node, Point neighbour)
{
    Edge[node].push_back(neighbour);
}


SPIC_API void spic::BFS::Search(Point start, Point end)
{
    std::vector<Point> startingPath; //Totaal gelopen path
    startingPath.push_back(start);

    queue.push_back(startingTuple);
    
    while (queue.size() > 0)
    {
       
    }

    visited[start] = true;
    startingPath.push_back(start);
    //startingTuple[start].push_back(startingPath);









   /* auto s = start;
	for (auto i : visited) i = false;
    std::list<Point> q;
    visited[s] = true;
    q.push_back(s);
    while (!q.empty())
    {
        s = q.front();
        std::cout << s << " ";
        q.pop_front();
        for (auto i : Edge[s])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push_back(i);
            }
        }
    }*/
}

//
//SPIC_API void spic::BFS::AddEdge(int node, int neighbour)
//{
//    //Edge[node].push_back(neighbour); 
//    //Edge[node].
//}
//
//SPIC_API void spic::BFS::Search(int s)
//{
//   /* for (auto i : visited) i = false;
//    std::list<int> q;
//    visited[s] = true;
//    q.push_back(s);
//    while (!q.empty())
//    {
//        s = q.front();
//        std::cout << s << " ";
//        q.pop_front();
//        for (auto i : Edge[s])
//        {
//            if (!visited[i])
//            {
//                visited[i] = true;
//                q.push_back(i);
//            }
//        }
//    }*/
//}
