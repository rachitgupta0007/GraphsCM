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
        l = new list<int>[v];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }
};

void BFS(Graph g, int v, int source)
{
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int front = q.front();
        cout << front << " ";
        q.pop();
        for (auto nbr : g.l[front])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
}

int main()
{
    Graph g(7);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(0, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(3, 5);

    BFS(g, 7, 0);
}