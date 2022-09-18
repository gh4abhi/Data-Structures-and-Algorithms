// Problem Link - https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1?page=4&company[]=Amazon&category[]=Tree&sortBy=submissions

/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/
#define ll int
vector <int> diagonalSum(Node* root) {
    vector<ll> ans;
    ll sum = 0;
    queue<Node*> q;
    if(root==nullptr)
        return ans;
    q.push(root);
    q.push(nullptr);
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        if(cur==nullptr)
        {
            ans.push_back(sum);
            sum = 0;
            if(q.size()==0)
                break;
            q.push(nullptr);
            continue;
        }
        while(cur)
        {
            sum += cur->data;
            if(cur->left)
                q.push(cur->left);
            cur = cur->right;
        }
    }
    return ans;
}