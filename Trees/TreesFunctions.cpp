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

//--------------------------Tree------------------------------------
template<typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode *> children ;
    TreeNode(T data)
    {
        this->data = data;
    }
};

//************ Print Tree **************
void printTree(TreeNode<ll>* root)
{
    if(root == nullptr)
    {
        return;
    }
    cout<<root->data<<" : ";
    for(ll i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<", ";
    }
    cout<<"\n";
    for(ll i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}
//*********** Take Tree Input as a Recursive Tree ***********
TreeNode<ll>* takeInput()
{
    ll rootData;
    cin>>rootData;
    cout<<"Enter the node data"<<endl;
    TreeNode<ll>* root = new TreeNode<ll>(rootData);
    ll n;
    cout<<"Enter number of children of "<<rootData<<" \n";
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        TreeNode<ll>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

//*********** Take Level Wise Input in a Tree ***********
TreeNode<ll> * takeInputLevelWise()
{
    ll rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    TreeNode<ll>* root = new TreeNode<ll>(rootData);
    queue<TreeNode<ll>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<ll>* front = pendingNodes.front();
        pendingNodes.pop();
        ll numChild;
        cout<<"Enter the number of children of "<<front->data<<endl;
        cin>>numChild;
        for(ll i=0;i<numChild;i++)
        {
            ll childData;
            cout<<"Enter "<<i+1<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<ll>* child = new TreeNode<ll>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return  root;
}

//*********** Count Number of Nodes in a Tree ***********
ll numNode(TreeNode<ll>* root)
{
    if(root == nullptr)
        return 0;
    ll ans  = 1;
    for(ll i=0;i<root->children.size();i++)
    {
        ans+= numNode(root->children[i]);
    }
    return ans;
}


//*********** Sum of Nodes in a Tree ***********

ll nodeSum(TreeNode<ll>* root)
{
    if(root== nullptr)
        return 0;
    ll sum = root->data;
    for(ll i=0;i<root->children.size();i++)
    {
        sum+= nodeSum(root->children[i]);
    }
    return sum;
}

//*********** Check if tree is Null ***********

bool nullTree(TreeNode<ll>* root)
{
    if(root == nullptr)
        return true;
    return false;
}

//*********** Find Maximum Node Data in a Tree ***********

ll maxNode(TreeNode<ll>* root)
{
    if(nullTree(root))
    {
        return 0;
    }
    ll maxVal = INT_MIN;
    maxVal = max(maxVal,root->data);
    for(ll i=0;i<root->children.size();i++)
    {
        maxVal = max(maxVal, maxNode(root->children[i]));
    }
    return  maxVal;
}

//*********** Find Height of a Tree ***********

ll treeHeight(TreeNode<ll>* root)
{
    if(nullTree(root))
    {
        return 0;
    }
    ll height = 1;
    for(ll i=0;i<root->children.size();i++)
    {
        ll k = 1;
        k+= treeHeight(root->children[i]);
        height = max(height,k);
    }

    return height;
}

//*********** Print all nodes at level K ***********

void printAtLevelK(TreeNode<ll>* root, ll k) {
    if (nullTree(root))
        return;
    if (k == 0) {
        cout << root->data << " ";
    }
    for (ll i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k - 1);
    }
}

//*********** Print all nodes at level K ***********

ll countNoLeaf(TreeNode<ll>* root)
{
    if(nullTree(root))
    {
        return -1;

    }
    ll num = 0;
    if(root->children.size()==0)
    {
        num++;
        return num;
    }
    for(ll i=0;i<root->children.size();i++)
    {
        num+=countNoLeaf(root->children[i]);
    }

    return num;
}


//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{

    BOOST;
#ifndef ONLINE_JUDGE
    inOt();
#endif
    TreeNode<ll>* root = takeInputLevelWise();
    cout<<countNoLeaf(root)<<"\n";
 printTree(root);
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------





