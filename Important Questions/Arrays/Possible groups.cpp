// Problem Link - https://practice.geeksforgeeks.org/problems/possible-groups2013/1?page=5&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll long long

class Solution{   
public:
    long long findgroups(int arr[], int n) {
        ll zero = 0, one = 0, two = 0;
        for(ll i=0;i<n;i++)
        {
            if(arr[i]%3==0)
                zero++;
            else if(arr[i]%3==1)
                one++;
            else
                two++;
        }
        ll ans = (zero*(zero-1))/2 + (one*(two)) + (zero*(zero-1)*(zero-2))/6 + (zero*one*two) + (one*(one-1)*(one-2))/6 + (two*(two-1)*(two-2))/6;
        return ans;
    }
};