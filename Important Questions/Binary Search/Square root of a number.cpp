// Problem Link - https://practice.geeksforgeeks.org/problems/square-root/1?page=1&company[]=Amazon&category[]=Binary%20Search&sortBy=submissions

#define ll long long

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        ll start = 0, end = x;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            ll val = mid*mid;
            if(val>x)
                end = mid-1;
            else if(val<x)
                start = mid+1;
            else
                return mid;
        }
        return end;
    }
};
