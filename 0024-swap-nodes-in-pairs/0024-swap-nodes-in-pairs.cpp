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
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* third=head->next->next;
        ListNode* prev=NULL;
        while(first && second){
            second->next=first;
            if(prev)
                prev->next=second;
            else
                head=second;
            first->next=third;

            prev=first;
            first=third;
            if(third && third->next){
                second=third->next;
                third=second->next;
            }
            else{
                second=NULL;
                third=NULL;
            }
        }
        return head;
    }
};