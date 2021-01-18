#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Graph
{
    ll V; // Number of vertices
    list <ll> *adj;
    public :
    Graph(ll V); // Constructor
    void addEdge(ll v, ll u);
    void BFS(ll s);
};

Graph::Graph(ll V)
{
    this->V = V;
    adj = new list<ll>[V];
}

void Graph::addEdge(ll v , ll w)
{
    adj[v].push_back(w); // For directed graph.
}

void Graph::BFS(ll s)
{
    bool *visited = new bool[V];
    for(ll i=0;i<V;i++)
    {
        visited[i] = false;
    }
    
    list <ll>queue ;
    visited[s] = true;
    queue.push_back(s);
    list<ll>::iterator i; // For pointing the adjacent vertices of a particular vertex
    while(!queue.empty())
    {
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(i = adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
            visited[*i] = true;
            queue.push_back(*i);
        
            }
            }
    }
}
int main()
{
     Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
