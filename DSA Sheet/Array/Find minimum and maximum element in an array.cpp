// Problem Link - https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1#

#define ll long long
pair<long long, long long> getMinMax(long long a[], int n) {
    ll maxi = a[0], mini = a[0];
    for(ll i=0;i<n;i++)
     mini = min(mini,a[i]), maxi = max(maxi,a[i]);
     pair<ll,ll> ans = {mini,maxi};
     return ans;
}