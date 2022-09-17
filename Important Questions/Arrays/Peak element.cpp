// Problem Link - https://practice.geeksforgeeks.org/problems/peak-element/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array

#define ll int

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       if(n==1)
        return 0;
       ll ans = -1;
       for(ll i=1;i<n-1;i++)
       {
           if(arr[i]>arr[i-1] and arr[i]>arr[i+1])
                ans = i;
       }
       if(arr[0]>arr[1])
        ans = 0;
       if(arr[n-1]>arr[n-2])
        ans = n-1;
       return ans;
    }
};