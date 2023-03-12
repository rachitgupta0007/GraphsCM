#include <iostream>
#include <list>
#include <unordered_map>
#include<vector>
using namespace std;

class Node
{
public:
    string name;
    list<string> nbrs;
    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{
    // all node... hashmap<string, node*>
    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new Node(city);
        }
    }
    void addEdge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir)
        {
            m[y]->nbrs.push_back(x);
        }
    }
    void printAdjList(){
       for(auto cityPair:m){
            auto city = cityPair.first;
            Node *node = cityPair.second;
            cout << city << "---->";
            for (auto nbrs : node->nbrs){
                cout << nbrs << " , ";
            }
            cout << endl;
       }
    }
};

int main()
{
    vector<string> cities = {"Delhi", "London", "New york", "Paris"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("London", "New york");
    g.addEdge("New york", "Paris");
    g.addEdge("New york", "Delhi");
    g.addEdge("London", "Paris");
    g.printAdjList();
}