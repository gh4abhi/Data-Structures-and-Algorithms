// Problem Link - https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

#define ll int

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<ll,ll> m;
        Node* temp = head;
        Node* pre = head;
        while(temp)
        {
            if(m.count(temp->data))
                pre->next = temp->next, temp = temp->next;
            else{
                m[temp->data]++;
                pre = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
