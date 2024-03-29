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
 
ll mex(vector<ll>& vect, ll i, ll j)
{
    ll ind = 0;
    map<ll,ll> m;
    for(ll k=i;k<=j;k++)
    {
        m[vect[k]]++;
    }
    while(1)
    {
        if(m.count(ind)==0)
        return ind;
        ind++;
    }
}
void io(ll r)
{
    if(r==0)
    return;
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
    if(binaryNullTree(root))
    {
        cout<<"Tree is empty."<<endl;
        return;
    }
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

//--------------------------Level Order Traversal of a Binary Tree------------------------------------

// Problem Statement - Given a binary tree, print the level order traversal. Make sure each level start in new line.

// O(n^2) Approach
/*void levelOrder(BinaryTreeNode<ll>*root)
{
    if(root)
    {
        queue<BinaryTreeNode<ll>*>pendingNodes;
        pendingNodes.push(root);
        while(pendingNodes.size()!=0)
        {
            ll si = pendingNodes.size();
            for(int i=0;i<si;i++)
            {
                BinaryTreeNode<ll>* current = pendingNodes.front();
                pendingNodes.pop();
                cout<<current->data<<" ";
                if(current->left)
                {
                    pendingNodes.push(current->left);
                }
                if(current->right)
                {
                    pendingNodes.push(current->right);
                }
            }
            cout<<"\n";
        }
    }
    return;
}*/

// O(n) Approach
void levelOrder(BinaryTreeNode<ll>*root)
{
    ll checknewLine = 1;
    if(root)
    {
        queue<BinaryTreeNode<ll>*>pendingNodes;
        pendingNodes.push(root);
        while(pendingNodes.size()!=0)
        {
                BinaryTreeNode<ll>* current = pendingNodes.front();
                pendingNodes.pop();
                if(current!= nullptr)
                {
                    cout<<current->data<<" ";

                if (current->left) {
                    if(checknewLine==1) {
                        checknewLine = 0;
                        pendingNodes.push(nullptr);
                    }
                    pendingNodes.push(current->left);
                }
                if (current->right) {
                    if (current->left == nullptr and checknewLine==1) {
                        checknewLine=0;
                        pendingNodes.push(nullptr);
                    }
                    pendingNodes.push(current->right);
                }
            }
            else
            {
                checknewLine = 1;
                cout << "\n";
            }
        }
        cout<<"\n";
    }
}

//--------------------------Remove Leaf Nodes of a Binary Tree------------------------------------

// Problem Statement - Remove all leaf nodes from a given Binary Tree. Leaf nodes are those nodes,
// which don't have any children.

pair<BinaryTreeNode<ll>*,bool> removeLeafNodes(BinaryTreeNode<ll>* root)
{
    bool check = 0;
    if(root)
    {
        if(root->left== nullptr and root->right== nullptr)
        {
            check = 1;
        }
        if(check==1)
        {
            root=nullptr;
            return make_pair(root,1);
        }
        bool checkleft=0,checkright=0;
        if(root->left) {
            checkleft = removeLeafNodes(root->left).second;
        }
        if(checkleft)
        {
            root->left = nullptr;
        }
        if(root->right) {
            checkright = removeLeafNodes(root->right).second;
        }
        if(checkright)
        {
            root->right = nullptr;
        }
    }
    return make_pair(root,check);
}

//--------------------------Level wise linkedlist------------------------------------

// Problem Statement - Given a binary tree, write code to create a separate linked list for each level.
// You need to return the array which contains head of each level linked list.

class Node
{
public :
    ll data;
    Node* next;
    Node(ll data)
    {
        this->data = data;
        next = nullptr;
    }
};


vector<Node*> levelWiseLinkedList(BinaryTreeNode<ll>* root)
{
    queue<BinaryTreeNode<ll>*> pendingNodes;
    vector<Node*> vect;
    if(root)
    {
        Node* head = nullptr;
        Node* tail = nullptr;
        ll flag=1;
        pendingNodes.push(root);
        while(pendingNodes.size()!=0)
        {
            BinaryTreeNode<ll>* current = pendingNodes.front();
            pendingNodes.pop();
            if(current==nullptr)
            {
                vect.push_back(head);
                head=nullptr;
                tail=nullptr;
                flag=1;
            }
            else
            {
                Node* newNode = new Node(current->data);
                if(head==nullptr)
                {
                    head = newNode;
                    tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
            if(current->left)
            {
                if(flag==1) {
                    pendingNodes.push(nullptr);
                    flag=0;
                }
                pendingNodes.push(current->left);
            }
            if(current->right)
            {
                if(current->left==nullptr and flag==1)
                {
                    pendingNodes.push(nullptr);
                    flag=0;
                }
                pendingNodes.push(current->right);
            }
            }
        }
        vect.push_back(head);
    }
    return vect;
}

void printLinkedList(Node* head)
{
    if(head==nullptr)
    {
        return;
    }
    Node* temp = head;
    while(temp!= nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//--------------------------Create & Insert Duplicate Node------------------------------------

BinaryTreeNode<ll>* createAndInsertDuplicateNode(BinaryTreeNode<ll>* root)
{
    if(root->left == nullptr)
    {
        BinaryTreeNode<ll>* dNode = new BinaryTreeNode<ll>(root->data);
        root->left = dNode;
        return root;
    }
    BinaryTreeNode<ll>* dNode = new BinaryTreeNode<ll>(root->data);
    dNode->left = root->left;
    root->left = dNode;
    dNode->right = createAndInsertDuplicateNode(root->right);
    dNode->left = createAndInsertDuplicateNode(root->left);
    return root;

}


//--------------------------Morris Inorder Traversal------------------------------------

// Time - O(n)
// Space - O(1)

void morrisInorderTraversal(BinaryTreeNode<ll>* root)
{
    BinaryTreeNode<ll>* current = root;
   while(current!=nullptr)
   {
       if(current->left==nullptr)
       {
           cout<<current->data<<" ";
           current = current->right;
       }
       else
       {
           BinaryTreeNode<ll>* predecessor = current->left;
           while(predecessor->right!=current and predecessor->right!= nullptr)
           {
               predecessor = predecessor->right;
           }
           if(predecessor->right == nullptr)
           {
               predecessor->right = current;
               current = current->left;
           }
           else
           {
               cout<<current->data<<" ";
               predecessor->right = nullptr;
               current = current->right;
           }
       }
   }
}

//--------------------------ZigZag Tree Traversal------------------------------------

// Problem Statement - Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2
// from right to left and so on. This means odd levels should get printed from left to right and even level right to left.

void zidzagTreeTraversal(BinaryTreeNode<ll>* root)
{
    if(root)
    {
        stack<BinaryTreeNode<ll>*> s1,s2;
        s1.push(root);
        while(s1.size()!=0 or s2.size()!=0) {
            while (s1.size() != 0) {
                BinaryTreeNode<ll> *current = s1.top();
                s1.pop();
                if (current->left) {
                    s2.push(current->left);
                }
                if (current->right) {
                    s2.push(current->right);
                }
                cout << current->data << " ";
            }
            cout<<endl;
            while (s2.size() != 0) {
                BinaryTreeNode<ll> *current = s2.top();
                s2.pop();
                if (current->right) {
                    s1.push(current->right);
                }
                if (current->left) {
                    s1.push(current->left);
                }
                cout << current->data << " ";
            }
            cout<<endl;
        }
    }
}

//--------------------------Nodes without sibling------------------------------------

// Problem Statement - Given a binary tree, print all nodes that don�t have a sibling.
// Print the elements in different lines. And order of elements doesn't matter.

void nodesWithoutSibling(BinaryTreeNode<ll>* root)
{
    if(root)
    {
        if(root->left and !(root->right))
        {
            cout<<root->left->data<<endl;
            nodesWithoutSibling(root->left);
        }
        else if(!(root->left) and root->right)
        {
            cout<<root->right->data<<endl;
            nodesWithoutSibling(root->right);
        }
        else
        {
            nodesWithoutSibling(root->left);
            nodesWithoutSibling(root->right);
        }
    }
}

//--------------------------Pair Sum Binary Tree------------------------------------

// Problem Statement - Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
// Assume binary tree contains all unique elements. In a pair, print the smaller element first.
// Order of different pair doesn't matter.

// First Method - Space complexity is large in the following approach.
pair<vector<pair<ll,ll>>,map<ll,ll>> pairSumBinaryTreeHelper(BinaryTreeNode<ll>* root, map<ll,ll> m, ll sum, vector<pair<ll,ll>> vect)
{
    if(m.count(sum-(root->data))>0)
    {
        vect.push_back(make_pair(min(root->data,sum - root->data), max(root->data,sum - root->data)));
    }
    m[root->data]++;
    pair<vector<pair<ll,ll>>, map<ll,ll>> lPair, rPair;
    if(root->left)
    {
        lPair = (pairSumBinaryTreeHelper(root->left, m, sum, vect));
        m = lPair.second;
        vect = lPair.first;
    }
    if(root->right)
    {
        rPair = pairSumBinaryTreeHelper(root->right, m, sum, vect);
        m = rPair.second;
        vect = rPair.first;
    }
    return make_pair(vect,m);
}

vector<pair<ll,ll>> pairSumBinaryTree(BinaryTreeNode<ll>* root, ll sum)
{
    map<ll,ll> m;
    vector<pair<ll,ll>> vect;
    return pairSumBinaryTreeHelper(root, m , sum, vect).first;
}

// Second approach - Time Complexity - ( o(n) + o(nlogn) => o(nlogn)

vector<ll> convertBinaryTreeToArray(BinaryTreeNode<ll>* root)
{
    vector<ll> vect, vectLeft, vectRight;
    if(root)
    {
        vect.pb(root->data);
        if(root->left)
        {
            vectLeft = convertBinaryTreeToArray(root->left);
        }
        if(root->right)
        {
            vectRight = convertBinaryTreeToArray(root->right);
        }

        if(vectLeft.size())
        {
            vect.insert(vect.end(), full(vectLeft));
        }
        if(vectRight.size())
        {
            vect.insert(vect.end(), full(vectRight));
        }
    }
    return vect;
}

vector<pair<ll,ll>> PairSumOptimizedApproach(BinaryTreeNode<ll>* root, ll sum)
{
    vector<ll> vect = convertBinaryTreeToArray(root);
    vector<pair<ll,ll>> ans;
    sort(full(vect));
    ll i = 0, j = vect.size()-1;
    while(i<j)
    {
        if(vect[i]+vect[j] == sum)
        {
            ans.pb(make_pair(min(vect[i],vect[j]),max(vect[i],vect[j])));
            i++;
            j--;
        }
        else if(vect[i]+vect[j] > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

//--------------------------LCA of Binary Tree------------------------------------

// Problem Statement - Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the
// given two nodes in Binary Tree. If out of 2 nodes only one node is present, return that node.
// If both are not present, return -1.

pair<ll,pair<bool,bool>> lcaOfBinaryTreeHelper(BinaryTreeNode<ll>* root, ll node1, ll node2)
{
    ll val = INT_MAX;
    ll lVal = INT_MAX, rVal = INT_MAX;
    bool node1L = false, node1R = false, node2L = false, node2R = false;

    pair<ll,pair<bool,bool>> l,r;
    bool rootNodeCheck1 = false, rootNodeCheck2 = false;

    if(root->data == node1)
    {
        rootNodeCheck1 = true;
    }
    if(root->data == node2)
    {
        rootNodeCheck2 = true;
    }

    if(root->left)
    {
        l = lcaOfBinaryTreeHelper(root->left,node1,node2);
        lVal = l.first;
        node1L = l.second.first;
        node2L = l.second.second;
    }
    if(root->right)
    {
        r = lcaOfBinaryTreeHelper(root->right,node1,node2);
        rVal = r.first;
        node1R = r.second.first;
        node2R = r.second.second;
    }

    rootNodeCheck1 = rootNodeCheck1 or node1L or node1R;
    rootNodeCheck2 = rootNodeCheck2 or node2L or node2R;

    if(rootNodeCheck2 and rootNodeCheck1 and lVal== INT_MAX and rVal==INT_MAX)
    {
        val = root->data;
    }

    val = min(val,min(lVal,rVal));

    return make_pair(val, make_pair(rootNodeCheck1,rootNodeCheck2));
}

ll lcaOfBinaryTree(BinaryTreeNode<ll>* root, ll node1, ll node2)
{
    ll val;
    bool rootNodeCheck1, rootNodeCheck2;
    pair<ll,pair<bool,bool>> ans;
    ans = lcaOfBinaryTreeHelper(root, node1, node2);
    val = ans.first;
    rootNodeCheck1 = ans.second.first;
    rootNodeCheck2 = ans.second.second;
    if(rootNodeCheck1 and !rootNodeCheck2)
    {
        return node1;
    }
    else if(rootNodeCheck2 and !rootNodeCheck1)
    {
        return node2;
    }
    else if(!rootNodeCheck1 and !rootNodeCheck2)
    {
        return -1;
    }
    else
    {
        return val;
    }
}

//--------------------------Iterative Preorder Traversal------------------------------------

void iterativePreorder(BinaryTreeNode<ll>* root)
{
    stack<BinaryTreeNode<ll>*> st;
    st.push(root);
    while(st.size())
    {
        BinaryTreeNode<ll>* cur = st.top();
        cout<<cur->data<<" ";
        st.pop();
        if(cur->right)
            st.push(cur->right);
        if(cur->left)
            st.push(cur->left);
    }
}

//--------------------------Iterative Inorder Traversal------------------------------------

void iterativeInorder(BinaryTreeNode<ll>* root)
{
    stack<BinaryTreeNode<ll>*> st;
    BinaryTreeNode<ll>* node = root;
    st.push(node);
    vector<ll> inorder;
    while(st.size())
    {
        if(node!=nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            node = st.top();
            st.pop();
            inorder.pb(node->data);
            node = node->right;
        }
    }
    for(auto i:inorder)
        cout<<i<<" ";
}

//--------------------------Iterative Postorder Traversal------------------------------------

void iterativePostorderTwoStacks(BinaryTreeNode<ll>* root)
{
    stack<BinaryTreeNode<ll>*> st1,st2;
    st1.push(root);
    while(st1.size())
    {
        BinaryTreeNode<ll>* cur = st1.top();
        st1.pop();
        st2.push(cur);
        if(cur->left)
            st1.push(cur->left);
        if(cur->right)
            st2.push(cur->right);
    }
    while(st2.size())
        cout<<st2.top()->data<<" ",st2.pop();
}

//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{
    BOOST;
// I/O Text Files
/*#ifndef ONLINE_JUDGE
    inOt();
#endif*/

//    BinaryTreeNode<ll>* root = takeInputBinaryTreeLevelWise();
    BinaryTreeNode<ll>* root = takeInputBinaryTreeLevelWise();
    // printBinaryTreeLevelWise(root);
    iterativePostorderTwoStacks(root);
    delete root;
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------






