class MyCircularQueue {
public:
    vector<int> q;
    int f=0,r=0;
    MyCircularQueue(int k) {
        q.resize(k+1);
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        r=(r+1)%q.size();
        q[r]=value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        else{
            f=(f+1)%q.size();
        }
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        else
            return q[(f+1)%q.size()];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        else
            return q[r];
    }
    
    bool isEmpty() {
        return (f==r);
    }
    
    bool isFull() {
        return ((r+1)%q.size()==f);
    }
};