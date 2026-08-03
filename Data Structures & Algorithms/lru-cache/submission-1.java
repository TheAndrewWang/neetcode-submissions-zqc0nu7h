class Node {
    public int key;
    public int val;
    public Node next;
    public Node prev;

    Node(int key, int val) {
        this.key = key;
        this.val = val;
        next = null;
        prev = null;
    }
}

class LRUCache {
    private int cap;
    private HashMap<Integer, Node> cache;
    private Node head;
    private Node tail;

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

    public LRUCache(int capacity) {
        this.cap = capacity;
        cache = new HashMap<>();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) return -1;

        remove(node);
        insert(node);

        return node.val;
    }
    
    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            remove(cache.get(key));
        }

        Node node = new Node(key, value);
        cache.put(key, node);
        insert(node);

        if (cache.size() > cap) {
            Node lru = tail.prev;
            remove(lru);
            cache.remove(lru.key);
        }
    }
}
