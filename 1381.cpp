class CustomStack {
public:
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        curSize = 0;
        this->maxSize = maxSize;
    }
    ~CustomStack(){
        delete[] arr;
    }
    
    void push(int x) {
        if(curSize >= maxSize) return;
        arr[curSize] = x;
        ++curSize;
        return;
    }
    
    int pop() {
        if(curSize <= 0) return -1;
        --curSize;
        return arr[curSize];
    }
    
    void increment(int k, int val) {
        for(int i = 0;i < min(k, curSize);++i){
            arr[i] += val;
        }
        return;
    }
private:
    int maxSize;
    int *arr;
    int curSize;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
