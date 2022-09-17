// Problem Link - https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll int

int transitionPoint(int arr[], int n) {
    ll start = 0, end = n-1;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        if(arr[mid]==0)
            start += 1;
        else 
            end -= 1;
    }
    if(arr[start]==1)
        return start;
    return -1;
}