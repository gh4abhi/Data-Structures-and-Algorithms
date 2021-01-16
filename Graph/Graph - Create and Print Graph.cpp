#include<bits/stdc++.h>
#define ll long long
using namespace std;

void addEdge(vector<ll> adj[] , ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<ll> adj[], ll size)
{
  for(ll i=0;i<size;i++)
  {
      cout<<"Adjacency list of vertex "<<i<<" is - \nhead";
      for(auto j: adj[i])
      {
          cout<<"-> "<<j;
      }
      cout<<"\n";
  }
}

int main()
{
    ll size;
    cout<<"Enter the number of vertices in the graph";
    cin>>size;
    vector<ll> adj[size];
    while(1)
    {
        char ans;
        cout<<"Do you want to connect some vertices of the graph (y/n)";
        cin>>ans;
        if(ans=='n')
        {
            break;
        }
        ll u,v;
        cout<<"\nEnter the first vertex";
        cin>>u;
        cout<<"\nEnter the second vertex";
        cin>>v;
        addEdge(adj,u,v);
    }
    cout<<"Adjacency lists of vertices of graph are - \n";
    printGraph(adj,size);
    return 0;
}
