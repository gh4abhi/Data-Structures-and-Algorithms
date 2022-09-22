// Problem Link - https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#define ll int

class Solution{
    public:
    
    void topoSort(vector<vector<ll>> &adj, ll source, vector<ll> &vis, vector<ll> &vect)
    {
        vis[source] = 1;
        for(auto i:adj[source])
            if(vis[i]==0)
                topoSort(adj,i,vis,vect);
        vect.push_back(source);
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<vector<ll>> adj(K);
        for(ll i=0;i<N-1;i++)
        {
            ll len = min(dict[i].length(),dict[i+1].length());
            for(ll j=0;j<len;j++)
            {
                if(dict[i][j]!=dict[i+1][j])
                {
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        vector<ll> vis(K,0);
        vector<ll> vect;
        for(ll i=0;i<K;i++)
            if(vis[i]==0)
                topoSort(adj,i,vis,vect);
        reverse(vect.begin(),vect.end());
        string ans = "";
        for(auto i:vect)
            ans += char(i+'a');
        return ans;
    }
};