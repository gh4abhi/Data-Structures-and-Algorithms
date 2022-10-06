// Problem Link - https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    
    bool twoSumSorted(ll start, ll end, ll A[], ll x)
    {
        while(start<end)
        {
            ll op = A[start] + A[end];
            if(op>x)
                end--;
            else if(op<x)
                start++;
            else
                return 1;
        }
        return 0;
    }
    
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(ll i=0;i<n;i++)
            if(twoSumSorted(i+1,n-1,A,X-A[i]))
                return 1;
        return 0;
    }

};
