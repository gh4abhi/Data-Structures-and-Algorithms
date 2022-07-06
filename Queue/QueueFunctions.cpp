/*-----------------------------------------------------------------
                    Gamers Never Quit.
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
bool compare(const pair<ll, ll>&i, const pair<ll, ll>&j)
{
    if(i.second != j.second)
    {
        return i.second > j.second;
    }
    else
    {
        return i.first < j.first;
    }
}

//------------------------------------------------------------------------------ Data Structres ---------------------------------------------------------------------------------

//--------------------------Queue using vector------------------------------------

class Queue
{
    private:
        vector<ll> vect;
        ll n;
        ll front;
        ll rear;
        ll count;

    public:
        
        Queue(ll size)
        {
            n = size;
            front = -1;
            rear = -1;
            vector<ll> temp(n);
            vect = temp;
            count = 0;
        }

        bool isFull()
        {
            return count==n;
        }

        bool isEmpty()
        {
            return count==0;
        }

        void push(ll val)
        {
            if(isFull())
                {
                    cout<<"Queue is full!";
                    return;
                }
            if(front==-1 and rear==-1)
                front = 0;
            rear = (rear+1)%n;
            vect[rear] = val;
            count++;
        }

        void pop()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty!";
                return;
            }
            vect[front] = -1;
            front = (front+1)%n;
            count--;
        }

        ll frontElement()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty!";
                return -1;
            }
            return vect[front];
        }

        ll size()
        {
            return count;
        }

        void printQueue()
        {
            ll x = count;
            for(ll i=front;i<=rear,x>0;)
            {
                cout<<vect[i]<<" ";
                i = (i+1)%n;
                x--;
            }
            cout<<endl;
        }
};

//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{

    BOOST;
/*#ifndef ONLINE_JUDGE
    inOt();
#endif*/
    cout<<fixed;
    
    Queue newQueue = Queue(4);

    newQueue.push(10);
    newQueue.push(6);
    newQueue.push(4);
    newQueue.push(2);
    cout<<newQueue.size()<<endl;
    newQueue.printQueue();
    while(newQueue.size())
        cout<<newQueue.frontElement()<<endl, newQueue.pop();    
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------









