// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<ll> dq;
        vector<ll> ans;
        for(ll i=0;i<n;i++)
        {
            while(dq.size() and arr[dq.back()]<arr[i])
                dq.pop_back();
            dq.push_back(i);
            if(dq.front()<i-k+1)
                dq.pop_front();
            if(i>=k-1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};
