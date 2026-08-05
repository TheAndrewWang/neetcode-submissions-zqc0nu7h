class Node {
    int key;
    int val;
    Node next;
    Node prev;

    Node(int key, int val) {
        this.key = key;
        this.val = val;
        next = null;
        prev = null;
    }
}
class LRUCache {
    int cap;
    Node head;
    Node tail;
    HashMap<Integer, Node> cache;
    int size;

    public LRUCache(int capacity) {
        this.cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        cache = new HashMap<>();
        head.next = tail;
        tail.prev = head;
        size = 0;
    }

    private void remove(Node node) {
        Node previousNode = node.prev;
        Node nextNode = node.next;
        previousNode.next = nextNode;
        nextNode.prev = previousNode;
    }

    private void insert(Node node) {
        Node oldHead = head.next;
        head.next = node;
        node.prev = head;

        node.next = oldHead;
        oldHead.prev = node;
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) return -1;
        remove(cache.get(key));
        insert(cache.get(key));       

        return cache.get(key).val;
    }
    
    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            remove(cache.get(key));
            cache.remove(key);    
            size--;
        }        

        Node newNode = new Node(key, value);
        cache.put(key, newNode);
        insert(newNode);
        size++;

        if (size > cap) {
            cache.remove(tail.prev.key);
            remove(tail.prev);
            size--;
        }
    }
}
