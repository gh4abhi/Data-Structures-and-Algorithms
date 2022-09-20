// Problem Link - https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    
    bool check(Node* root1, Node* root2)
    {
        if(root1==nullptr and root2==nullptr)
            return 1;
        if(root1==nullptr or root2==nullptr)
            return 0;
        if(root1->data!=root2->data)
            return 0;
        ll lef = (check(root1->left,root2->left) and check(root1->right,root2->right));
        ll rig = (check(root1->left,root2->right) and check(root1->right,root2->left));
        return lef or rig;    
    }
    
    
    bool isIsomorphic(Node *root1,Node *root2)
    {
        return check(root1,root2);
    }
};