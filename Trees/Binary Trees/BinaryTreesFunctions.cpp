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

//--------------------------Binary Tree------------------------------------

template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

//--------------------------Print Binary Tree------------------------------------

void printBinaryTree(BinaryTreeNode<ll>* root)
{
    if(root== nullptr)
    {
        return;
    }
    cout<<root->data<<" : ";
    if(root->left)
    {
        cout<<"L - "<<root->left->data<<", ";
    }
    else
    {
        cout<<"L - "<<"NULL"<<", ";
    }
    if(root->right)
    {
        cout<<"R - "<<root->right->data<<", ";
    }
    else
    {
        cout<<"R - "<<"NULL"<<", ";
    }
    cout<<"\n";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

//--------------------------Take Input For Binary Tree Recursive------------------------------------

BinaryTreeNode<ll>* takeInputBinaryTreeRecursive()
{
    cout<<"Enter Data\n";
    ll rootData;
    cin>>rootData;
    if(rootData==-1)
    {
        return nullptr;
    }
    BinaryTreeNode<ll>* root = new BinaryTreeNode<ll>(rootData);
    BinaryTreeNode<ll>* leftChild = takeInputBinaryTreeRecursive();
    BinaryTreeNode<ll>* rightChild = takeInputBinaryTreeRecursive();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

//--------------------------Take Input For Binary Tree Level Wise------------------------------------

BinaryTreeNode<ll>* takeInputBinaryTreeLevelWise()
{
   ll rootData;
   cout<<"Enter Root Data\n";
   cin>>rootData;
   if(rootData==-1)
   {
       return nullptr;
   }
    BinaryTreeNode<ll>* root = new BinaryTreeNode<ll>(rootData);
    queue<BinaryTreeNode<ll>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<ll>* current = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<current->data<<"\n";
        ll node1;
        cin>>node1;
        if(node1!=-1)
        {
            BinaryTreeNode<ll>* leftChild = new BinaryTreeNode<ll>(node1);
            pendingNodes.push(leftChild);
            current->left = leftChild;
        }
        cout<<"Enter right child of "<<current->data<<"\n";
        ll node2;
        cin>>node2;
        if(node2!=-1)
        {
            BinaryTreeNode<ll>* rightChild = new BinaryTreeNode<ll>(node2);
            pendingNodes.push(rightChild);
            current->right = rightChild;
        }
    }
    return root;
}

//--------------------------Check if Binary Tree is empty------------------------------------

bool binaryNullTree(BinaryTreeNode<ll>* root)
{
    return root== nullptr;
}

//--------------------------Print Tree Level Wise------------------------------------

void printBinaryTreeLevelWise(BinaryTreeNode<ll>* root)
{
    queue<BinaryTreeNode<ll>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<ll>* current = pendingNodes.front();
        pendingNodes.pop();
        cout<<current->data<<" : ";
        if(current->left)
        {
            cout<<"L - "<<current->left->data<<", ";
            pendingNodes.push(current->left);
        }
        else
        {
            cout<<"L - "<<"NULL"<<", ";
        }
        if(current->right)
        {
            cout<<"R - "<<current->right->data<<"\n";
            pendingNodes.push(current->right);
        }
        else
        {
            cout<<"R - "<<"NULL"<<"\n";

        }
    }
}

//--------------------------Number of Nodes in Binary Tree------------------------------------

ll binaryNumNode(BinaryTreeNode<ll>* root)
{
    ll ans=0;
    if(root!= nullptr)
    {
        return 1 + binaryNumNode(root->left) + binaryNumNode(root->right);
    }
    return ans;
}

//--------------------------Find a Node in Binary Tree------------------------------------

bool binaryFindNode(BinaryTreeNode<ll>* root, ll x)
{
  if(binaryNullTree(root))
  {
      return false;
  }

  return root->data==x or binaryFindNode(root->left,x) or binaryFindNode(root->right,x);
}

//--------------------------Find a Height of a Binary Tree------------------------------------

// Problem Statement - Given a binary tree, find and return the height of given tree.

ll heightOfBinaryTree(BinaryTreeNode<ll>* root)
{
    ll ans = 0,x=0,y=0;
    if(binaryNullTree(root))
    {
        return 0;
    }
    ans = 1;
    x+=(heightOfBinaryTree(root->left)) + ans;
    y+=(heightOfBinaryTree(root->right)) + ans;
    ans = max(ans,x);
    ans = max(ans,y);
    return ans;
}

//--------------------------Mirror the given Binary Tree------------------------------------

// Problem Statement - Mirror the given binary tree. That is, right child of every nodes should become left and left should become right.

BinaryTreeNode<ll>* mirrorBinaryTree(BinaryTreeNode<ll>* root)
{
    if(binaryNullTree(root))
        return nullptr;

    BinaryTreeNode<ll>* mirroredRoot = new BinaryTreeNode<ll>(root->data);
    mirroredRoot->left = mirrorBinaryTree(root->right);
    mirroredRoot->right = mirrorBinaryTree(root->left);

    return mirroredRoot;
}

//--------------------------Inorder Traversal of Binary Tree------------------------------------

void inorderBinaryTree(BinaryTreeNode<ll>* root)
{
    if(binaryNullTree(root))
    {
        return;
    }
    inorderBinaryTree(root->left);
    cout<<root->data<<" ";
    inorderBinaryTree(root->right);
}

//--------------------------Preorder Traversal of Binary Tree------------------------------------

void preorderBinaryTree(BinaryTreeNode<ll>* root)
{
    if(binaryNullTree(root))
    {
        return;
    }
    cout<<root->data<<" ";
    preorderBinaryTree(root->left);
    preorderBinaryTree(root->right);
}

//--------------------------Postorder Traversal of Binary Tree------------------------------------

void postorderBinaryTree(BinaryTreeNode<ll>* root)
{
    if(binaryNullTree(root))
    {
        return;
    }
    postorderBinaryTree(root->left);
    postorderBinaryTree(root->right);
    cout<<root->data<<" ";
}

//--------------------------Construct Tree from Preorder and Inorder------------------------------------

// Problem Statement - Given Preorder and Inorder traversal of a binary tree, create the binary tree associated
// with the traversals.You just need to construct the tree and return the root.

BinaryTreeNode<ll>* buildTreeHelper(vector<ll>preorder,vector<ll>inorder, ll inS, ll inE, ll prS, ll prE)
{
    if(inS>inE)
    {
        return nullptr;

    }
    ll rootIndex = -1;
    ll rootData = preorder[prS];
    for(int i=inS;i<=inE;i++)
    {
        if(inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    ll lpreS = prS + 1;
    ll linS = inS;
    ll linE = rootIndex-1;
    ll rpreE = prE;
    ll rinS = rootIndex + 1;
    ll rinE = inE;
    ll lpreE = linE - linS + lpreS;
    ll rpreS = lpreE + 1;

    BinaryTreeNode<ll>* root = new BinaryTreeNode<ll>(rootData);
    root->left = buildTreeHelper(preorder,inorder,linS,linE,lpreS,lpreE);
    root->right = buildTreeHelper(preorder,inorder,rinS,rinE,rpreS,rpreE);
    return root;
}

BinaryTreeNode<ll>* makeBinaryTreeFromPreandInorder(vector<ll>preorder,vector<ll>inorder)
{
    return buildTreeHelper(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1);
}

//--------------------------Construct Tree from Postorder and Inorder------------------------------------

//Problem Statement - Given Postorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.
// You just need to construct the tree and return the root.

BinaryTreeNode<ll>* buildTreePostAndIn(vector<ll> postorder, vector<ll> inorder, ll poS, ll poE,ll inS,ll inE)
{
    if(poS>poE)
    {
        return nullptr;
    }
    ll rootData = postorder[poE];
    ll rootIndex = -1;
    for(ll i=inS;i<=inE;i++)
    {
        if(inorder[i]==rootData)
        {
            rootIndex =i;
        }
    }

    ll lpoS = poS;
    ll rpoE = poE-1;
    ll linS = inS;
    ll linE = rootIndex-1;
    ll rinS = rootIndex + 1;
    ll rinE = inE;
    ll lpoE = linE - linS + lpoS;
    ll rpoS = lpoE + 1;

    BinaryTreeNode<ll>* root = new BinaryTreeNode<ll>(rootData);
    root->left = buildTreePostAndIn(postorder,inorder,lpoS,lpoE,linS,linE);
    root->right = buildTreePostAndIn(postorder,inorder,rpoS,rpoE,rinS,rinE);
    return root;
}

BinaryTreeNode<ll>* makeBinaryTreeFromPostandInorder(vector<ll> postorder, vector<ll> inorder)
{
    return buildTreePostAndIn(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1);
}

//--------------------------Diameter of a Binary Tree------------------------------------

pair<ll,ll> binaryTreeDiameter(BinaryTreeNode<ll>* root)
{
    if(root== nullptr)
    {
        return make_pair(0,0);
    }
    ll lheight = binaryTreeDiameter(root->left).first;
    ll rheight = binaryTreeDiameter(root->right).first;
    ll ldia = binaryTreeDiameter(root->left).second;
    ll rdia = binaryTreeDiameter(root->right).second;
    ll finalHeight = 1 +  max(lheight,rheight);
    ll finaldia = max(lheight+rheight,max(ldia,rdia));
    return make_pair(finalHeight,finaldia);
}

//--------------------------Min and Max of Binary Tree------------------------------------

// Problem Statement - Given a binary tree, find and return the min and max data value of given binary tree.
//Return the output as an object of PairAns class, which is already created.

pair<ll,ll> maxAndMin(BinaryTreeNode<ll>* root)
{
    if(root== nullptr)
    {
        return make_pair(INT_MIN,INT_MAX);
    }
    ll maxi = root->data, mini = root->data;

    ll lmaxi = maxAndMin(root->left).first;
    ll lmini = maxAndMin(root->left).second;
    ll rmaxi = maxAndMin(root->right).first;
    ll rmini = maxAndMin(root->right).second;
    ll finalmaxi = max(maxi,max(lmaxi,rmaxi));
    ll finalmini = min(mini,min(rmini,lmini));
    return make_pair(finalmaxi,finalmini);
}

//--------------------------Sum of all nodes of a Binary Tree------------------------------------

// Problem Statement - Given a binary tree, find and return the sum of all nodes.

ll binaryTreeNodeSum(BinaryTreeNode<ll>* root)
{
    if(!root)
    {
        return 0;
    }

    ll rootData = root->data;
    ll leftData = binaryTreeNodeSum(root->left);
    ll rightData = binaryTreeNodeSum(root->right);
    ll nodeSum = rootData + leftData + rightData;
    return nodeSum;

}

//--------------------------Is Binary Tree Balanced------------------------------------

// Problem Statement - Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1.
// Return true if given binary tree is balanced, false otherwise.

pair<ll,bool> isBinaryTreeBalanced(BinaryTreeNode<ll>* root)
{
    if(root == nullptr)
    {
        // cout<<"Current Height - "<<0<<"  LeftH - "<<-1<<"  RightH - "<<-1<<"  bcheck - "<<1<<"  finalCheck - "<<1<<endl;
        return make_pair(0,1);
    }
    bool bcheck = 0;
    pair<ll,bool> leftPair =  isBinaryTreeBalanced(root->left);
    pair<ll,bool> rightPair =  isBinaryTreeBalanced(root->right);
    ll lheight = leftPair.first;
    ll rheight = rightPair.first;
    if(abs(lheight-rheight)<=1)
    {
        bcheck = 1;
    }
    bool finalCheck = bcheck and leftPair.second and rightPair.second;
    ll finalHeight = 1 + max(lheight,rheight);
    // cout<<"NodeData - "<<root->data<<"  Current Height - "<<finalHeight<<"  LeftH - "<<lheight<<"  RightH - "<<rheight<<"  bcheck - "<<bcheck<<"  finalCheck - "<<finalCheck<<endl;
    return make_pair(finalHeight,finalCheck);
}
//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{
    BOOST;
// I/O Text Files
#ifndef ONLINE_JUDGE
    inOt();
#endif

//    BinaryTreeNode<ll>* root = takeInputBinaryTreeLevelWise();
    BinaryTreeNode<ll>* root = takeInputBinaryTreeLevelWise();
    cout<<isBinaryTreeBalanced(root).second<<endl;
    printBinaryTreeLevelWise(root);
    delete root;
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------






