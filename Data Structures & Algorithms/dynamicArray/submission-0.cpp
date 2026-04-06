class DynamicArray {
public:

    DynamicArray(int c) : capacity{c}, size{0}, storage{new int[c]} {}

    int get(int i) {
        return storage[i];
    }

    void set(int i, int n) {
        storage[i] = n;
    }

    void pushback(int n) {
        if (size == capacity)  {
            resize();
        }
        storage[size] = n;
        size++;
    }

    int popback() {
        size--;
        return storage[size];
    }

    void resize() {
        capacity *= 2;
        int* newStorage = new int[capacity];
        for (int i = 0; i < size; i++) {
            newStorage[i] = storage[i];
        }
        delete storage;
        storage = newStorage;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

private:
    int capacity;
    int size;
    int* storage;
};
