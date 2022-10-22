// Problem Link - https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<ll,ll> m;
        ll sum = 0;
        ll ans = 0;
        for(auto i:arr)
        {
            sum += i;
            if(sum==0)
                ans += 1+m[0];
            else if(m.count(sum))
                ans+=m[sum];
            m[sum]++;
        }
        return ans;
    }
};