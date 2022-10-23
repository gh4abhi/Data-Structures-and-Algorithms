// Problem Link - https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n);
        ll ans = 0;
        for(ll i=n-1;i>=2;i--)
        {
            ll start = 0, end = i-1;
            while(start<end)
            {
                if(arr[start]+arr[end]>arr[i])
                    ans += end-start, end--;
                else
                    start++;
            }
        }
        return ans;
    }
};
