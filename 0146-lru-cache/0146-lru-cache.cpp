class LRUCache {
public:

    class Node{
        public:
        Node* prev;
        Node* next;
        int key,val;
        Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    void addNode(Node* newNode){
        Node* oldNext=head->next;
        head->next=newNode;
        newNode->prev=head;

        newNode->next=oldNext;
        oldNext->prev=newNode;
    }
    void deleteNode(Node* delNode){
        Node* oldPrev=delNode->prev;
        Node* oldNext=delNode->next;

        oldPrev->next=oldNext;
        oldNext->prev=oldPrev;
    }
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* delNode=m[key];

        m.erase(key);
        deleteNode(delNode);
        
        addNode(delNode);
        m[key]=delNode;
        return m[key]->val;
    }

    unordered_map<int,Node*> m;
    int limit;

    void put(int key, int value) {

        if(m.find(key)!=m.end()){
            Node* oldNode=m[key];
            m.erase(key);
            deleteNode(oldNode);
        }
        if(limit==m.size()){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode= new Node(key,value);
        addNode(newNode);
        m[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */