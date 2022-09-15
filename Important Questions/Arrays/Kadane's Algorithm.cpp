// Problem Link - https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll long long

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        ll ans = -1e18;
        ll op = 0;
        for(ll i=0;i<n;i++)
        {
            op += arr[i];
            ans = max(ans,op);
            if(op<0)
                op = 0;
        }
        return ans;
    }
};