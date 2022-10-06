// Problem Link - https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?page=1&company[]=Amazon&category[]=Dynamic%20Programming&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    ll findMax(ll arr[], ll n, ll ind, vector<ll> &dp)
    {
        if(ind>=n)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        return dp[ind] = max(findMax(arr,n,ind+1,dp), arr[ind] + findMax(arr,n,ind+2,dp));
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<ll> dp(n,-1);
        return findMax(arr,n,0,dp);
    }
};
