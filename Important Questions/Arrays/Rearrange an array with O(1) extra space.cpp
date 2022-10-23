// Problem Link - https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll long long

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        for(ll i=0;i<n;i++)
            arr[i] += (arr[arr[i]]%n)*n;
        for(ll i=0;i<n;i++)
            arr[i]/=n;
    }
};
