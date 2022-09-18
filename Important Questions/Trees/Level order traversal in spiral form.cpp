// Problem Link - https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?page=1&company[]=Amazon&category[]=Tree&sortBy=submissions

#define ll int

//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    if(root==nullptr)
        return {};
        stack<Node*> st1, st2;
        vector<ll> ans;
        st2.push(root);
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
