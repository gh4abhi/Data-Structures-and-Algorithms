// Problem Link - https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll int

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        ll ans = a[0];
        ll count = 1;
        for(ll i=1;i<size;i++)
        {
            if(count==0)
                ans = a[i], count = 1;
            else if(a[i]==ans)
                count += 1;
            else
                count -=1;
        }
        count = 0;
        for(ll i=0;i<size;i++)
            if(a[i]==ans)
                count+=1;
        if(count<=size/2)
            return -1;
        return ans;
    }
};