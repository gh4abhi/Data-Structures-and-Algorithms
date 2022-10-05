// Problem Link - https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    ll sum = 0;
    for(ll i=0;i<N;i++)
        sum += A[i]*i;
    ll op = 0;
    for(ll i=0;i<N;i++)
        op += A[i];
    ll maxi = sum;
    for(ll i=0;i<N;i++)
        sum = sum + (-op + (N)*A[i]), maxi = max(maxi,sum);
    return maxi;
}