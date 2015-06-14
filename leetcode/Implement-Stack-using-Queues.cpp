/*
*Implement the following operations of a stack using queues.

  *push(x) -- Push element x onto stack.
  *pop() -- Removes the element on top of the stack.
  *top() -- Get the top element.
  *empty() -- Return whether the stack is empty.
*Notes:
*You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
*Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
*You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(!que1.empty())
            que1.push(x);
        else
            que2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!que1.empty()) {
            while(que1.size() > 1) {
                que2.push(que1.front());
                que1.pop();
            }
            que1.pop();
        }
        else {
            while(que2.size() > 1) {
                que1.push(que2.front());
                que2.pop();
            }
            que2.pop();
        }
    }

    // Get the top element.
    int top() {
        int top_;
        if(!que1.empty()) {
            while(que1.size() > 0) {
                top_ = que1.front();
                que2.push(top_);
                que1.pop();
            }
        }
        else {
            while(que2.size() > 0) {
                top_ = que2.front();
                que1.push(top_);
                que2.pop();
            }
        }
        return top_;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que1.empty() && que2.empty();
    }
    
private:
    queue<int> que1;
    queue<int> que2;
};
