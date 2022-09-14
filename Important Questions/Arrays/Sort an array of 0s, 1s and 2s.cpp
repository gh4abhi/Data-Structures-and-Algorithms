// Problem Link - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll int

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        ll start = 0, mid = 0, end = n-1;
        while(mid<=end)
        {
            if(a[mid]==0)
                swap(a[mid],a[start]), start +=1, mid += 1;
            else if(a[mid]==1)
                mid += 1;
            else
                swap(a[mid],a[end]), end -= 1;
        }
    }
};