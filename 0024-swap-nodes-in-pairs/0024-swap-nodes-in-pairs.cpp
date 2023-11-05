/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
         return head;
       
        ListNode* curr=head;
        ListNode* forward=curr->next;
       
       while(forward!=NULL && curr!=NULL)
       {
           int temp=curr->val;
           curr->val=forward->val;
           forward->val=temp;
           curr=forward->next;
           if(curr!=NULL && forward!=NULL)
            forward=curr->next;
       }
       return head;
    }
};