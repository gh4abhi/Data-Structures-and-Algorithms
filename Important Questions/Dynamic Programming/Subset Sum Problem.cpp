// Problem Link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?page=1&company[]=Amazon&category[]=Dynamic%20Programming&sortBy=submissions

#define ll int

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        ll n = arr.size();
        vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
        for(ll i=0;i<n+1;i++)
            dp[i][0] = 1;
        for(ll i=1;i<sum+1;i++)
            dp[n][i] = 0;
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=1;j<sum+1;j++)
            {
                if(j>=arr[i])
                    dp[i][j] = dp[i][j] or dp[i+1][j-arr[i]];
                dp[i][j] = dp[i][j] or dp[i+1][j];
            }
        }
        return dp[0][sum];
    }
};
