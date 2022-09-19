// Problem Link - https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1?page=1&company[]=Amazon&category[]=Stack&sortBy=submissions

void StackQueue :: push(int x)
{
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s2.size())
    {
        ll op = s2.top();
        s2.pop();
        return op;
    }
    if(s1.size()==0)
        return -1;
    while(s1.size())
        s2.push(s1.top()), s1.pop();
    ll op = s2.top();
    s2.pop();
    return op;
    
}
