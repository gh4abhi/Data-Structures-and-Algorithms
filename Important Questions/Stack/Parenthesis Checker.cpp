// Problem Link - https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?page=1&company[]=Amazon&category[]=Stack&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for(auto i:x)
        {
            if(st.size()==0 or i=='(' or i=='[' or i=='{')
                st.push(i);
            else if(st.top()=='(' and i==')')
                st.pop();
            else if(st.top()=='[' and i==']')
                st.pop();
            else if(st.top()=='{' and i=='}')
                st.pop();
            else
                st.push(i);
        }
        return st.size()==0;
    }

};