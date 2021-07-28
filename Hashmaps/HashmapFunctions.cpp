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

//--------------------------Hashmaps------------------------------------
// map<key,val> -> BST, o(logn)
// unordered_map<key,val> -> Hash Tables, o(1)


//--------------------------Remove duplicate elements from an array------------------------------------

vector<ll> removeDuplicate(ll* a,ll si)
{
    unordered_map<ll,bool> m;
    vector<ll> vect;
    for(ll i=0;i<si;i++)
    {
        if(m.count(a[i])>0)
        {
            continue;
        }
        else
        {
            m[a[i]] = true;
            vect.push_back(a[i]);
        }
    }
    return vect;
}

//--------------------------Maximum Frequency Number------------------------------------

// Problem Statement - You are given an array of integers that contain numbers in random order.
// Write a program to find and return the number which occurs the maximum times in the given input.
// If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

ll maximumFreNum(ll* a, ll si)
{
    map<ll,ll> m;
    for(ll i=0;i<si;i++)
    {
        m[a[i]]++;
    }
    ll maxFre=INT_MIN, maxEle=INT_MAX;
    for(auto i:m)
    {
        if(i.second>maxFre)
        {
            maxFre = i.second;
            maxEle = i.first;
        }
    }
    return maxEle;
}

//--------------------------Array Intersection------------------------------------

// Problem Statement - You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
// Note : Input arrays/lists can contain duplicate elements.

vector<ll> arrayIntersection(ll* a, ll n, ll* b , ll m)
{
    map<ll,ll> m1;
    vector<ll> vect;
    if(n<m)
    {
        for(ll i=0;i<n;i++)
        {
            m1[a[i]]++;
        }
        for(ll i=0;i<m;i++)
        {
            if(m1[b[i]]>0)
            {
                vect.push_back(b[i]);
                m1[b[i]]--;
            }
        }
    }
    else
    {
        for(ll i=0;i<m;i++)
        {
            m1[b[i]]++;
        }
        for(ll i=0;i<n;i++)
        {
            if(m1[a[i]]>0)
            {
                vect.push_back(a[i]);
                m1[a[i]]--;
            }
        }
    }
    sort(full(vect));
    return vect;
}

//--------------------------Pair sum to 0------------------------------------

// Problem Statement - Given a random integer array A of size N. Find and print the count of pair of elements
// in the array which sum up to 0. Note: Array A can contain duplicate elements as well.

ll pairtToSum0(ll* a, ll si)
{
    map<ll,ll> m,ans;
    for(ll i=0;i<si;i++) {
        m[a[i]]++;
        if(m.count(-a[i])>0)
        {
            ans[abs(a[i])] = m[a[i]]*m[-a[i]];
        }
    }
    ll sum=0;
    for(auto i:ans)
    {
        sum+=i.second;
    }
    return sum;
}

//--------------------------User Defined Hashmaps------------------------------------

template< typename  v>
class MapNode{
public:
    string key;
    v value;
    MapNode* next;
    MapNode(string key, v value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename v>
class ourMap{
    MapNode<v>** buckets;
    ll count_size;
    ll numBuckets;
public:
    ourMap()
    {
        count_size=0;
        numBuckets=5;
        buckets = new MapNode<v>* [numBuckets];
        for(ll i=0;i<numBuckets;i++)
        {
            buckets[i] = nullptr;
        }
    }
    ~ourMap(){
        for(ll i=0;i<numBuckets;i++)
        {
            delete buckets[i];
        }
        delete [] buckets;
    }

private:

    ll getBucketIndex(string key)
    {
        ll hashCode = 0;
        ll curCoefficient = 1;
        for(ll i=key.length()-1;i>=0;i--)
        {
            hashCode+= key[i]*curCoefficient;
            hashCode = hashCode%numBuckets;
            curCoefficient*=37;
            curCoefficient = curCoefficient%numBuckets;
        }
        return hashCode%numBuckets;
    }

    void rehash()
    {
        MapNode<v>** temp = buckets;
        buckets = new MapNode<v>*[numBuckets*2];
        for(ll i=0;i<2*numBuckets;i++)
        {
            buckets[i] = nullptr;
        }
        ll oldNumBuckets = numBuckets;
        numBuckets*=2;
        count_size = 0;
        for(ll i=0;i<oldNumBuckets;i++)
        {
            MapNode<v>* tempNode = temp[i];
            while(tempNode!=nullptr)
            {
                string key = tempNode->key;
                v val = tempNode->value;
                insert(key,val);
                tempNode = tempNode->next;
            }
        }

        for(ll i=0;i<oldNumBuckets;i++)
        {
            delete temp[i];
        }

        delete [] temp;
    }

public:
    ll size()
    {
        return count_size;
    }

    void insert(string key, v val)
    {
        ll bucketIndex = getBucketIndex(key);
        MapNode<v>* head = buckets[bucketIndex];
        MapNode<v>* temp = head;
        while(temp!=nullptr)
        {
            if(temp->key==key)
            {
                temp->value = val;
                return;
            }
        }
        MapNode<v>* newNode = new MapNode<v>(key,val);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count_size++;
        double loadFactor = (1.0*count_size)/numBuckets;
        if(loadFactor>0.7)
        {
            rehash();
        }
    }

    v getValue(string key)
    {
        ll bucketIndex = getBucketIndex(key);
        MapNode<v>* head = buckets[bucketIndex];
        MapNode<v>* temp = head;
        while(temp!=nullptr)
        {
            if(temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;  // We can do v val = 0 and then return it but this is also correct it will automatically be converted into that type.
    }

    v remove(string key)
    {
        ll bucketIndex = getBucketIndex(key);
        MapNode<v>* head = buckets[bucketIndex];
        MapNode<v>* temp = head;
        MapNode<v>* prev = nullptr;
        v val = 0;
        while(temp!=nullptr)
        {
            if(temp->key == key)
            {
                if(prev == nullptr)
                {
                    buckets[bucketIndex] = head->next;
                }
                else {
                    prev->next = temp->next;
                }
                val = temp->value;
                temp->next = nullptr;
                delete temp;
                count_size--;
                return val;
            }
            prev = temp;
            temp = temp->next;
        }
        return val;
    }

    double getLoadFactor()
    {
        return (1.0*count_size)/numBuckets;
    }

};

//--------------------------Test User Defined Hashmaps------------------------------------

void testMap()
{
    ourMap<ll> map;
    for(ll i=0;i<10;i++)
    {
        string key = "abc";
        char c = '0' + i;
        key = key + c;
        ll value = 1 + i;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<endl;
    }
    for(ll i=0;i<10;i++)
    {
        string key = "abc";
        char c = '0' + i;
        key = key + c;
        ll value = 1 + i;
        cout<<key<<" : "<<map.getValue(key)<<endl;
    }
    cout<<map.size()<<endl;
    cout<<"Now deleting values\n";
    map.remove("abc3");
    map.remove("abc9");
    for(ll i=0;i<10;i++)
    {
        string key = "abc";
        char c = '0' + i;
        key = key + c;
        ll value = 1 + i;
        cout<<key<<" : "<<map.getValue(key)<<endl;
    }
    cout<<map.size()<<endl;
}

//--------------------------Extract Unique characters------------------------------------

// Problem Statement - Given a string S, you need to remove all the duplicates. That means, the output string should contain each
// character only once. The respective order of characters should remain same, as in the input string.

string extractUniqueChar(string str)
{
    string ans_str = "";
    map<char,bool> m;
    for(auto i:str)
    {
        if(m.count(i)==0) {
            m[i] = true;
            ans_str += i;
        }
    }
    return ans_str;
}

//--------------------------Longest Consecutive Sequence------------------------------------

//Problem Statement - You are given an array of unique integers that contain numbers in random order.
// You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
// You need to return the output array which contains starting and ending element.
// If the length of the longest possible sequence is one, then the output array must contain only single element.
// Note:
// 1. Best solution takes O(n) time.
// 2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

vector<ll> longConsecutiveSequence(vector<ll> vect)
{
    map<ll,pair<bool,ll>> m;
    vector<ll> ans;
    ll k=0;
    for(auto i:vect)
    {
        m[i].first = true;
        m[i].second = k;
        k++;
    }
    ll start = INT_MAX, end = INT_MIN,lStreak=0;
    for(auto i:vect)
    {
        ll curEnd = i, curStart = i,curStreak=1;
        m[i].first = false;
        while(m.count(curStart-1)>0 and m[curStart-1].first)
        {
            curStart -=1;
            curStreak+=1;
            m[curStart].first = false;
        }
        while(m.count(curEnd+1)>0 and m[curEnd+1].first)
        {
           curEnd = curEnd+1;
           m[curEnd].first = false;
           curStreak+=1;
        }
        if(curStreak>lStreak or(curStreak==lStreak and m[curStart].second<m[start].second))
        {
            lStreak = curStreak;
            start = curStart;
            end = curEnd;
        }
    }
       if(start==end)
       {
           ans.push_back(start);
       }
       else
       {
           ans.push_back(start);
           ans.push_back(end);

       }
       return ans;
}

//--------------------------Pairs with difference K------------------------------------

ll pairWithDifferenceK(vector<ll> vect, ll k)
{
    map<ll,ll> m;
    for(auto i:vect) {
        m[i]++;
    }
    ll sum = 0;
    if(k!=0) {
        for (auto &i:m) {
            if (m.count(i.first - k) > 0) {
                sum += i.second * (m[i.first - k]);
            }
            if (m.count(i.first + k) > 0) {
                sum += i.second * (m[i.first + k]);
            }
            i.second = 0;
        }
    }
    else
    {
        for(auto i:m)
        {
            sum+= (i.second)*(i.second-1)/2;
        }
    }
    return  sum;
}

//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{

    BOOST;
#ifndef ONLINE_JUDGE
    inOt();
#endif
    cout<<fixed;
   ll n;
   cin>>n;
   vector<ll> vect(n);
   for(ll i=0;i<n;i++)
   {
       cin>>vect[i];
   }
   ll k;
   cin>>k;
   cout<<pairWithDifferenceK(vect,k);

    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------









