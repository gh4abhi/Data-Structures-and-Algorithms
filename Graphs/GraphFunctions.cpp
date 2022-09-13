/*-----------------------------------------------------------------
                    Gamers Never Quit.
-------------------------------------------------------------------*/

#include <bits/stdc++.h>
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(),v.end())
#define prt1(a) cout<<a<<" ";
#define prt2(a,b) cout<<a<<" "<<b<<" ";
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define ll long long
#define vec  vector<ll>
#define pb push_back
#define pa vector<pair<ll,ll>>
#define fi first
#define se second
#define siz size()
#define full(a) a.begin(),a.end()
#define max_val INT_MIN
#define min_val INT_MAX;
#define MOD 1000000007


using namespace std;

//----------------------------------------------------------------Necessary Functions---------------------------------------------------------------------------------------
void printvec(vector<ll> v) {
    for(auto x:v)
        cout<<x<<" ";
}

ll fact(ll n)   {
    ll m=1;
    for(ll i=1;i<=n;i++)
        m*=i;
    return m;
}

void inOt()
{
    freopen("input.txt" , "r" , stdin);   // For getting input from input.txt file
    freopen("output.txt" , "w" , stdout);  // Printing the Output to output.txt file
}

ll lcm (ll a,ll b)
{
    return (a / __gcd(a, b)) * b;
}

ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll po = power(x, y / 2, m) % m;
    po = (po * po) % m;

    return (y % 2 == 0) ? po : (x * po) % m;
}


bool isPrime(ll n){
    if (n <= 1)
        return false;

    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

ll modInverse(ll a,ll m)
{
    return power(a, m - 2, m);

}

vector<ll> primeFactors(ll n)
{
    vec v2;
    while (n % 2 == 0)
    {
        v2.pb(2);
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            v2.pb(i);
            n = n/i;
        }
    }

    if (n > 2)
        v2.pb(n);
    return v2;
}
vector<ll> pr;
ll h = 1;
ll st = 19000;
vector<ll> SieveOfEratosthenes(ll n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<ll> vect;
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
        {
            vect.push_back(p);
        }
    return vect;
}
int LCSubStr(char* X, char* Y, int m, int n)
{
    // Create a table to store
    // lengths of longest
    // common suffixes of substrings.
    // Note that LCSuff[i][j] contains
    // length of longest common suffix
    // of X[0..i-1] and Y[0..j-1].

    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
    // longest common substring

    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}


//------------------------------------------------------------------------------ Data Structres ---------------------------------------------------------------------------------

//--------------------------Graphs------------------------------------

//--------------------------Depth First Search Traversal in Graphs------------------------------------

void printDFS(ll**edges, ll startingVertex, bool*visited, ll n)
{
    visited[startingVertex] = true;
    cout<<startingVertex<<" ";
    for(ll i=0;i<n;i++)
    {
        if(i==startingVertex)
        {
            continue;
        }
        if(edges[startingVertex][i]==1)
        {
            if(visited[i]) {
                continue;
            }
            printDFS(edges,i,visited,n);
        }
    }
}


void DFS(ll** edges, ll nodesNum)
{
    bool* visited = new bool[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        visited[i]= false;
    }
    for(ll i=0;i<nodesNum;i++) {
        if(visited[i]==false) {
            printDFS(edges, i, visited, nodesNum);
        }
    }
    cout<<endl;
    delete [] visited;
}

//--------------------------Breadth First Search Traversal in Graphs------------------------------------

void printBFS(ll**edges, ll startingVertex, bool*visited, ll n)
{
    queue<ll> pendingNodes;
    pendingNodes.push(startingVertex);
    pendingNodes.push(-1);
    visited[startingVertex]=true;
    while(pendingNodes.size()!=0)
    {
        ll current = pendingNodes.front();
        pendingNodes.pop();
        if(pendingNodes.size()==0)
        {
            break;
        }
        if(current==-1)
        {
            pendingNodes.push(-1);
            cout<<endl;
            continue;
        }
        cout<<current<<" ";
        for(ll i=0;i<n;i++)
        {
            if(i==current)
            {
                continue;
            }
            if(edges[current][i]==1)
            {
                if(visited[i]!=true)
                {
                    pendingNodes.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

void BFS(ll** edges, ll nodesNum)
{
    bool* visited = new bool[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        visited[i]= false;
    }
    for(ll i=0;i<nodesNum;i++) {
        if(visited[i]==false) {
            printBFS(edges, i, visited, nodesNum);
        }
    }
    cout<<endl;
    delete [] visited;
}

//--------------------------Has Path------------------------------------

// Problem Statement - There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive).
// The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional
// edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
// You want to determine if there is a valid path that exists from vertex start to vertex end.
// Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.

bool hasPathHelper(ll** edges, ll nodesNum, ll startVertex, ll endVertex, bool* visited)
{
   visited[startVertex] = true;
   if(visited[endVertex]==true)
   {
       return true;
   }
   bool curStatus = false;
   for(ll i=0;i<nodesNum;i++)
   {
       if(i==startVertex)
       {
           continue;
       }
       if(edges[startVertex][i]==1)
       {
           if(visited[i]==false)
           {
               curStatus = curStatus or (hasPathHelper(edges,nodesNum,i,endVertex,visited));
           }
       }
   }
   return curStatus;
}

bool hasPath(ll** edges, ll nodesNum, ll startVertex, ll endVertex)
{
    bool* visited = new bool[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        visited[i] = false;
    }
    bool ans = hasPathHelper(edges, nodesNum, startVertex, endVertex, visited);
    delete [] visited;
    return ans;
}

//--------------------------Get Path - DFS------------------------------------

// Problem Statement - Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path
// from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
//Find the path using DFS and print the first path that you encountered.
//V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
//E is the number of edges present in graph G.
//Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
//Note : Save the input graph in Adjacency Matrix.

void getPathDFSHelper(ll** edges, ll nodesNum, ll startVertex, ll endVertex, bool* visited, vector<ll> vect)
{
    visited[startVertex] = true;
    vect.pb(startVertex);
    if(startVertex==endVertex)
    {
        reverse(full(vect));
        for(auto i:vect)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }

    for(ll i=0;i<nodesNum;i++)
    {
        if(edges[startVertex][i]==1)
        {
            if(visited[i]==false)
            {
                getPathDFSHelper(edges,nodesNum,i,endVertex,visited,vect);
            }
        }
    }
    vect.pop_back();
}

void getPathDFS(ll** edges, ll nodesNum, ll startVertex, ll endVertex)
{
    bool* visited = new bool[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        visited[i] = false;
    }
    vector<ll> vect;
    getPathDFSHelper(edges, nodesNum, startVertex, endVertex, visited, vect);
    delete [] visited;
}

//--------------------------Get Path - BFS------------------------------------

// Problem Statement - Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the
// path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
//Find the path using BFS and print the shortest path available.
//V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
//E is the number of edges present in graph G.
//Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
//Note : Save the input graph in Adjacency Matrix.
//Input Format :
//Line 1: Two Integers V and E (separated by space)
//Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
//Line (E+2) : Two integers v1 and v2 (separated by space)

vector<ll> getPathBFSHelper(ll** edges, bool* visited, ll nodesNum, ll startVertex, ll endVertex, vector<pair<ll,vector<ll>>> m)
{
    queue<ll> pendingNodes;
    pendingNodes.push(startVertex);
    visited[startVertex] = true;
    ll flag = 0;
    while(pendingNodes.size()!=0)
    {
        ll current = pendingNodes.front();
        pendingNodes.pop();
        if(current==endVertex)
        {
            flag = 1;
            break;
        }
        for(ll i=0;i<nodesNum;i++)
        {
            if(edges[current][i]==1)
            {
                if(visited[i]==false)
                {
                    pendingNodes.push(i);
                    visited[i] = true;
//                    m.insert(make_pair(current,));
                }
            }
        }
    }
    vector<ll> ans;
    if(flag) {
        for (auto i:m) {
            ans.pb(i.first);
        }
        ans.pb(endVertex);
        reverse(full(ans));
    }
    return ans;
}

void getPathBFS(ll** edges, ll nodesNum, ll startVertex, ll endVertex)
{
    bool* visited = new bool[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        visited[i] = false;
    }
    vector<pair<ll,vector<ll>>> m;
    vector<ll> ans = getPathBFSHelper(edges, visited, nodesNum, startVertex, endVertex, m);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
//--------------------------Is Connected ?------------------------------------

//Given an undirected graph G(V,E), check if the graph G is connected graph or not.
//V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
//E is the number of edges present in graph G.

void isGraphConnectedHelper(ll** edges, ll nodesNum, bool* visited, ll source)
{
    visited[source] = true;
    for(ll i=0;i<nodesNum;i++)
    {
        if(edges[source][i] and !visited[i])
        {
            isGraphConnectedHelper(edges, nodesNum, visited, i);
        }
    }
}

bool isGraphConnected(ll** edges, ll nodesNum)
{
    bool* visited = new bool[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        visited[i] = false;
    }
    isGraphConnectedHelper(edges, nodesNum, visited, 0);

    bool ans = true;
    for(ll i=0;i<nodesNum;i++)
    {
        ans = ans and visited[i];
    }
    delete [] visited;
    return ans;
}

//--------------------------All connected components------------------------------------


// Problem Statement - Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// You need to take input in main and create a function which should return all the connected components.
// And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space).
// Order of different components doesn't matter.

vector<ll> allConnectedComponentsHelper(ll** edges, ll nodesNum, bool* visited, ll source)
{
    vector<ll> component;
    queue<ll> pendingNodes;
    pendingNodes.push(source);
    component.pb(source);
    visited[source] = true;
    while(pendingNodes.size()!=0)
    {
        ll current = pendingNodes.front();
        pendingNodes.pop();
        for(ll i=0;i<nodesNum;i++)
        {
            if(edges[current][i]==1 and !visited[i])
            {
                pendingNodes.push(i);
                visited[i] = true;
                component.pb(i);
            }
        }
    }
    return component;
}

vector<vector<ll>> allConnectedComponents(ll** edges, ll nodesNum)
{
    bool* visited = new bool[nodesNum];
    vector<vector<ll>> graphComponents;
    for(ll i=0; i<nodesNum; i++)
    {
        visited[i] = false;
    }
    for(ll i=0;i<nodesNum;i++)
    {
        if(visited[i]==false)
        {
            graphComponents.pb(allConnectedComponentsHelper(edges, nodesNum, visited, i));
        }
    }
    delete [] visited;
    return graphComponents;
}

//--------------------------Detect Cycle In An Undirected Graph Using DFS------------------------------------

bool findCycleDFSHelper(ll nodesNum, ll currentVertex, ll previousVertex, ll** edges, bool* visited)
{
    visited[currentVertex] = true;
    ll ans = false;
    for(ll i=0;i<nodesNum;i++)
    {
        if(i==currentVertex)
            continue;
        if(edges[currentVertex][i]==1)
        {
            if(visited[i]== true and i!=previousVertex)
                return true;
            if(!visited[i])
                if(findCycleDFSHelper(nodesNum, i, currentVertex, edges, visited))
                    return true;
        }
    }
    return ans;
}

bool findCycleDFS(ll** edges, ll nodesNum)
{
    bool* visited = new bool[nodesNum];
    for(ll i=0;i<nodesNum;i++)
        visited[i] = false;
    bool ans = false;
    for(ll i=0;i<nodesNum;i++)
    {
        if(visited[i]==false)
            if(findCycleDFSHelper(nodesNum,i, -1, edges,visited))
                return true;
    }
    return ans;
}

//--------------------------Detect Cycle In An Undirected Graph Using BFS------------------------------------


bool findCycleBFSHelper(ll**edges, ll nodesNum, ll source, bool* visited)
{
    queue<pair<ll,ll>> pendingNodes;
    pendingNodes.push({source,-1});
    while(pendingNodes.size()!=0)
    {
        pair<ll,ll> current = pendingNodes.front();
        pendingNodes.pop();
        visited[current.first] = true;
        for(ll i=0;i<nodesNum;i++)
        {
            if(i==current.first)
            continue;
            if(edges[current.first][i]==1)
            {
                if(visited[i]==false)
                    pendingNodes.push({i,current.first});
                else
                {
                    if(i!=current.second)
                    return true;
                }    
            }        
        }
    }
    return false;
}

bool findCycleBFS(ll** edges, ll nodesNum)
{
    bool* visited = new bool[nodesNum];

    for(ll i=0;i<nodesNum;i++)
    {
        visited[i] = false;
    }
    for(ll i=0;i<nodesNum;i++)
    {
        if(visited[i]==false)
            if(findCycleBFSHelper(edges, nodesNum, i, visited))
                return true;
    }
        
    delete [] visited;

    return false;

}


//--------------------------Detect Cycle In An Undirected Graph Using Union Find------------------------------------

ll findPar(ll u, vector<ll>& par)
{
    if(par[u]==u)
        return u;
    return par[u] = findPar(par[u], par);
}

bool findCycle(ll numCourses, vector<vector<ll>>& edges) {
    vector<ll> par(numCourses);
    for(ll i=0;i<numCourses;i++)
    {
        par[i] = i;
    }

    ll count = 0, i=0;
    ll n = edges.size();
    for(auto i:edges)
    {
        ll v1 = i[0];
        ll v2 = i[1];
        ll p1 = findPar(v1, par);
        ll p2 = findPar(v2,par);

        if(p1!=p2)
        {
            par[p2] = par[p1];
        }
        else
        {
            return false;
        }
    }
    return true;
}

//--------------------------------Is Graph Bipartite? (BFS)----------------------------------------------------

bool isGraphBipartiteBFSHelper(ll** edges, ll nodesNum, ll source, ll* color)
{
    color[source] = 1;
    queue<ll> pendingNodes;
    pendingNodes.push(source);
    while(pendingNodes.size()!=0)
    {
        ll current = pendingNodes.front();
        pendingNodes.pop();
        for(ll i=0;i<nodesNum;i++)
        {
            if(edges[current][i]==1)
            {
                if(color[i]==-1)
                   {
                        color[i] = !color[current];
                        pendingNodes.push(i);                   
                   }
                else
                {
                    if(color[i]==color[current])
                        return false;   
                }    
            }
        }
    }
    return true;
}


bool isGraphBipartiteBFS(ll** edges, ll nodesNum)
{
    ll* color = new ll[nodesNum];
    
    for(ll i=0;i<nodesNum;i++)
    color[i] = -1;
    
    for(ll i=0;i<nodesNum;i++)
    {
        if(color[i]==-1)
        {
            if(!isGraphBipartiteBFSHelper(edges, nodesNum, i, color))
                return false;
        }
    }
    delete [] color;
    return true;
}

//--------------------------------Is Graph Bipartite? (DFS)----------------------------------------------------

bool isGraphBipartiteDFSHelper(ll** edges, ll nodesNum, ll source, vector<ll>& color)
{
    for(ll i=0;i<nodesNum;i++)
    {
        if(edges[source][i]==1)
        {
            if(color[i]==-1)
            {
                color[i] = 1 - color[source];
                if(!isGraphBipartiteDFSHelper(edges, nodesNum, i, color))
                    return false;
            }
            else
            {
                if(color[i]==color[source])
                    return false;   
            }
        }
    }
    return true;
}


bool isGraphBipartiteDFS(ll** edges, ll nodesNum)
{
    vector<ll> color(nodesNum,-1);
    for(ll i=0;i<nodesNum;i++)
    {
        if(color[i]==-1)
        {
            color[i] = 1;
            if(!isGraphBipartiteDFSHelper(edges, nodesNum, i, color))
                return false;
        }
    }    
    return true;
}

//--------------------------Detect Cycle In A Directed Graph Using DFS------------------------------------

bool findCycleDirectedDFSHelper(ll source, ll nodesNum, vector<ll>& vis, vector<ll>& dfsVis, ll** edges)
{
    vis[source] = 1;
    dfsVis[source] = 1;
    for(ll i=0;i<nodesNum;i++)
    {
        if(edges[source][i]==0)
            continue;
        if(!vis[i])
        {
           if(findCycleDirectedDFSHelper(i,nodesNum,vis,dfsVis,edges))
                return true;
        }
        else
        {
            if(dfsVis[i])
               return true;
        }
    }
    dfsVis[source] = 0;
    return false;
}

bool findCycleDirectedDFS(ll** edges, ll nodesNum)
{
    vector<ll> vis(nodesNum,0);
    vector<ll> dfsVis(nodesNum,0);
    for(ll i=0;i<nodesNum;i++)
         if(!vis[i])
            if(findCycleDirectedDFSHelper(i,nodesNum,vis,dfsVis,edges))
                return true;
    return false;      
}

//--------------------------Topological Sort DFS------------------------------------

void topologicalSortDFSHelper(ll source, ll nodesNum, ll** edges, stack<ll>& st, vector<ll>& vis)
{
    vis[source] = 1;
    for(ll i=0;i<nodesNum;i++)
        if(edges[source][i]==1 and !vis[i])
            topologicalSortDFSHelper(i,nodesNum,edges,st,vis);
    st.push(source);
}

vector<ll> topologicalSortDFS(ll** edges, ll nodesNum)
{
    stack<ll> st;
    vector<ll> vis(nodesNum,0);
    for(ll i=0;i<nodesNum;i++)
        if(!vis[i])
            topologicalSortDFSHelper(i,nodesNum,edges,st,vis);
    vector<ll> topoSort;
    while(st.size())
        topoSort.pb(st.top()), st.pop();
    return topoSort;
}

//--------------------------Topological Sort BFS------------------------------------

vector<ll> topologicalSortBFS(ll** edges, ll nodesNum)
{
    vector<ll> inDegree(nodesNum,0);
    for(ll i=0;i<nodesNum;i++)
        for(ll j=0;j<nodesNum;j++)
            if(edges[i][j]==1)
                inDegree[j]++;
    queue<ll> q;
    for(ll i=0;i<nodesNum;i++)
        if(inDegree[i]==0)
            q.push(i);
    vector<ll> ans;
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        ans.pb(cur);
        for(ll i=0;i<nodesNum;i++)
        {
            if(edges[cur][i]==1)
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                    q.push(i);
            }
        }
    }
    return ans;
}

//--------------------------Shortest Path in Undirected Graph with Unit Weights(BFS)------------------------------------

vector<ll> shortestDistance(ll source, vector<vector<ll>> &adj, ll n)
{
    queue<ll> q;
    vector<ll> dis(n,1e18);
    vector<ll> vis(n,0);
    dis[source] = 0;
    q.push(source);
    vis[source] = 1;
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(auto i:adj[cur])
        {
            if(vis[i]==0)
            {
                vis[i] = 1;
                dis[i] = dis[cur] + 1;
                q.push(i);
            }
            else
                dis[i] = min(dis[i],dis[cur]+1);
        }
    }
    return dis;
}

//--------------------------Shortest Path in Directed Weighted Acyclic Graph------------------------------------

void topoSortWeighted(ll source, vector<vector<pair<ll,ll>>> &adj, vector<ll> &vis, ll n, stack<ll> &st)
{
    vis[source] = 1;
    for(auto i:adj[source])
        if(vis[i.first]==0)
            topoSortWeighted(i,adj,vis,n,st);
    st.push(source);
}

vector<ll> shortestPathDWAG(ll source, vector<vector<pair<ll,ll>>> &adj, ll n)
{
    stack<ll> st;
    vector<ll> vis(n,0);
    for(ll i=0;i<n;i++)
        if(vis[i]==0)
            topoSortWeighted(i,adj,vis,n,st);
    vector<ll> dis(n,1e18);
    dis[source] = 0;
    while(st.size())
    {
        auto cur = st.top();
        st.pop();
        if(dis[cur]!=1e18)
        {
            for(auto i:adj[cur])
            {
                dis[i.first] = min(dis[i.first],dis[cur] + i.second);
            }
        }
    }
    return dis;
}

//--------------------------Dijkstra's Algorithm------------------------------------

vector <int> dijkstra(int n, vector<vector<int>> adj[], int source)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,source});
    vector<ll> dis(n,INT_MAX);
    dis[source] = 0;
    while(pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        for(auto j:adj[cur.second])
        {
            if(dis[cur.second] + j[1]< dis[j[0]])
            dis[j[0]] = dis[cur.second] + j[1], pq.push({dis[cur.second] + j[1], j[0]});
        }
    }
    return dis;
}

//--------------------------Kosaraju's Algorithm for Strongly Connected Components------------------------------------

void topoSort(vector<vector<ll>> &adj, ll n, ll start, vector<ll>& vis, stack<ll> &st)
{
    vis[start] = 1;
    for(auto i:adj[start])
        if(vis[i]==0)
            topoSort(adj,n,i,vis,st);
    st.push(start);
}

void revDFS(vector<vector<ll>> &adj, ll n, ll start, vector<ll>& vis, vector<ll>& vect)
{
    vis[start] = 1;
    vect.pb(start);
    for(auto i:adj[start])
        if(vis[i]==0)
            revDFS(adj,n,i,vis,vect);
}

vector<vector<ll>> kosaraju(vector<vector<ll>> &adj, ll n)
{
    vector<vector<ll>> ans;
    stack<ll> st;
    vector<ll> vis(n,0);
    for(ll i=0;i<n;i++)
        if(vis[i]==0)
            topoSort(adj,n,i,vis,st);
    vector<vector<ll>> transpose(n);
    for(ll i=0;i<n;i++)
    {
        vis[i] = 0;
        for(auto j:adj[i])
            transpose[j].push_back(i);
    }

    while(st.size())
    {
        ll node = st.top();
        st.pop();
        vector<ll> vect;
        if(vis[node]==0)
            revDFS(transpose,n,node,vis,vect);
        if(vect.size())
            ans.pb(vect);
    }
    return ans;
}

//--------------------------Kruskals Algorithm using Union Find Algorithm------------------------------------

// Problem Statement - Given an undirected, connected and weighted graph G(V, E) with V number of vertices
// (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format - v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1<=v2 i.e. print
// the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.


class Edge{
public:
    ll source;
    ll dest;
    ll weight;
};

bool cmp(Edge e1, Edge e2)
{
    return e1.weight<e2.weight;
}

ll findParent(ll v, ll* parent)
{
    if(parent[v]==v)
        return v;
    return findParent(parent[v],parent);
}

void kruskalsAlgoUsingUnionFind(Edge* input, ll nodesNum, ll edgesNum)
{
    // Now sort the edges on the basis of weight in ascending order.
    sort(input, input+edgesNum, cmp);
    Edge* output = new Edge[nodesNum-1];

    ll* parent = new ll[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        parent[i] = i;
    }

    ll count = 0, i=0;
    while(count!=nodesNum-1)
    {
        Edge currentEdge = input[i];
        ll sourceParent = findParent(currentEdge.source, parent);
        ll destParent = findParent(currentEdge.dest, parent);
        if(sourceParent!=destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[destParent] = parent[sourceParent];
        }
        i++;
    }

    for(ll i=0;i<nodesNum-1;i++)
    {
        if(output[i].source<output[i].dest)
        {
            cout<<output[i].source<<" "<<input[i].dest<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<input[i].source<<" "<<output[i].weight<<endl;
        }
    }
}

//--------------------------Kruskals Algorithm using Union By Rank and Path Compression------------------------------------



//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{
    BOOST;
    ll n;
    cin>>n;
    ll e;
    cin>>e;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<e;i++)
    {
        ll a, b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    kosaraju(adj,n);
/*    ll nodesNum,edgesNum;
    cin>>nodesNum>>edgesNum;

    ll ** edges = new ll*[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        edges[i] = new ll[nodesNum];
        for(ll j=0;j<nodesNum;j++)
        {
            edges[i][j] = 0;
        }
    }*/
    // For Undirected Graph
    /*for(ll i=0;i<edgesNum;i++)
    {
        ll pre,post;
        cin>>pre>>post;
        edges[pre][post] = 1;
        edges[post][pre] = 1;
    }*/
    // For Directed Graph
/*    for(ll i=0;i<edgesNum;i++)
    {
        ll pre,post;
        cin>>pre>>post;
        edges[post][pre] = 1;
    }*/

/*    BFS(edges,nodesNum);
    DFS(edges,nodesNum);*/

/*for(auto i:topologicalSortDFS(edges,nodesNum))
    cout<<i<<" ";*/

/*
Edge* input = new Edge[edgesNum];

for(ll i=0;i<nodesNum;i++)
{
    ll s,d,w;
    cin>>s>>d>>w;
    input[i].source = s;
    input[i].dest = d;
    input[i].weight = w;
}

    kruskalsAlgoUsingUnionFind(input, nodesNum, edgesNum);*/

/*
    for(ll i=0;i<nodesNum;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;*/
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------






