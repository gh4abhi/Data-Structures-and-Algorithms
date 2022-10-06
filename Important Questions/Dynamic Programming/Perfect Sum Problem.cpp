// Problem Link - https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1?page=1&company[]=Amazon&category[]=Dynamic%20Programming&sortBy=submissions

#define ll int 
#define MOD 1000000007

class Solution{

    public:
    
    ll countSum(ll arr[], ll n, ll sum, ll ind, vector<vector<ll>> &dp)
    {
        if(sum==0)
        {
            if(arr[ind]==0)
                return 2;
            return 1;
        }
        if(ind==n-1)
            return sum==arr[ind];
            
        ll op = 0;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        if(arr[ind]<=sum)
            op = (op + countSum(arr,n,sum-arr[ind],ind+1,dp))%MOD;
       return dp[ind][sum] = (op + countSum(arr,n,sum,ind+1,dp))%MOD;
    }
    
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<ll>> dp(n,vector<ll>(sum+1,-1));
        for(ll i=0;i<n;i++)
            
        return countSum(arr,n,sum,0,dp);
    }
      
};
