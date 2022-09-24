// Problem Link - https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1?page=1&company[]=Amazon&category[]=Binary%20Search&sortBy=submissions

#define ll int

bool bs(ll start, ll end, int arr[], ll x)
{
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        // cout<<arr[mid]<<" "<<x<<endl;
        if(arr[mid]<x)
            start = mid+1;
        else if(arr[mid]>x)
            end = mid -1;
        else
            return 1;
    }
    return 0;
}

bool findPair(int arr[], int size, int n){
    set<ll> s;
    for(ll i=0;i<size;i++)
        s.insert(arr[i]);
    for(ll i=0;i<size;i++)
        if(s.find(arr[i]+n)!=s.end() or s.find(arr[i]-n)!=s.end())
            return 1;
    return 0;
}