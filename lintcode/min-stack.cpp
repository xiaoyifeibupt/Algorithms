/**
*Implement a stack with min() function, which will return the smallest number in the stack.
*Example*
*Operations: *push(1), pop(), push(2), push(3), min(), push(1), min()* Return: *1, 2, 1*

*Note*
*min operation will never be called if there is no number in the stack*
*/

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        if (elements_.empty()) {
            elements_.emplace(0);
            stack_min_ = number;
        } else {
            elements_.emplace(number - stack_min_);
            if (number < stack_min_) {
                stack_min_ = number; // Update min.
            }
        }
    }

    int pop() {
        int diff = elements_.top();
        elements_.pop();
        if (diff < 0) {
            stack_min_ -= diff; // Restore previous min.
        }
        return stack_min_ + diff;
    }

    int min() {
        return stack_min_;
    }
private:
    stack<int> elements_;
    int stack_min_;
};

