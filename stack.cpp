# include <vector>

using std :: vector;

class Stack {
public:
    // define a vector of integers named stack which will hold the elements of the stack
    vector<int> stack_;

    Stack(){};

    void insert(int n) {
        // push the element to the end of stack
        stack_.push_back(n);
    }

    int pop() {
        // first we will get the last element of the stack
        int result = stack_[stack_.size() - 1];
        // now we will remove the last element
        stack_.pop_back();
        // return the last elemnent
        return result;
    }
};