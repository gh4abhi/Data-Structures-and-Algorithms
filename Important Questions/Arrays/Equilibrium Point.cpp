// Problem Link - https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll int

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        ll sum = 0;
        for(ll i=0;i<n;i++)
            sum += a[i];
        ll op = 0;
        for(ll i=0;i<n;i++)
        {
            if(op==sum-a[i]-op)
                return i+1;
            op += a[i];
        }
        return -1;
    }

};