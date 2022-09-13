// Problem Link - https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1?page=1&company[]=Amazon&category[]=Arrays&sortBy=submissions

#define ll int

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<ll> ans;
        map<ll,ll> m;
        
        for(ll i=0;i<n;i++)
        {
            if(arr[abs(arr[i])%n]<0)
                m[abs(arr[i])%n]++;
            else
                {
                    if(arr[abs(arr[i])%n]==0)
                        arr[abs(arr[i])%n] = n;
                    arr[abs(arr[i])%n]*=(-1);
                }
        }
        for(auto i:m)
            ans.push_back(i.first);
        if(ans.size()==0)
            return {-1};
        return ans;
    }
};