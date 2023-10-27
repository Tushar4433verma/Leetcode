//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

class Solution{
  public:
  Node* getMid(Node* head)
  {
      Node* slow=head;
      Node* fast=head->next;
      
      while(fast!=NULL)
      {
          fast=fast->next;
          if(fast!=NULL)
            fast=fast->next;
          slow=slow->next;
      }
      return slow;
  }
   
   Node* reverse(Node* head)
   {
       Node* prev=NULL;
       Node* curr=head;
       while(curr!=NULL)
       {
           Node* ff=curr->next;
           curr->next=prev;
           prev=curr;
           curr=ff;
       }
       return prev;
   }
    bool isPalindrome(Node *head)
    {
        if(head==NULL || head->next==NULL)
          return true;
        
        Node* mid=getMid(head);
        Node* h2=reverse(mid);
        
        Node* h1=head;
        
        while(h1!=NULL && h2!=NULL)
        {
            if(h1->data!=h2->data) 
              return false;
            h1=h1->next;
            h2=h2->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends