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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        if(k==0) return head;
        ListNode* tail=head;
        int n=0;
        while(tail->next){
            tail=tail->next;
            n++;
        }
        n++;
        ListNode* temp=head;
        ListNode* prev=NULL;
        int count=1;

        if(k>n){
            while(k>n){
            k=k-n;
            }
        }
        if(k==n) return head;
        while(count!=n-k+1){
            prev=temp;
            temp=temp->next;
            count++;
        }
        prev->next=NULL;
        tail->next=head;
        return temp;
    }
};