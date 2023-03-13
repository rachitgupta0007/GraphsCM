// find the shortest distance from the source node to all the nodes
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *l;
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int x, int y, bool undir = true)
    {
        l[x].push_back(y);
        if (undir)
            l[y].push_back(x);
    }
};
vector<int> bfs(Graph g, int v, int source)
{
    vector<int> distance(v, 0);
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int f = q.front();
        cout << f << " ";
        q.pop();
        for (auto nbr : g.l[f])
        {
            if (!visited[nbr])
            {
                distance[nbr] = distance[f] + 1;
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
    return distance;
}
int main()
{
    Graph g(7);
    g.addEdge(1, 2);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    vector<int> v = bfs(g, 7, 1);
    cout << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
}