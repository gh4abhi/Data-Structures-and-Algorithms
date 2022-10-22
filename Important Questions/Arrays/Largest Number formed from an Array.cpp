// Problem Link - https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1?page=2&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll long long

class Solution{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    string printLargest(vector<string> &arr) {
       
       ll n = arr.size();
       sort(arr.begin(),arr.end(),[](string &a, string &b){
          return (a+b)>(b+a);
       });
       string ans = "";
       for(auto i:arr)
        ans += i;
       return ans;
    }
};
