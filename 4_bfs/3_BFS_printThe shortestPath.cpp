// print the shortest distance from the source node to given node
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
    vector<int> parent(v, -1);
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = source;
    while (!q.empty())
    {
        int f = q.front();
        cout << f << " ";
        q.pop();
        for (auto nbr : g.l[f])
        {
            if (!visited[nbr])
            {
                parent[nbr] = f;
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
    return parent;
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
    vector<int> parent = bfs(g, 7, 1);
    cout << endl;
    for (auto i : parent)
    {
        cout << i << " ";
    }
    cout << endl;
    int destination = 6;
    cout << destination << " -> ";
    while (destination != parent[1])
    {
        cout << parent[destination] << " -> ";
        destination = parent[destination];
    }
}