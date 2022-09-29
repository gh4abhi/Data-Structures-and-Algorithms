// Problem Link - https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(ll i=0;i<n;i++)
        {
            ll op = arr[i]-1;
            while(arr[i]>0 and arr[i]<n+1 and arr[i]!=arr[op])
            {
                swap(arr[i],arr[op]);
                op = arr[i] -1;
            }
        }
        for(ll i=0;i<n;i++)
            if(arr[i]-1!=i)
                return i+1;
        return n+1;
    } 
};
