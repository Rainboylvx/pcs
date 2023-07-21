class MinStack {
public:
    /** initialize your data structure here. */
    int a[200];
    int b[200];
    int idx;
    MinStack() {
        idx = 0;
    }
    
    void push(int x) {
        a[idx] = x;
        if( idx == 0)
            b[idx] = x;
        else 
            b[idx] = std::min(b[idx-1],x);
        idx++;
    }
    
    void pop() {
        idx--;
    }
    
    int top() {
        return a[idx-1];
    }
    
    int getMin() {
        return b[idx-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
