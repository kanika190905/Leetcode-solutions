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
        int cnt=0;
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            prev=temp;
            temp=temp->next;
            cnt++;
            
        }
        
    
        int tail=cnt-(k%cnt);
        k %= cnt;

if(k == 0) return head;
        temp=head;
        cnt=1;
        while(cnt<tail){
            temp=temp->next;
            cnt++;
        }
        ListNode* nextNode=temp->next;
        temp->next=NULL;
        prev->next=head;
        return nextNode;

       

    }
};