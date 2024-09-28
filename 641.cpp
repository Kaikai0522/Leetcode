class MyCircularDeque {
public:
    MyCircularDeque(int k) : circular_queue(k + 1, 0){
        front = 0;
        end = 1;
        size = k + 1;
    }
    
    bool insertFront(int value) {
        if(this->isFull()) return false;
        circular_queue[front] = value;
        front = (front - 1 + size) % size;
        return true;
    }
    
    bool insertLast(int value) {
        if(this->isFull()) return false;
        circular_queue[end] = value;
        end = (end + 1) % size;
        return true;
    }
    
    bool deleteFront() {
        if(this->isEmpty()) return false;
        front = (front + 1) % size;
        return true;
    }
    
    bool deleteLast() {
        if(this->isEmpty()) return false;
        end = (end - 1 + size) % size;
        return true;
    }
    
    int getFront() {
        if(this->isEmpty()) return -1;
        return circular_queue[(front + 1) % size];
    }
    
    int getRear() {
        if(this->isEmpty()) return -1;
        return circular_queue[(end - 1 + size) % size];
    }
    
    inline bool isEmpty() {
        return (front + 1) % size == end;
    }
    
    inline bool isFull() {
        return front == end;
    }
    vector<int> circular_queue;
    int front, end, size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
