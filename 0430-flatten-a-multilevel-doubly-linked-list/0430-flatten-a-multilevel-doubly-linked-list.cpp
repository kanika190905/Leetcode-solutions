/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return head;
        Node* curr=head;
        while(curr){
            if(curr->child){
                //flatten
                Node* next=curr->next;
                curr->next=flatten(curr->child);
                curr->next->prev=curr;
                curr->child=NULL;
                //find tail 
                while(curr->next){
                    curr=curr->next;
                }
                //attach tail with nextPtr
                if(next){
                    curr->next=next;
                    next->prev=curr;
                }
            }
            curr=curr->next;
        }
        return head;
    }
};