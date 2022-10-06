// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        ll i=1,j=0;
        ll plat = 1;
        ll ans = 0;
        while(i<n and j<n)
        {
            if(arr[i]<=dep[j])
                plat+=1,i++;
            else
                plat-=1,j++;
             ans = max(ans,plat);
        }
        return ans;
    }
};