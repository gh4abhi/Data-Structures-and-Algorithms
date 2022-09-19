//Problem Link - https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?page=1&company[]=Amazon&category[]=Stack&sortBy=submissions

#define ll long long

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<ll> ans(n);
        stack<ll> st;
        for(ll i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                st.push(arr[i]);
                ans[i] = -1;
                continue;
            }
            while(st.size() and st.top()<=arr[i])
                st.pop();
            if(st.size()==0)
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};