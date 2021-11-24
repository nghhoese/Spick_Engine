#include "..\Controller_Headers\BFS.hpp"

//spic::BFS::BFS(int size)
//{
//    Edge.resize(size);
//    visited.resize(size);
//}

spic::BFS::BFS()
{
}
//
SPIC_API void spic::BFS::AddEdge(struct spic::Point node, struct spic::Point neighbour)
{
    //Edge[node].push_back(neighbour); 
    //Edge[node].
}

SPIC_API void spic::BFS::Search(int s)
{
   /* for (auto i : visited) i = false;
    std::list<int> q;
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
