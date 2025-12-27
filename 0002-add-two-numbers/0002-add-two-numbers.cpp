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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL) return NULL;
        ListNode* l3=new ListNode(0,0);
        ListNode* temp=l3;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int y=0;
        while(temp1 && temp2){
            if((temp1->val+temp2->val)<=9 && y==0){
                temp->next=new ListNode(temp1->val+temp2->val,NULL);
            }
            else if((temp1->val+temp2->val)>9 && y==0){
                int x=(temp1->val+temp2->val)%10;
                y=(temp1->val+temp2->val)/10;
                temp->next=new ListNode(x,NULL);
            }
            else if( y!=0){
                int z=temp1->val+temp2->val+y;
                y=z/10;
                temp->next=new ListNode(z%10,NULL);
            }
            temp1=temp1->next;
            temp2=temp2->next;
            temp=temp->next;
        }
        while(temp1){
             if( y==0){
                temp->next=new ListNode(temp1->val,NULL);
            }
            else if((temp1->val+y)<=9){
                temp->next=new ListNode(temp1->val+y,NULL);
                y=0;
            }
            else{
                int z=temp1->val+y;
                y=z/10;
                temp->next=new ListNode(z%10,NULL);
            }
            temp1=temp1->next;
            temp=temp->next;
        }
         while(temp2){
             if( y==0){
                temp->next=new ListNode(temp2->val,NULL);
            }
            else if((temp2->val+y)<=9){
                temp->next=new ListNode(temp2->val+y,NULL);
                y=0;
            }
            else{
                int z=temp2->val+y;
                y=z/10;
                temp->next=new ListNode(z%10,NULL);
            }
            temp2=temp2->next;
            temp=temp->next;
        }
         while(y){
            int z=y%10;
            temp->next=new ListNode(z,NULL);
            y=y/10;
            temp=temp->next;
         }
        return l3->next;
    }
};