// Problem Link - https://practice.geeksforgeeks.org/problems/find-length-of-loop/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

#define ll int
//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)
            break;
    }
    if(!fast or !fast->next)
        return 0;
    Node* temp = head;
    while(temp!=fast)
        fast = fast->next, temp = temp->next;
    ll ans = 0;
    while(fast->next!=temp)
        ans++, fast = fast->next;
    return ans+1;
}