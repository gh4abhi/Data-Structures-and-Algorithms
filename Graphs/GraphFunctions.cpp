/*-----------------------------------------------------------------
                    Always beleive you can.
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

//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{
    BOOST;
// I/O Text Files
#ifndef ONLINE_JUDGE
    inOt();
#endif

    ll nodesNum,edgesNum;
    cin>>nodesNum>>edgesNum;
    ll ** edges = new ll*[nodesNum];
    for(ll i=0;i<nodesNum;i++)
    {
        edges[i] = new ll[nodesNum];
        for(ll j=0;j<nodesNum;j++)
        {
            edges[i][j] = 0;
        }
    }
    for(ll i=0;i<edgesNum;i++)
    {
        ll pre,post;
        cin>>pre>>post;
        edges[pre][post] = 1;
        edges[post][pre] = 1;
    }
/*    BFS(edges,nodesNum);
    DFS(edges,nodesNum);*/

    ll startVertex, endVertex;
    cin>>startVertex>>endVertex;

    getPathDFS(edges, nodesNum, startVertex, endVertex);

    for(ll i=0;i<nodesNum;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------







