// Problem Link - https://practice.geeksforgeeks.org/problems/topological-sort/1

#define ll int

class Solution
{
    public:
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<ll> inDegree(V,0);
        for(ll i=0;i<V;i++)
            for(auto j:adj[i])
                inDegree[j]++;
        vector<ll> ans;
        queue<ll> q;
        for(ll i=0;i<V;i++)
            if(inDegree[i]==0)
                q.push(i);
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto i:adj[cur])
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                    q.push(i);
            }
        }
        return ans;
    }
};