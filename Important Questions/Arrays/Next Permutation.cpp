// Problem Link - https://practice.geeksforgeeks.org/problems/next-permutation5226/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int
class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        ll i=n-2;
        while(i>=0 and arr[i]>=arr[i+1])
            i--;
        if(i<0)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        ll j = n-1;
        while(j>=0 and arr[j]<=arr[i])
            j--;
        swap(arr[i],arr[j]);
        reverse(arr.begin()+i+1,arr.end());
        return arr;
    }
};