class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node) {
        Node* oldHead = head->next;
        head->next = node;
        node->prev = head;

        node->next = oldHead;
        oldHead->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->head = new Node(0, 0);
        this->tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        cache.clear();
    }
    
    int get(int key) {
        if (!cache.contains(key)) return -1;
        Node* node = cache[key];

        remove(node);
        insert(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            remove(cache[key]);
        }
        
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if (cache.size() > cap) {
            Node* lastNode = tail->prev;
            remove(lastNode);
            cache.erase(lastNode->key);
            delete lastNode;
        }

    }
};
