// Problem Link - https://practice.geeksforgeeks.org/problems/leaves-to-dll/1?page=4&company[]=Amazon&category[]=Tree&sortBy=submissions

Node* DFS(Node* root, Node* &prev)
{
    if(root==nullptr)
        return nullptr;
    if(!root->left and !root->right)
    {
        prev->right = root;
        root->left = prev;
        prev = root;
        return nullptr;
    }
    root->left = DFS(root->left, prev);
    root->right = DFS(root->right,prev);
    return root;
}

Node * convertToDLL(Node *root){
    Node* prev = new Node(-1);
    Node* ans = prev;
    root = DFS(root,prev);
    if(ans->right)
        ans = ans->right;
    else
        return nullptr;
    ans->left=nullptr;
    return ans;
}
