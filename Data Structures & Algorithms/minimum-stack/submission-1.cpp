class Node {
public:
    Node(int value) : next{nullptr}, prev{nullptr}, val{value} {} 
    Node* next;
    Node* prev;
    int val;
};

class MinStack {
public:
    MinStack() : minimumNode{nullptr}, topNode{nullptr} {}
    
    void push(int val) {
        if (topNode == nullptr) {
            topNode = new Node(val);
            minimumNode = new Node(val);
            return;
        }

        // Add to stack
        Node* newNode = new Node(val);
        topNode->next = newNode;
        newNode->prev = topNode;
        topNode = newNode;

        // Add to min stack if new min
        if (val <= minimumNode->val) {
            Node* newMin = new Node(val);
            minimumNode->next = newMin;
            newMin->prev = minimumNode;
            minimumNode = newMin;
        }
    }
    
    void pop() {
        if (minimumNode->val == topNode->val) {
            Node* temp = minimumNode;
            minimumNode = minimumNode->prev;
            delete temp;
        }

        Node* temp = topNode;
        topNode = topNode->prev;
        delete temp;
    }
    
    int top() {
        return topNode->val;
    }
    
    int getMin() {
        return minimumNode->val;
    }
private:
    Node* minimumNode;
    Node* topNode;
};
