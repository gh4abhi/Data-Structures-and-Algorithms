// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll long long

class Solution{
public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n) {
        ll ans = -1e18;
        ll op = 1;
        for(ll i=0;i<n;i++)
        {
            op *= arr[i];
            ans = max(ans,op);
            if(op==0)
                op = 1;
        }
        op=1;
        for(ll i=n-1;i>=0;i--)
        {
            op *= arr[i];
            ans = max(ans,op);
            if(op==0)
                op = 1;
        }
        return ans;
    }
};
