// Problem Link - https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{

    public:
    int findSwapValues(int A[], int n1, int B[], int n2)
    {
        unordered_map<ll,ll> m;
        ll sum1 = 0, sum2 = 0;
        for(ll i=0;i<n1;i++)
            sum1 += A[i], m[A[i]]++;
        for(ll j=0;j<n2;j++)
            sum2 += B[j];
        if((sum1 + sum2)&1)
            return -1;
        ll op = abs(sum1-sum2);
        op/=2;
        for(ll i=0;i<n2;i++)
        {
            if(m.count(B[i]-op) or m.count(B[i]+op))
                return 1;
        }
        return -1;
    }
};