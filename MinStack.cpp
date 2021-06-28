#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> x_stack;
    stack<int> min_stack;
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(__INT32_MAX__);
    }
    
    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(val, min_stack.top()));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        x_stack.top();
        min_stack.top();
    }
    
    int getMin() {
        min_stack.top();
    }
};