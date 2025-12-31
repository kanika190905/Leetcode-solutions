class LFUCache {
public:

    class Node {
    public:
        int key, val, freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = next = NULL;
        }
    };

    class List {
    public:
        int size;
        Node* head;
        Node* tail;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* node) {
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++;
        }

        
        void removeNode(Node* node) {
            Node* p = node->prev;
            Node* n = node->next;
            p->next = n;
            n->prev = p;
            size--;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyNode;      
    unordered_map<int, List*> freqListMap;  

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int oldFreq = node->freq;

        freqListMap[oldFreq]->removeNode(node);

        if (oldFreq == minFreq && freqListMap[oldFreq]->size == 0) {
            minFreq++;
        }

        node->freq++;

        if (freqListMap.find(node->freq) == freqListMap.end()) {
            freqListMap[node->freq] = new List();
        }
        freqListMap[node->freq]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if (keyNode.size() == capacity) {
            List* list = freqListMap[minFreq];
            Node* lruNode = list->tail->prev; 
            keyNode.erase(lruNode->key);
            list->removeNode(lruNode);
        }

        Node* newNode = new Node(key, value);
        minFreq = 1;

        if (freqListMap.find(1) == freqListMap.end()) {
            freqListMap[1] = new List();
        }

        freqListMap[1]->addFront(newNode);
        keyNode[key] = newNode;
    }
};
