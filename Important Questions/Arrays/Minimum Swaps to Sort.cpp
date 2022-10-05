// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-swaps/1?page=1&difficulty[]=1&company[]=Microsoft&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    int minSwaps(vector<int>&nums)
    {
        ll n = nums.size();
        vector<pair<ll,ll>> vect;
        for(ll i=0;i<n;i++)
            vect.push_back({nums[i],i});
        sort(vect.begin(),vect.end());
        ll ans = 0;
        for(ll i=0;i<n;i++)
        {
           if(i!=vect[i].second)
           {
               ans+=1;
               swap(vect[i],vect[vect[i].second]);
               i--;
           }
        }
        return ans;
    }
};
