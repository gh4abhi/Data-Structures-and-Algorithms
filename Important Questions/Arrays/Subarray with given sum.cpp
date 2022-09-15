// Problem Link - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll long long

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        ll start = 0, end = 0;
        
        for(ll i=1;i<n;i++)
            arr[i] += arr[i-1];
        ll op = 0;
        while(end<n)
        {
            if(arr[end]==s)
                return {1,end+1};
            if(arr[end]-arr[start]<s or start==end)
                end++;
            else if(arr[end]-arr[start]>s)
                start++;
            else
                return {start+2,end+1};
        }
        return {-1};
    }
};