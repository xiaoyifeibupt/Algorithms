/**
*As the title described, you should only use two stacks to implement a queue's actions.
*Example*
*For *push(1), pop(), push(2), push(3), top(), pop()*, you should return *1*, *2* and *2*

*Challenge*
*implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by *AVERAGE*.*
*/

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int x = top();
        stack2.pop();
        return x;
    }

    int top() {
        // write your code here
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int x = stack1.top();
                stack1.pop();
                stack2.push(x);
            }
        }
        return stack2.top();
    }
};

