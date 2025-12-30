/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;

        unordered_map<Node*,Node*> m;
        Node* newHead=new Node(head->val);
        m[head]=newHead;
        Node* oldTemp=head->next;
        Node* newTemp=newHead;

        while(oldTemp){
            Node* copyNode=new Node(oldTemp->val);
            newTemp->next=copyNode;
            m[oldTemp]=copyNode;

            newTemp=newTemp->next;
            oldTemp=oldTemp->next;
        }
        oldTemp=head;
        newTemp=newHead;
        while(oldTemp){
            newTemp->random=m[oldTemp->random];

            newTemp=newTemp->next;
            oldTemp=oldTemp->next;
        }
        return newHead;
    }
};