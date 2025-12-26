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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL ) return head;
        if(head->next==NULL && n==1)  return NULL;
        ListNode* temp=head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        int k=count-n;
        int count2=0;
        ListNode* temp2=head;
        if(k==0){
            head=head->next;
            return head;
        }
        while(count2<k-1){
            count2++;
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        return head;
    }
};