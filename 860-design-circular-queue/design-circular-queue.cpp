class MyCircularQueue {
public:
    vector<int> q;
    int front, rear, count, size;
    MyCircularQueue(int k) {
        size = k;
        q.resize(k);
        front = rear = count =0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[rear] = value;
        rear = (rear+1)%size;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1)%size;
        count--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[(rear-1+size) %size];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};