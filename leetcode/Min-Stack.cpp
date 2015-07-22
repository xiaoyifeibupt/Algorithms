/**
*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

  push(x) -- Push element x onto stack.
  pop() -- Removes the element on top of the stack.
  top() -- Get the top element.
  getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        data.push(x);
        if(min.size() == 0 || x < min.top())
            min.push(x);
        else
            min.push(min.top());
    }

    void pop() {
        if(data.size() > 0 && min.size() > 0){
            min.pop();
            data.pop();
        }
        else
            return;
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
    
private:
    stack<int> data;
    stack<int> min;
};
