#define ll long long int

long long int numberOfPairs(vector<int>& arr)
{
    int n = arr.size();
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i] - i]++;
 
    int ans = 0;
    for (auto i : m) {
        int counter = i.second;
 
        ans += ((counter * (counter - 1)) / 2);
    }
 
    return ans;
}