//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
Node* Intersect(Node* head)
     {
         Node* slow=head;
         Node* fast=head;
         
         while(fast!=NULL)
         {
             fast=fast->next;
             if(fast!=NULL)
               fast=fast->next;
             slow=slow->next;
             if(slow==fast)
               return slow;
         }
         return NULL;
     }
     
    Node* getStartNode(Node* head)
    {
        
        Node* intersect=Intersect(head);
        
        if(intersect==NULL) return NULL;
        
        Node* slow=head;
        
        while(slow!=intersect)
        {
            slow=slow->next;
            intersect=intersect->next;
        }
        return slow;
    }
int countNodesinLoop(struct Node *head)
{
    Node* start=getStartNode(head);
    int cnt=0;
    if(start==NULL)
     return cnt;
    Node* ptr=start->next;
    
    while(ptr!=start)
    {
         cnt++;
        ptr=ptr->next;
    }
    
    return cnt+1;
    
}