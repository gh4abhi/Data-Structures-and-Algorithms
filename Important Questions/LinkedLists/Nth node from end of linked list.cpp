// Problem Link - https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&company[]=Amazon&category[]=Linked%20List&sortBy=submissions

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       Node* op = head;
       while(op and n--)
        op = op->next;
       if(n>0)
        return -1;
       Node* ans = head;
       while(op)
        ans = ans->next, op = op->next;
      return ans->data;
}