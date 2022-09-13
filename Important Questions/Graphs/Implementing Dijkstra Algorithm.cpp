// Problem Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#define ll int

class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
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
};
