//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* solve(Node* first,Node*second)
{
    if(first->next==NULL)
    {
        first->next=second;
        return first;
    }
    Node* prev=first;
    Node* forward=prev->next;
    
    Node* t1=second;
    Node* t2=t1;
    
    while(forward!=NULL && t1!=NULL)
    {
        if(prev->data<=t1->data && t1->data<=forward->data)
        {
            prev->next=t2;
            t2=t1->next;
            t1->next=forward;
            prev=t1;
            t1=t2;
        }
        else
        {
            prev=forward;
            forward=forward->next;
            if(forward==NULL)
            {
                prev->next=t1;
                return first;
            }
        }
    }
    return first;
}
Node* sortedMerge(Node* h1, Node* h2)  
{  
    
    if(h1==NULL) return h2;
    if(h2==NULL) return h1;
    
    if(h1->data<=h2->data)
       return solve(h1,h2);
    else
       return solve(h2,h1);
    
}  