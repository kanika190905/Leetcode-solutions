class Solution {
public:
    ListNode* reverseLL(ListNode* orHead,ListNode* head,ListNode* left,ListNode* right){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=right){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        if( left!=NULL)
        left->next=prev;
        head->next=right;
        if(left==NULL){
            return prev;
        }
        return orHead;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp=head;
        ListNode *leftt = NULL, *rightt = NULL;

        ListNode *nnode = NULL, *prev = NULL;
        int cnt=1;
        while(temp!=NULL){
            if(cnt==left){
                nnode=temp;
            }
            if(cnt==right){
                rightt=temp->next;
            }
            if(cnt==left){
                leftt=prev;
            }
            cnt++;
            
            prev=temp;
            temp=temp->next;
        }
        
        return  reverseLL(head,nnode,leftt,rightt);;
    }
};

 

