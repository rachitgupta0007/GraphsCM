// Find Center of Star Graph
//         There is an undirected star graph consisting of n nodes labeled from 1 to n.A star graph is a graph where there is one center node and exactly n -
//     1 edges that connect the center node with every other node.

//     You are given a 2D integer array edges where each edges[i] = [ ui, vi ] indicates that there is an edge between the nodes ui and vi.Return the center of the given star graph.

#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>> edges)
{
    int V = edges.size();
    list<int> *l = new list<int>[V + 1];

    for (int i = 0; i < V - 1; i++)
    {
        int x = edges[i][0], y = edges[i][1];
        l[x].push_back(y);
        l[y].push_back(x);
    }
    // std::cout << "my user log";
    for (int i = 1; i <= V + 1; i++)
    {
        if (l[i].size() > 1)
        {
            return i;
        }
    }
}