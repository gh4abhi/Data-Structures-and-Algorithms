// Problem Link - https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?page=3&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=0;i<k+1;i++)
            pq.push(arr[i]);
        ll op = 0;
        for(ll j=k+1;j<num;j++)
        {
            arr[op++] = pq.top();
            pq.pop();
            pq.push(arr[j]);
        }
        while(op<num)
            arr[op++] = pq.top(), pq.pop();
        vector<ll> ans(arr,arr+num);
        return ans;
    }
};