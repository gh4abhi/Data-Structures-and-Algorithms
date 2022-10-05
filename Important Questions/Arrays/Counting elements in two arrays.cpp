// Problem Link - https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
  public:
    
    ll bs(ll arr[], ll n, ll x)
    {
        ll start = 0, end = n-1;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(arr[mid]<=x)
                start = mid+1;
            else
                end = mid-1;
        }
        return start;
    }
    
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        sort(arr2,arr2+n);
        vector<ll> ans;
        for(ll i=0;i<m;i++)
            ans.push_back(bs(arr2,n,arr1[i]));
        return ans;
    }
};