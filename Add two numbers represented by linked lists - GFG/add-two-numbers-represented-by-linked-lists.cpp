//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
      struct Node* reverse(struct Node *head)
    {
        if(head==NULL || head->next==NULL)
          return head;
          
               Node* prev=NULL;
        Node* curr=head;
        Node* temp=curr->next;
        while(curr!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=temp;
            if(temp!=NULL)
                 temp=temp->next;
        }
        return prev;
    }
    
    void inserAtTail(Node* &head,Node* &tail,int data)
    {
        
        Node* temp=new Node(data);
        if(head==NULL)
        {
            
            head=temp;
            tail=head;
            return;
        }
        else
        {
            tail->next=temp;
            tail=temp;
            return;
        }
    }
    struct Node* add(Node* first,Node* second)
    {
        Node* head=NULL;
        Node* tail=NULL;
        int carry=0;
        
        while(first && second)
        {
            int sum=first->data+second->data+carry;
            int digit=sum%10;
            inserAtTail(head,tail,digit);
            carry=sum/10;
            first=first->next;
            second=second->next;
        }
        while(first)
        {
            int sum=first->data+carry;
            int digit=sum%10;
            inserAtTail(head,tail,digit);
            carry=sum/10;
            first=first->next;
        }
         while(second)
        {
            int sum=second->data+carry;
            int digit=sum%10;
            inserAtTail(head,tail,digit);
            carry=sum/10;
            second=second->next;
            
        }
         while(carry)
        {
            int sum=carry;
            int digit=sum%10;
            inserAtTail(head,tail,digit);
            carry=sum/10;
        }
        return head;
    
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        Node* ans=add(first,second);
        ans=reverse(ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends