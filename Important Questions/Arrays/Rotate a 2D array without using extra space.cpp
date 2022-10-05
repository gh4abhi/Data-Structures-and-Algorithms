// Problem Link - https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1?page=5&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

//User function template for C++
class Solution{
public: 
    
    void rotateMatrix(vector<vector<int>>& arr, int n) {
        for(ll i=0;i<n;i++)
            for(ll j=i+1;j<n;j++)
                swap(arr[i][j],arr[j][i]);
        ll start = 0, end = n-1;
        while(start<end)
        {
            for(ll j=0;j<n;j++)
                swap(arr[start][j],arr[end][j]);
            start+=1;
            end-=1;
        }
    }
};