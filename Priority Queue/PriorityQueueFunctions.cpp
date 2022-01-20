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


//------------------------------------------------------------------------------ Data Structres ---------------------------------------------------------------------------------

//--------------------------Priority Queue------------------------------------

class PriorityQueue
{
    vector<ll> pq;
public:
    PriorityQueue()
    {

    }
    bool isEmpty()
    {
        return pq.size()==0;
    }

    ll getSize()
    {
        return pq.size();
    }

    ll getMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(ll element)
    {
        pq.pb(element);

        ll childIndex = pq.size()-1;

        while(childIndex>0)
        {
            ll parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex]<pq[parentIndex])
            {
                swap(pq[childIndex],pq[parentIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    ll removeMin()
    {
        if(isEmpty())
            return 0;
        ll deletedElement = pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        ll parentIndex = 0;
        // Down Heapify
        ll lChildIndex = 2*parentIndex + 1;
        ll rChildIndex = 2*parentIndex + 2;
        ll minIndex = parentIndex;

        while(lChildIndex<pq.size())
        {
            if(pq[minIndex]>pq[lChildIndex])
             {
                 minIndex = lChildIndex;
             }
             if(rChildIndex<pq.size()-1 and pq[rChildIndex]<pq[minIndex])
             {
                 minIndex = rChildIndex;
             }
             if(minIndex==parentIndex)
                 break;
            swap(pq[parentIndex],pq[minIndex]);
            parentIndex = minIndex;
            lChildIndex = 2*parentIndex + 1;
            rChildIndex = 2*parentIndex + 2;
        }
        return deletedElement;
    }
};

void inplaceHeapSort(ll arr[], ll n)
{
    for(ll i=0;i<n;i++)
    {
        ll childIndex = i;
        ll parentIndex = (i-1)/2;
        while(parentIndex>=0)
        {
            if(arr[parentIndex]>arr[childIndex])
            {
                swap(arr[parentIndex],arr[childIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
    }
    ll lastIndex = n-1;
    for(ll i=0;i<n;i++)
    {
        swap(arr[lastIndex],arr[0]);
        cout<<arr[lastIndex]<<" ";
        ll parentIndex = 0;
        ll lChild = 2*parentIndex + 1;
        ll rChild = 2*parentIndex + 2;
        lastIndex--;
        while(lChild<lastIndex+1)
        {

            ll minIndex = parentIndex;
            if(arr[minIndex]>arr[lChild])
            {
                minIndex = lChild;
            }
            if(rChild<lastIndex + 1 and arr[minIndex]>arr[rChild])
            {
                minIndex = rChild;
            }
            if(minIndex==parentIndex)
            {
                break;
            }
            swap(arr[parentIndex],arr[minIndex]);
            parentIndex = minIndex;
            lChild = 2*parentIndex + 1;
            rChild = 2*parentIndex + 2;
        }
    }
}

//--------------------------------------------------------------K Sorted Array----------------------------------------------------------------------------------------------

void kSortedArray(ll arr[], ll n, ll k) {
    priority_queue<ll> pq;

    for (ll i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    ll ans[n], j = 0;
    for (ll i = k; i < n; i++) {
        ans[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while(!pq.empty())
    {
        ans[j] = pq.top();
        pq.pop();
        j++;
    }
    for (ll i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
}


//--------------------------------------------------------------Notes----------------------------------------------------------------------------------------------

/*PriorityQueue p;
    p.insert(10);
    p.insert(12);
    p.insert(19);
    p.insert(14);
    p.insert(15);
    p.insert(21);
    p.insert(11);

    cout<<p.getSize()<<" "<<p.getMin()<<endl;
    while(!p.isEmpty())
    {
        cout<<p.removeMin()<<endl;
    }*/

// Inbuilt Priority Queue
// By default max priority queue
/*priority_queue<ll> pq;
pq.push(10);
pq.push(9);
pq.push(8);
pq.push(7);
pq.push(6);
pq.push(5);
pq.push(4);
pq.push(3);
pq.push(2);
pq.push(1);
pq.push(0);
cout<<pq.size()<<endl;
while(!pq.empty())
{
    cout<<pq.top()<<" ";
    pq.pop();
}*/
// To implement min priority queue from inbuilt priority queue
/*priority_queue<ll, vector<ll>, greater<ll>> pq;
pq.push(10);
pq.push(9);
pq.push(8);
pq.push(7);
pq.push(6);
pq.push(5);
pq.push(4);
pq.push(3);
pq.push(2);
pq.push(1);
pq.push(0);
cout<<pq.size()<<endl;
while(!pq.empty())
{
    cout<<pq.top()<<" ";
    pq.pop();
}*/


//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{
    BOOST;
// I/O Text Files
#ifndef ONLINE_JUDGE
    inOt();
#endif

    ll arr[] = {10,12,6,7,9};
    ll k = 3;
    kSortedArray(arr,5,k);
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------






