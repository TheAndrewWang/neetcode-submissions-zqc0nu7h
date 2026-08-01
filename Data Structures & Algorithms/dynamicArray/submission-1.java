class DynamicArray {
    private int capacity;
    private int size;
    private int[] arr;

    public DynamicArray(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.arr = new int[capacity];
    }

    public int get(int i) {
        return arr[i];
    }

    public void set(int i, int n) {
        arr[i] = n;
    }

    public void pushback(int n) {
        if (size == capacity) {
            resize();
            int[] newArray = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArray[i] = arr[i];
            }
            arr = newArray;
        }

        arr[size] = n;
        size++;
    }

    public int popback() {
        size--;
        return arr[size];
    }

    private void resize() {
        this.capacity *= 2;
    }

    public int getSize() {
        return size;
    }

    public int getCapacity() {
        return capacity;
    }
}
