class Node {
public:
    Node(int value) : next{nullptr}, val{value} {}
    Node* next;
    int val;
};

class LinkedList {
public:
    LinkedList() : head{nullptr}, size{0} {}

    int get(int index) {
        if (index >= size || size == 0) {
            return -1;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            newNode->next = head;
        }
        head = newNode;
        size++;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }
        if (size == 1) {
            delete head;
            size = 0;
            head = nullptr;
            return true;
        }
        size--;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* current = head;
        for (int i = 0; i < index-1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node* current = head;
        for (int i = 0; i < size; i++) {
            values.push_back(current->val);
            current = current->next;
        }
        return values;
    }

private:
    int size;
    Node* head;
};
