/*
Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false

Notes:

    You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
According to Leetcode:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
Memory Usage: 8.8 MB, less than 50.23% of C++ online submissions for Implement Stack using Queues.
*/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
      
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        topValue=x;
            mockStack.push(x);
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
       
        if(mockStack.empty()){ return -1;}
         queue<int> newQueue;
        int removedValue;
        while(mockStack.size()!=1)
        {
            topValue=mockStack.front();
            newQueue.push(topValue);
            mockStack.pop();
        }
        removedValue=mockStack.front();
        mockStack=newQueue;
        return removedValue;
        
    }
    
    /** Get the top element. */
    int top() {
        return topValue;
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mockStack.empty();
        
    }
      queue<int> mockStack;
    int topValue;
        
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
