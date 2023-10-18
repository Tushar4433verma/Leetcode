//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    void insertTail(Node*&tail,Node* val)
    {
        tail->next=val;
        tail=tail->next;
        
    }
    Node* segregate(Node *head) {
        
      
       Node* zerohead=new Node(-1);
       Node* onehead=new Node(-1);
       Node* twohead=new Node(-1);
       Node* zerotail=zerohead;
       Node* onetail=onehead;
       Node* twotail=twohead;
       Node* ptr=head;
       
       while(ptr!=NULL)
       {
           if(ptr->data==0)
               insertTail(zerotail,ptr);
            if(ptr->data==1)
               insertTail(onetail,ptr);
            if(ptr->data==2)
               insertTail(twotail,ptr);
            
            ptr=ptr->next;
       }
       
       //merging them
       
       if(onehead->next!=NULL)
          zerotail->next=onehead->next;
        else
          zerotail->next=twohead->next;
        
        onetail->next=twohead->next;
        twotail->next=NULL;
        head=zerohead->next;
        
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends