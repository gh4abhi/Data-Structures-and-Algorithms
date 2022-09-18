// Problem Link - https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?page=2&company[]=Amazon&category[]=Tree&sortBy=submissions

/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
#define ll int
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        stack<Node*> st1, st2;
        vector<ll> ans;
        st1.push(root);
        while(st1.size() or st2.size())
        {
            while(st1.size())
            {
                ans.push_back(st1.top()->data);
                if(st1.top()->left)
                    st2.push(st1.top()->left);
                if(st1.top()->right)
                    st2.push(st1.top()->right);
                st1.pop();
            }
            while(st2.size())
            {
                ans.push_back(st2.top()->data);
                if(st2.top()->right)
                    st1.push(st2.top()->right);
                if(st2.top()->left)
                    st1.push(st2.top()->left);
                st2.pop();
            }
        }
        return ans;
    }
};