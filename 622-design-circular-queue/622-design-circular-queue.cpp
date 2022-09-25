class MyCircularQueue {
    int front,rear,size;
    int *q;
public:
    MyCircularQueue(int k) {
        q = new int[k+1];
        front = 0;
        rear = 0;
        size = k+1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        rear = (rear+1)%size;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        front = (front+1)%size;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[(front+1)%size];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        if (front == rear) return true;
        return false;
    }
    
    bool isFull() {
        if (front == (rear+1)%size) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */