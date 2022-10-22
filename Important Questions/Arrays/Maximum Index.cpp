// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-index3307/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        ll posMax[n];
        ll preMin[n];
        preMin[0] = arr[0];
        for(ll i=1;i<n;i++)
            preMin[i] = min(preMin[i-1],arr[i]);
        posMax[n-1] = arr[n-1];
        for(ll i=n-2;i>=0;i--)
            posMax[i] = max(posMax[i+1],arr[i]);
        ll i=0,j=0;
        ll ans = 0;
        while(i<n and j<n)
        {
            if(preMin[i]<=posMax[j])
                ans = max(ans,j-i), j+=1;
            else
                i+=1;
        }
        return ans;
    }

};