// Problem Link - https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1?page=1&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{
public:
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        ll col = m-1;
        ll maxi = 0;
        ll ind = 0;
        for(ll i=0;i<n;i++)
        {
            while(m>0 and arr[i][col]==1)
                col--;
            if(maxi<m-col)
                maxi = m-col, ind = i;
        }
        if(col==m-1)
            return -1;
        return ind;
    }

};
