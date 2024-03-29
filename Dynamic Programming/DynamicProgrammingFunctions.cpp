/*-----------------------------------------------------------------
                    Always beleive you can.
-------------------------------------------------------------------*/

#include <bits/stdc++.h>
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(),v.end())
#define prt1(a) cout<<a<<" ";
#define prt2(a,b) cout<<a<<" "<<b<<" ";
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define ll long long
#define vec  vector<ll>
#define pb push_back
#define pa vector<pair<ll,ll>>
#define fi first
#define se second
#define siz size()
#define full(a) a.begin(),a.end()
#define max_val INT_MIN
#define min_val INT_MAX;
#define MOD 1000000007


using namespace std;

//----------------------------------------------------------------Necessary Functions---------------------------------------------------------------------------------------
void printvec(vector<ll> v) {
    for(auto x:v)
        cout<<x<<" ";
}

ll fact(ll n)   {
    ll m=1;
    for(ll i=1;i<=n;i++)
        m*=i;
    return m;
}

void inOt()
{
    freopen("input.txt" , "r" , stdin);   // For getting input from input.txt file
    freopen("output.txt" , "w" , stdout);  // Printing the Output to output.txt file
}

ll lcm (ll a,ll b)
{
    return (a / __gcd(a, b)) * b;
}

ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll po = power(x, y / 2, m) % m;
    po = (po * po) % m;

    return (y % 2 == 0) ? po : (x * po) % m;
}


bool isPrime(ll n){
    if (n <= 1)
        return false;

    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

ll modInverse(ll a,ll m)
{
    return power(a, m - 2, m);

}

vector<ll> primeFactors(ll n)
{
    vec v2;
    while (n % 2 == 0)
    {
        v2.pb(2);
        n = n/2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            v2.pb(i);
            n = n/i;
        }
    }

    if (n > 2)
        v2.pb(n);
    return v2;
}
vector<ll> pr;
ll h = 1;
ll st = 19000;
vector<ll> SieveOfEratosthenes(ll n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<ll> vect;
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
        {
            vect.push_back(p);
        }
    return vect;
}
int LCSubStr(char* X, char* Y, int m, int n)
{
    // Create a table to store
    // lengths of longest
    // common suffixes of substrings.
    // Note that LCSuff[i][j] contains
    // length of longest common suffix
    // of X[0..i-1] and Y[0..j-1].

    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
    // longest common substring

    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}


//------------------------------------------------------------------------------ Dynamic Programming ---------------------------------------------------------------------------------

//--------------------------Nth Fibonacci Number------------------------------------

// Memoization - Top-Down

ll fibonacciHelper(ll* ans, ll n)
{
    if(n<=1)
    {
        return n;
    }
    if(ans[n]!=-1)
    {
        return ans[n];
    }
    ll a = fibonacciHelper(ans,n-1);
    ll b = fibonacciHelper(ans,n-2);
    ans[n] = a+b;
    return ans[n];
}

ll nthFibonacciNum(ll n)
{
    ll* ans = new ll[n+1];
    for(ll i=0;i<n+1;i++)
    {
        ans[i] = -1;
    }

    return fibonacciHelper(ans, n);
}

ll nthFibonacciNumDP(ll n)
{
    ll* ans = new ll[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(ll i=2;i<n+1;i++)
    {
        ans[i] = ans[i-1] + ans [i-2];
    }
    return ans[n];
}

//--------------------------Min Steps to one------------------------------------

// Problem Statement - Given a positive integer 'n', find and return the minimum number of steps that 'n' has
// to take to get reduced to 1. You can perform any one of the following 3 steps:
// 1.) Subtract 1 from it. (n = n - 1) ,
// 2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
// 3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).

ll minStepsTo1DP(ll n)
{
    ll* arr = new ll[n+1];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(ll i=4; i<n+1;i++)
    {
        ll a = INT_MAX, b = INT_MAX;
        if(i%2==0)
        {
            a = arr[i/2];
        }
        if(i%3==0)
        {
            b = arr[i/3];
        }
        arr[i] = 1+min(a,min(b,arr[i-1]));
    }
    return arr[n];
}

//--------------------------Staircase------------------------------------

// Problem Statement - A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
// Implement a method to count and return all possible ways in which the child can run-up to the stairs.

ll staircaseDP(ll n)
{
    ll* arr = new ll[max(n+1ll,4ll)];
    arr[0] =0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(ll i=4;i<n+1;i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr[n];
}

//--------------------------Minimum Count------------------------------------

// Problem Statement - Given an integer N, find and return the count of minimum numbers required to represent N as a
// sum of squares.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is
// the minimum count of numbers required to represent N as sum of squares.

ll minimumCountRecursive(ll n)
{
    ll count = INT_MAX;

    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    if(n==3)
    {
        return 3;
    }

    for(ll i=1;i<sqrt(n);i++)
    {
        ll curCount=0;
        if(sqrt(n)*sqrt(n) == n)
        {
            curCount = 1;
        }
        else {
            curCount = 1 + minimumCountRecursive(n - i * i);
        }
        count = min(curCount,count);
    }
    return count;
}

//*****************************************************************************************//

ll minimumCountMemoizationHelper(ll arr[], ll n)
{
    if(n<=3)
    {
        return n;
    }
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    for(ll i=1;i<=n;i++)
    {
        arr[i] = i;
        for(ll j=0;j*j<=i;j++)
        {
            arr[i] = min(arr[i],1+ minimumCountMemoizationHelper(arr,i-j*j));
        }
    }

    return arr[n];

}

ll minimumCountMemorization(ll n)
{
    ll arr[n+1];
    for( ll i=0;i<n+1;i++)
    {
        arr[i] = -1;
    }
    return minimumCountMemoizationHelper(arr,n);
}

//*****************************************************************************************//

ll minimumCountDP(ll n)
{
    ll dp[n+1];
    dp[0] = 0;
    for(ll i=1;i<=n;i++)
    {
        dp[i] = i;
        for(ll j=1;j*j<=i;j++)
        {
            dp[i] = min(dp[i],1+dp[i-j*j]);
        }
    }
    return dp[n];
}

//*****************************************************************************************//

ll minimumCountLegendresTheorem(ll n)
{
    ll k = sqrt(n);
    if(k*k==n)
    {
        return 1;
    }
    if(n%4==0)
    {
        while(n%4==0)
        {
            n/=4;
        }
    }

    if(n%8==7)
    {
        return 4;
    }

    for(ll i=1;i*i<=n;i++)
    {
        ll m = n-i*i;
        ll r = sqrt(m);
        if(r*r == m)
        {
            return 2;
        }
    }
    return 3;
}

//--------------------------Number of balanced Binary Trees------------------------------------

// Problem Statement - Given an integer h, find the possible number of balanced binary trees of height h.
// You just need to return the count of possible binary trees which are balanced.
// This number can be huge, so return output modulus 10^9 + 7.

ll numberOfBalancedBinaryTreeRecursive(ll h)
{
    if(h<=1)
    {
        return 1;
    }
    ll x = numberOfBalancedBinaryTreeRecursive(h-1);
    ll y = numberOfBalancedBinaryTreeRecursive(h-2);
    ll ans = (((x%MOD)*(x%MOD))%MOD + (2*(y%MOD)*x%MOD)%MOD)%MOD;
    return ans;
}

//*****************************************************************************************//


ll numberOfBalancedBinaryTreeMemoizationHelper(ll h, ll arr[])
{
    if(h<=1)
    {
        return 1;
    }
    if(arr[h]!=-1)
    {
        return arr[h];
    }
    ll x = numberOfBalancedBinaryTreeMemoizationHelper(h-1,arr);
    ll y = numberOfBalancedBinaryTreeMemoizationHelper(h-2,arr);
    arr[h] = (((x%MOD)*(x%MOD))%MOD + (2*(y%MOD)*x%MOD)%MOD)%MOD;
    return arr[h];
}


ll numberOfBalancedBinaryTreeMemoization(ll h)
{
    ll arr[h+1];
    for(ll i=0;i<h+1;i++)
    {
        arr[i] = -1;
    }
    ll ans = numberOfBalancedBinaryTreeMemoizationHelper(h, arr);
    return ans;
}

//*****************************************************************************************//

ll numberOfBalancedBinaryTreeDP(ll h)
{
    ll dp[h+1];
    dp[0] = 1;
    dp[1] = 1;
    for(ll i=2;i<h+1;i++)
    {
        dp[i] = (((dp[i-1])*(dp[i-1]))%MOD + 2*(((dp[i-1])*dp[i-2])%MOD))%MOD;
    }
    return dp[h];
}


//--------------------------Min cost Path------------------------------------

// Problem Statement - An integer matrix of size (M x N) has been given. Find out the minimum cost to
// reach from the cell (0, 0) to (M - 1, N - 1).
// From a cell (i,  j), you can move in three directions:
// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"
// The cost of a path is defined as the sum of each cell's values through which the route passes.

ll minCostPathRecursiveHelper(vector<vector<ll>>& vect, ll i, ll j, ll sum)
{

    ll diSum = INT_MAX, rSum = INT_MAX, doSum = INT_MAX;
    if(i==vect.size()-1 and j==vect[0].size()-1)
    {
        return sum + vect[i][j];
    }

    if(i<vect.size()-1 and j<vect[0].size()-1)
    {
        diSum = minCostPathRecursiveHelper(vect, i+1, j+1, sum + vect[i][j]);
    }
    if(i<vect.size()-1)
    {
        doSum = minCostPathRecursiveHelper(vect, i+1, j, sum + vect[i][j]);
    }

    if(j<vect[0].size()-1)
    {
        rSum = minCostPathRecursiveHelper(vect, i, j+1, sum + vect[i][j]);
    }
    return min(diSum, min(rSum,doSum));

}

ll minCostPathRecursive(vector<vector<ll>>& vect)
{
    return minCostPathRecursiveHelper(vect, 0, 0, 0);
}

//*****************************************************************************************//

ll minCostPathMemoizationHelper(vector<vector<ll>>& vect, ll i, ll j, ll sum, vector<vector<ll>> arr)
{
    ll diSum = INT_MAX, rSum = INT_MAX, doSum = INT_MAX;
    if(i==vect.size()-1 and j==vect[0].size()-1)
    {
        return sum + vect[i][j];
    }
    if(arr[i][j]!=-1)
    {
        return arr[i][j];
    }
    if(i<vect.size()-1 and j<vect[0].size()-1)
    {
        diSum = minCostPathMemoizationHelper(vect, i+1, j+1, sum + vect[i][j],arr);
    }
    if(i<vect.size()-1)
    {
        doSum = minCostPathMemoizationHelper(vect, i+1, j, sum + vect[i][j],arr);
    }

    if(j<vect[0].size()-1)
    {
        rSum = minCostPathMemoizationHelper(vect, i, j+1, sum + vect[i][j],arr);
    }
    arr[i][j] =  min(diSum, min(rSum,doSum));
    return arr[i][j];
}

ll minCostPathMemoization(vector<vector<ll>>& vect)
{
    vector<vector<ll>> arr(vect.size());
    for(ll i=0;i<vect.size();i++)
    {
        for(ll j=0;j<vect[0].size();j++)
        {
            arr[i].pb(-1);
        }
    }
    return minCostPathMemoizationHelper(vect, 0, 0, 0, arr);
}

//*****************************************************************************************//


ll minCostPathDP(vector<vector<ll>>& vect)
{
    ll m = vect.size();
    ll n = vect[0].size();
    ll dp[m][n];
    dp[m-1][n-1] = vect[m-1][n-1];
    // Filling last row (right -> left)
    for(ll i = n-2;i>=0;i--)
    {
        dp[m-1][i] = vect[m-1][i] + dp[m-1][i+1];
    }
    // Filling last column (bottom -> top)
    for(ll i = m-2;i>=0;i--)
    {
        dp[i][n-1] = vect[i][n-1] + dp[i+1][n-1];
    }

    for(ll i = m-2; i>=0;i--)
    {
        for(ll j = n-2; j>=0; j--) {

            dp[i][j] = vect[i][j] + min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
    }
return dp[0][0];

}

//--------------------------Longest Common Subsequence------------------------------------

ll longestCommonSubsequenceRecursiveHelper(string s, string t, ll i, ll j, ll count)
{
    ll eqC = INT_MIN, dI = INT_MIN, dJ = INT_MIN, dB = INT_MIN;
    if(i==s.length() or j==t.length())
    {
        return count;
    }
    if(s[i]==t[j])
    {
      eqC = longestCommonSubsequenceRecursiveHelper(s,t, i+1, j+1, count+1);
    }
    else
    {
        dI = longestCommonSubsequenceRecursiveHelper(s,t,i+1,j,count);
        dJ = longestCommonSubsequenceRecursiveHelper(s,t,i,j+1,count);
        dB = longestCommonSubsequenceRecursiveHelper(s,t,i+1,j+1,count); // We can avoid this call as when we remove
        // first character of s or t, it becomes exactly the same case.
    }

    return max(eqC,max(dI,max(dJ,dB)));
}


ll longestCommonSubsequenceRecursive(string s, string t)
{
    return longestCommonSubsequenceRecursiveHelper(s, t, 0,0,0);
}

//*****************************************************************************************//

ll longestCommonSubsequenceMemoizationHelper(string s, string t, ll** arr)
{
 ll m = s.length();
 ll n = t.length();

 if(m==0 or n==0)
 {
     return 0;
 }


 ll eqC = INT_MIN, dI = INT_MIN, dJ = INT_MIN, dB = INT_MIN;

 if(arr[m][n]!=-1)
 {
     return arr[m][n];
 }

 if(s[0]==t[0])
 {
     eqC = 1 + longestCommonSubsequenceMemoizationHelper(s.substr(1), t.substr(1), arr);
     arr[m][n] = eqC;
     return arr[m][n];
 }
 else
 {
     dI = longestCommonSubsequenceMemoizationHelper(s.substr(1), t, arr);
     dJ = longestCommonSubsequenceMemoizationHelper(s, t.substr(1), arr);
     dB = longestCommonSubsequenceMemoizationHelper(s.substr(1), t.substr(1), arr);
 }

 arr[m][n] = max(dI,max(dJ,dB));
 return arr[m][n];
}

ll longestCommonSubsequenceMemoization(string s, string t)
{
    ll m = s.length();
    ll n = t.length();
    ll** arr = new ll*[m+1];
    for(ll i=0;i<=m;i++)
    {
        arr[i] = new ll[n+1];
        for(ll j=0;j<=n;j++)
        {
            arr[i][j] = -1;
        }
    }
    ll ans = longestCommonSubsequenceMemoizationHelper(s,t,arr);
    for(ll i=0;i<=m;i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return ans;
}

//*****************************************************************************************//

ll longestCommonSubsequenceDP(string s, string t)
{
    ll m = s.length();
    ll n = t.length();
    ll dp[m+1][n+1];
    for(ll i=0; i<=m; i++)
    {
        dp[i][0] = 0;
    }
    for(ll i=0; i<=n; i++)
    {
        dp[0][i] = 0;
    }
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(s[m-i]==t[n-j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                ll a = dp[i-1][j];
                ll b = dp[i][j-1];
                ll c = dp[i-1][j-1];
                dp[i][j] = max(a,max(b,c));
            }
        }
    }
    return dp[m][n];
}

//--------------------------Edit Distance------------------------------------

// Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings.
// Edit Distance of two strings is minimum number of steps required to make one string equal to other.
// In order to do so you can perform following three operations only :
// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
// Note - Strings don't contain spaces

ll editDistanceRecursive(string s, string t)
{
    ll m = s.length(), n = t.length();
    if(m==0 and n==0)
    {
        return 0;
    }
    if(m==0)
    {
        return n;
    }
    if(n==0)
    {
        return m;
    }
    ll a = INT_MAX, b = INT_MAX, c = INT_MAX, ans;
    if(s[0]==t[0])
    {
        return editDistanceRecursive(s.substr(1),t.substr(1));
    }
    else
    {
      a = 1 + editDistanceRecursive(s.substr(1), t);
      b = 1 + editDistanceRecursive(s,t.substr(1));
      c = 1 + editDistanceRecursive(s.substr(1),t.substr(1));
    }
    return min(a,min(b,c));
}

//*****************************************************************************************//

ll editDistanceMemoizationHelper(string s, string t, ll** arr)
{
    ll m = s.length(), n = t.length();
    if(arr[m][n]!=-1)
    {
        return arr[m][n];
    }
    if(m==0 and n==0)
    {
        arr[m][n] = 0;
        return arr[m][n];
    }
    if(m==0)
    {
        arr[m][n] = n;
        return arr[m][n];
    }
    if(n==0)
    {
        arr[m][n] = m;
        return arr[m][n];
    }
    ll a = INT_MAX, b = INT_MAX, c = INT_MAX, ans;
    if(s[0]==t[0])
    {
        ans = editDistanceMemoizationHelper(s.substr(1),t.substr(1),arr);
    }
    else
    {
        a = 1 + editDistanceMemoizationHelper(s.substr(1), t,arr);
        b = 1 + editDistanceMemoizationHelper(s,t.substr(1),arr);
        c = 1 + editDistanceMemoizationHelper(s.substr(1),t.substr(1),arr);
        ans =  min(a,min(b,c));
    }

    arr[m][n] = ans;
    return arr[m][n];

}

ll editDistanceMemoization(string s, string t)
{
  ll m = s.length();
  ll n = t.length();
  ll** arr = new ll*[m+1];
  for(ll i=0;i<=m;i++)
  {
      arr[i] = new ll[n+1];
      for(ll j=0;j<=n;j++)
      {
          arr[i][j] = -1;
      }
  }
  ll ans = editDistanceMemoizationHelper(s,t,arr);
  for(ll i=0;i<=m;i++)
  {
      delete [] arr[i];
  }
  delete [] arr;
  return ans;
}

//*****************************************************************************************//

ll editDistanceDP(string s, string t)
{
    ll m = s.length();
    ll n = t.length();
    ll dp[m+1][n+1];
    for(ll i=0;i<=m;i++)
    {
        dp[i][0] = i;
    }
    for(ll i=0;i<=n;i++)
    {
        dp[0][i] = i;
    }
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(s[m-i]==t[n-j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                ll a = dp[i-1][j];
                ll b = dp[i][j-1];
                ll c = dp[i-1][j-1];
                dp[i][j] = 1 + min(a, min(b, c));
            }
        }
    }

    return dp[m][n];
}

//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{
    BOOST;
// I/O Text Files
#ifndef ONLINE_JUDGE
    inOt();
#endif
  string s,t;
  cin>>s>>t;
    cout<<editDistanceDP(s,t);
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------






