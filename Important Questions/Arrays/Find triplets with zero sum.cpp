// Problem Link - https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/

#define ll int

class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
        for(ll i=0;i<n;i++)
        {
            ll op = -arr[i];
            ll start = 0, end = n-1;
            while(start<end)
            {
                if(start==i)
                {
                    start += 1;
                    continue;
                }
                if(end==i)
                {
                    end-=1;
                    continue;
                }
                ll val = arr[start] + arr[end];
                if(val>op)
                    end-=1;
                else if(val<op)
                    start += 1;
                else
                    return 1;
            }
        }
        return 0;
    }
};