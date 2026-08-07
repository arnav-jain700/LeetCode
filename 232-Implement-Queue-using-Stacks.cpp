class MyQueue {

private: 
    stack<int> input_stack;
    stack<int> output_stack;

    void transferIfEmpty() {
        if(output_stack.empty()){
            while(!input_stack.empty()){
                output_stack.push(input_stack.top());
                input_stack.pop();
            }
        }
    }

public:
    MyQueue() {

    }
    
    void push(int x) {
        input_stack.push(x);
    }
    
    int pop() {
        transferIfEmpty();
        int topElement = output_stack.top();
        output_stack.pop();
        return topElement;
    }
    
    int peek() {
        transferIfEmpty();
        return output_stack.top();
    }
    
    bool empty() {
        return input_stack.empty() && output_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */