// Problem Link - https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll int

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        map<ll,ll> m;
        ll count = 0;
        for(ll i=0;i<n;i++)
        {
            if(m.count(k-arr[i]))
                count += m[k-arr[i]];
            m[arr[i]]++;
        }
        return count;
    }
};
