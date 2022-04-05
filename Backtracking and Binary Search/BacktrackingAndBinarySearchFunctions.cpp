/*-----------------------------------------------------------------
                    Gamers Never Quit.
-------------------------------------------------------------------*/

#include <bits/stdc++.h>
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define forl(n) for(ll i=0;i<n;i++)
#define prtIn(vect,i) cout<<vect[i]
#define vecs(vect,n) vector<ll> vect(n)
#define rev(v) reverse(v.begin(), v.end());
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
#define sz size()
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

void inOt()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
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
bool prime[100];
vector<ll> SieveOfEratosthenes(ll n)
{
    memset(prime, true, sizeof(prime));

    for (ll p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<ll> vect;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            vect.pb(p);
    return vect;
}
int LCSubStr(char* X, char* Y, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
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
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}
string decToBinary(int n)
{
    string ans="";
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans+="1";
        else
            ans+="0";
    }
    return ans;
}
long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

ll checkPalindrome(string str)
{
    ll n = str.length();
    ll start = 0;
    ll end = 0;
    if(n&1)
    {
        start = (n+1)/2;
        end = (n+1)/2;
    }
    else
    {
        start = n/2;
        end = n/2+1;
    }
    start--;
    end--;
    ll count = 0;
    while(start>=0 and end<n)
    {
        if(str[start]!=str[end])
        {
            count++;
        }
        start--;
        end++;
    }
    if(count==0) {
        return 1;
    }
    else
    {
        return 0;
    }
}

ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}


ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

bool compare(const pair<ll, ll>&i, const pair<ll, ll>&j)
{
    if(i.second != j.second)
    {
        return i.second > j.second;
    }
    else
    {
        return i.first > j.first;
    }
}

class threePair
{
public:
    ll l;
    ll r;
    ll c;
};

pair<ll,ll> solve(ll n)
{
    ll count = 0;
    cin>>n;
    ll c = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
        c++;
    }
    return make_pair(count,(c-count));
}

class Edge{
public:
    ll pre;
    ll pos;
    ll val;
    Edge(ll pre, ll pos, ll val)
    {
        this->pre = pre;
        this->pos = pos;
        this->val = val;
    }
};

bool isPalindrome(string S)
{
    string P = S;

    reverse(P.begin(), P.end());

    if (S == P) {
        return true;
    }
    else {
        return false;
    }
}

//--------------------------Backtracking------------------------------------


//--------------------------------------------------------------N Queen Problem----------------------------------------------------------------------------------------------

bool isPossible(ll n, ll row, ll col, vector<vector<char>>& board)
{
    for(ll i=row-1;i>=0;i--)                                 // Vertical
        if(board[i][col]=='Q')
            return false;
    for(ll i=row-1,j=col-1;i>=0 and j>=0;i--,j--)           // Upper Left Diagonal 
        if(board[i][j]=='Q')
            return false;
    for(ll i=row-1,j=col+1;i>=0 and j<n;i--,j++)           // Upper Right Diagonal 
        if(board[i][j]=='Q')
            return false;
    return true;
}

void nQueenHelper(ll n, vector<vector<char>>& board, ll row)
{
    if(row==n)
    {
        for(auto i:board)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
        return;
    }

    for(ll j=0;j<n;j++)
    {
        if(isPossible(n,row,j,board))
        {
            board[row][j] = 'Q';
            nQueenHelper(n,board,row+1);
            board[row][j] = '.';
        }
    }
}

void nQueen(ll n)
{
    vector<vector<char>> board(n,vector<char>(n,'.'));
    nQueenHelper(n,board,0);
}

//--------------------------------------------------------------Aggressive Cows----------------------------------------------------------------------------------------------

void aggressiveCows()
{
    ll n, c;
    cin>>n>>c;
    vector<ll> vect(n);

    forl(n)
    cin>>vect[i];

    sort(full(vect));

    ll start = vect[0], end = vect[n-1] - vect[0];
    ll ans = -1;
    while(start<=end)
    {
        ll mid = start + (end - start)/2;

        ll flag = 0;
        ll count = 1;
        ll last_position = 0;
        for(ll i=1;i<n;i++)
        {
            if(vect[i] - vect[last_position]>=mid)
            {
                last_position = i;
                count++;
            }
            if(count == c)
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            ans = max(ans,mid);
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    cout<<ans;
}
//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{

    BOOST;
/*#ifndef ONLINE_JUDGE
    inOt();
#endif*/
    cout<<fixed;
    aggressiveCows();
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------





